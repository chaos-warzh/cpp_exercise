#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
    int value;
    vector<TreeNode*> children;
    TreeNode(int v) : value(v) {}
};

void dfs(TreeNode* node, int parentValue, const function<bool(TreeNode*, int, bool)>& strategy, int& totalValue, bool isRoot) {
    if (!strategy(node, parentValue, isRoot)) {
        return;
    }
    
    totalValue += node->value;
    
    for (auto child : node->children) {
        dfs(child, node->value, strategy, totalValue, false);
    }
}

int main() {
    int n, p, q, k;
    cin >> n >> p >> q >> k;
    
    vector<TreeNode*> tree(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        tree[i] = new TreeNode(0);
    }
    
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x]->children.push_back(tree[y]);
    }
    
    vector<int> value(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
        tree[i]->value = value[i];
    }
    
    function<bool(TreeNode*, int, bool)> strategy1 = [p](TreeNode* node, int parentValue, bool isRoot) {
        return node->value > p;
    };

    function<bool(TreeNode*, int, bool)> strategy2 = [q, k](TreeNode* node, int parentValue, bool isRoot) {
        return isRoot || node->value > q && node->value + parentValue > k;
    };
    
    function<bool(TreeNode*, int, bool)> strategy3 = [](TreeNode* node, int parentValue, bool isRoot) {
        return isRoot || node->value % 2 == 0;
    };

    int totalValue1 = 0, totalValue2 = 0, totalValue3 = 0;
    
    dfs(tree[1], 0, strategy1, totalValue1, true);
    dfs(tree[1], 0, strategy2, totalValue2, true);
    dfs(tree[1], 0, strategy3, totalValue3, true);
    
    cout << totalValue1 << " " << totalValue2 << " " << totalValue3 << endl;
    
    return 0;
}
