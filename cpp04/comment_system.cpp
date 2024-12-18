//
// Created by DELL on 2024/12/18.
//
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

class Comment {
    public:
    uint customer_id;
    float food_score;
    float service_score;
    float env_score;
    string timestamp;
    uint version; // start from 1
};

unordered_map<uint, uint> last_ver; // id -> version

void printCoreComment(const Comment & comment, bool food, bool service, bool env) {
    if (food) {
        cout << " Food Rating " << comment.food_score;
    }
    if (service) {
        cout << " Service Rating " << comment.service_score;
    }
    if (env) {
        cout << " Environment Rating " << comment.env_score;
    }
    cout << " Timestamp " << comment.timestamp << endl;
}

void printComment(const Comment & comment, bool food, bool service, bool env) {
    if (comment.version != last_ver[comment.customer_id]) return;
    // newest ver
    cout << "Customer ID " << comment.customer_id;
    printCoreComment(comment, food, service, env);
}

int main() {
    vector<Comment> comments;

    int n;
    scanf("%d ", &n);

    string line;
    while (n--) {
        getline(cin, line);

        stringstream ss(line);
        string cmd;
        ss >> cmd;
        switch (cmd[0]) {
            case 'i': { // insert
                cout << "Review inserted successfully" << endl;
                Comment new_comment;
                ss >> new_comment.customer_id >> new_comment.food_score >> new_comment.service_score >> new_comment.env_score;
                string daystamp, minstamp;
                ss >> daystamp >> minstamp;
                new_comment.timestamp = daystamp;
                new_comment.timestamp.append(" ").append(minstamp);
                new_comment.version = 1;
                comments.push_back(new_comment);
                last_ver[new_comment.customer_id] = 1;
                break;
            }
            case 'm': { // modify
                uint id;
                ss >> id;
                Comment new_comment;
                new_comment.customer_id = id;

                bool found = false;
                for (auto comment : comments) {
                    if (comment.customer_id == id && last_ver[comment.customer_id] == comment.version) {
                        found = true;
                        cout << "Modification successful" << endl;

                        new_comment.food_score = comment.food_score;
                        new_comment.service_score = comment.service_score;
                        new_comment.env_score = comment.env_score;

                        string dim;
                        ss >> dim;
                        float *prt;
                        switch (dim[0]) {
                            case 'f': {
                                prt = &(new_comment.food_score);
                                break;
                            }
                            case 's': {
                                prt = &(new_comment.service_score);
                                break;
                            }
                            case 'e': {
                                prt = &(new_comment.env_score);
                                break;
                            }
                        }
                        ss >> *prt;
                        string daystamp, minstamp;
                        ss >> daystamp >> minstamp;
                        new_comment.timestamp = daystamp;
                        new_comment.timestamp.append(" ").append(minstamp);
                        new_comment.version = comment.version + 1;
                        last_ver[new_comment.customer_id] = new_comment.version;
                        comments.push_back(new_comment);
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer ID not found, modification failed" << endl;
                }
                break;
            }
            case 'd': {
                if (cmd[1] == 'e') { // delete
                    uint id;
                    ss >> id;

                    auto new_end = remove_if(comments.begin(), comments.end(), [id](Comment &c) {
                        return c.customer_id == id;
                    });

                    if (new_end != comments.end()) {
                        comments.erase(new_end, comments.end());
                        cout << "Deletion successful" << endl;
                    } else {
                        cout << "Customer ID not found, deletion failed" << endl;
                    }
                } else if (cmd[1] == 'i') { // display
                    string dim;
                    ss >> dim;
                    sort(comments.begin(), comments.end(), [](Comment &c1, Comment &c2) {
                        return c1.timestamp > c2.timestamp; // decent
                    });
                    bool food = true, service = true, env = true;
                    if (!dim.empty()) { // display all
                        switch (dim[0]) {
                            case 'f': {
                                service = false; env= false;
                                break;
                            }
                            case 's': {
                                food = false; env= false;
                                break;
                            }
                            case 'e': {
                                food = false; service = false;
                                break;
                            }
                        }
                    }
                    for_each(comments.begin(), comments.end(), [food, service, env](Comment &c) {
                            printComment(c, food, service, env);
                        });
                }
                break;
            }
            case 'h': { // history
                uint id;
                ss >> id;
                string dim;
                ss >> dim;

                cout << "History:" << endl;
                vector<Comment> his_comments;
                for (auto comment : comments) {
                    if (comment.customer_id == id) {
                        his_comments.push_back(comment);
                    }
                }
                sort(his_comments.begin(), his_comments.end(), [](Comment &c1, Comment &c2) {
                    return c1.version > c2.version;
                });

                bool food = true, service = true, env = true;
                if (!dim.empty()) { // display all
                    switch (dim[0]) {
                        case 'f': {
                            service = false; env= false;
                            break;
                        }
                        case 's': {
                            food = false; env= false;
                            break;
                        }
                        case 'e': {
                            food = false; service = false;
                            break;
                        }
                    }
                }
                for_each(his_comments.begin(), his_comments.end(), [food, service, env](Comment &c) {
                    cout << "Version " << c.version << ":";
                    printCoreComment(c, food, service, env);
                });

                break;
            }
            case 'r': { // range_query
                float food_low, food_high, service_low, service_high, env_low, env_high;
                ss >> food_low >> food_high >> service_low >> service_high >> env_low >> env_high;

                vector<Comment> able_comments;
                for_each(comments.begin(), comments.end(), [&](Comment &c) {
                    if (c.version == last_ver[c.customer_id]) {
                        // possible
                        if (c.food_score >= food_low && c.food_score <=  food_high &&
                            c.service_score >= service_low && c.service_score <=  service_high &&
                            c.env_score >=  env_low && c.env_score <=  env_high) {
                            able_comments.push_back(c);
                        }
                    }
                });

                sort(able_comments.begin(), able_comments.end(), [](Comment &c1, Comment &c2) {
                    return c1.customer_id > c2.customer_id;
                });
                for (auto comment : able_comments) {
                    printComment(comment, true, true, true);
                }
                break;
            }
        }
    }
    return 0;
}
