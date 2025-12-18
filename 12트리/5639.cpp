#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
void init(Node* n, int v) {
    n->val = v;
    n->left = NULL;
    n->right = NULL;
}
Node* insert(Node* root, int val) {
    if (!root) {
        Node* n = new Node();
        init(n, val);
        return n;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\n";
}
int main() {
    Node* root = NULL;
    int val;
    while (cin >> val) {
        root = insert(root, val);
    }

    postorder(root);

    return 0;
}
