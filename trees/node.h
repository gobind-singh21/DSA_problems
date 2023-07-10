struct Node {
    int val;
    Node* right;
    Node* left;
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    Node(int x, Node* leftNode, Node* rightNode) {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};