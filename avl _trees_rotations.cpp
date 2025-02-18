#include <iostream>
using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1; // New node is initially at height 1
    }
};

// Class for AVL Tree
class AVLTree {
public:
    // Function to get the height of the tree
    int height(Node* n) {
        return n == nullptr ? 0 : n->height;
    }

    // Get the balance factor of a node
    int getBalance(Node* n) {
        return n == nullptr ? 0 : height(n->left) - height(n->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert a node in the AVL tree
    Node* insert(Node* node, int key) {
        // Perform normal BST insertion
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Equal keys are not allowed in BST
            return node;

        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // If the node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // Return the (unchanged) node pointer
    }

    // Function to print the tree in-order (for testing)
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }
    
    
Node* maximum(Node* root) {
    Node* temp = root;
    while (temp->right) {
        temp = temp->right;
    }
    return temp;
}

Node* deletenode(Node* root, int x) {
    if (root == nullptr) {
        return nullptr;
    }

    // Node to be deleted found
    if (root->key == x) {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child (left child)
        if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: One child (right child)
        if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        if (root->left != nullptr && root->right != nullptr) {
            // Replace with maximum from the left subtree
            Node* maxNode = maximum(root->left);
            root->key = maxNode->key;
            root->left = deletenode(root->left, maxNode->key);
        }
    } else if (x < root->key) {
        // Search in the left subtree
        root->left = deletenode(root->left, x);
    } else {
        // Search in the right subtree
        root->right = deletenode(root->right, x);
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Balance the tree if it becomes unbalanced

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // Return the root pointer
}

};

int main() {
    AVLTree avl;
    Node* root = nullptr;

    // Insert nodes
    root = avl.insert(root, 10);
    root = avl.insert(root, 20);
    root = avl.insert(root, 30);
    root = avl.insert(root, 40);
    root = avl.insert(root, 50);
    root = avl.insert(root, 25);
    avl.inOrder(root);
    cout<<endl;
    root= avl.deletenode(root,40);
    // Print in-order traversal of the AVL tree
    cout << "In-order traversal of the AVL tree is: ";
    avl.inOrder(root);
    cout << endl;

    return 0;
}

