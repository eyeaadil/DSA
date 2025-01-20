#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

TreeNode* findMin(TreeNode* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

void leftViewOfaTree ( TreeNode * root ) {

}

class Node {
    public:
    int data;
    Node *left ;
    Node *right;

    Node(int data ) {
        this->data = data;
        this->left = left;
        this ->right=right;
    }
};
// Node * makeBinaryTree (Node *&root ) {
//     if(root == NULL  ) {
//         return NULL ;
//     }

//     cout << "Enter data "<< endl;
//     int val  ;
//     cin >> val ;
//     Node * temp  = new Node(val);
//     root -> left =  

// }

int main() {
    TreeNode* root = NULL;
    int n, val, key;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the node values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Level order traversal of the BST: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Enter the value of the node to be deleted: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "Level order traversal after deletion: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
