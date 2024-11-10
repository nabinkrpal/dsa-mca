#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; 
    return newNode;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* insert(Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; 

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp; 

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        inorderTraversal(root->left);
        inorderTraversal(root->right);
    }
}
int main() {
    Node* root = NULL;
    int ch;
    do {
        cout << ".......Menu......\n";
        cout << "1. Insert a Node in AVL\n";
        cout << "2. Traversal in Inorder pf AVL\n";
        cout << "3. Traversal in Preorder of AVL\n";
        cout << "4. Delete A Node of AVL\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                int val;
                cout<<"Enter Next Value: ";
                cin>>val;
                root=insert(root,val); 
                break;
            case 2: {
                inorderTraversal(root);
                cout<<endl;
                break;
            }
            case 3: {
                preorderTraversal(root);
                cout<<endl;
                break;
            }
            case 4: {
                int val;
                cout<<"Enter Node value to Delete: ";
                cin>>val;
                root=deleteNode(root,val);
                break;
            }
            default:
                break;
        }
    } while (ch<5 && ch>0);

    // root = insert(root, 64);
    // root = insert(root, 1);
    // root = insert(root, 18);
    // root = insert(root, 34);
    // root = insert(root, 5);
    // root = insert(root, 6);
    // root = insert(root, 78);
    // root = insert(root, 49);

    // cout << "Inorder traversal of the AVL tree is: ";
    // inorderTraversal(root);
    // cout<<endl;
    // cout << "Preorder traversal of the AVL tree is: ";
    // preorderTraversal(root);
    // cout << endl;

    // root = deleteNode(root, 5);
    // cout << "Inorder traversal after deletion of 5: ";
    // inorderTraversal(root);
    // cout << endl;
    // preorderTraversal(root);
    // cout << endl;

    // root = deleteNode(root, 78);
    // cout << "Inorder traversal after deletion of 78: ";
    // inorderTraversal(root);
    // cout << endl;
    // preorderTraversal(root);
    // cout << endl;
    return 0;
}
