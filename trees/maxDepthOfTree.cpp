#include <iostream>
#include "node.h"

using namespace std;

int depth(Node* root) {
    if(!root)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

int main() {
    return 0;
}