#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main function
int main() {
    // Creating a sample tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int choice;
    do {
        cout << "\n===== Tree Traversal Menu =====" << endl;
        cout << "1. Preorder Traversal" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
