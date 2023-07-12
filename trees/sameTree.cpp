#include <iostream>
#include "node.h"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((!p && q) || (p && !q) || (p->val != q->val))
            return false;
        bool equalLeft = isSameTree(p->left, q->left);
        if(!equalLeft)
            return false;
        return equalLeft && isSameTree(p->right, q->right);
    }
};

int main() {
    return 0;
}