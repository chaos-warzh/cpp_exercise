#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string foods[6] = {"Chicken", "Lettuce", "Tomato", "Cheese", "Onion", "Sauce"};

int cnt[6] = {0, 0, 0, 0, 0, 0};
int cnt_new[6] = {0, 0, 0, 0, 0, 0};

int getNo(string name) {
    for (int i = 0; i < 6; i++) {
        if (foods[i] == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    string cmd;
    while (n--) {
        cin >> cmd;
        if (cmd[0] == 'S') {
            string ind_name;
            cin >> ind_name;
            int ind_no = getNo(ind_name);
            int quantity;
            cin >> quantity;
            cnt[ind_no] += quantity;
            cout << "Stocked " << ind_name << " with " << quantity << " units" << endl;
        } else if (cmd[0] == 'O') {
            bool done = true;

            vector<int> need_no;
            vector<int> need_quantity;

            string customer_id;
            cin >> customer_id;
            
            string pairs;
            getline(cin, pairs);
            stringstream ss(pairs);
            string ind_name;
            int quantity;

            // store
            for (int i = 0; i < 6; i++) {
                cnt_new[i] = cnt[i];
            }

            while (ss >> ind_name >> quantity) {
                int ind_no = getNo(ind_name);
                if (cnt[ind_no] < quantity) {
                    done = false;
                    need_no.push_back(ind_no);
                    need_quantity.push_back(quantity - cnt[ind_no]);
                    continue;
                } else {
                    cnt_new[ind_no] = cnt[ind_no] - quantity;
                }
            }
            if (done) {
                // restore
                for (int i = 0; i < 6; i++) {
                    cnt[i] = cnt_new[i];
                }
                cout << "Order " << customer_id << " completed" << endl;
            } else {
                cout << "Order " << customer_id << " failed: missing ";
                for (int i = 0; i < need_no.size(); i++) {
                    if (i != 0) {
                        cout << ", ";
                    }
                    cout << foods[need_no[i]] << " " << need_quantity[i] ;
                }
                cout << endl;
            }
            
        } else if (cmd[0] == 'I') {
            cout << "=== Inventory ==="<<endl;
            for (int i = 0; i < 6; i++) {
                cout << foods[i] << ": " << cnt[i] << endl;
            }
            cout << "=================" << endl;
        }
    }

    return 0;
}