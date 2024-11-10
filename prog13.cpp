#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        cout<<"Empty BST!";
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int ch;
    do {
        cout << ".......Menu......\n";
        cout << "1. Insert a Node in BST\n";
        cout << "2. Delete a Node From BST\n";
        cout << "3. Search an Element from BST\n";
        cout << "4. Traverse BST\n";
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
                cout<<"Enter Node Value: ";
                cin>>val;
                root=deleteNode(root,val);               
                break;
            }
            case 3: {
                cout<<"Enter Value: ";
                cin>>val;
                Node* result = search(root, val);
                if (result != NULL) {
                    cout << "Found" << endl;
                } else {
                    cout << "Not Found" << endl;
                }
                break;
            }
            case 4: {
                int tch;
                cout << "1. Inorder\n";
                cout << "2. Preorder\n";
                cout << "3. Postorder\n";
                cout << "Enter your choice: ";
                cin >> tch;

                if (tch == 1) {
                    inorder(root);
                    cout<<"\n";
                } else if (tch == 2) {
                    preorder(root);
                    cout<<"\n";
                } else if (tch == 3) {
                    postorder(root);
                    cout<<"\n";
                } else {
                    cout << "Invalid choice!" << endl;
                }   
                break;
            }
            default:
                break;
        }
    } while (ch<5 && ch>0);
    // root = insert(root, 45);
    // root = insert(root, 39);
    // root = insert(root, 56);
    // root = insert(root, 12);
    // root = insert(root, 34);
    // root = insert(root, 78);
    // root = insert(root, 32);
    // root = insert(root, 10);
    // root = insert(root, 89);
    // root = insert(root, 54);
    // root = insert(root, 67);
    // root = insert(root, 81);

    // cout << "Inorder traversal: ";
    // inorder(root);
    // cout << endl;

    // cout << "Preorder traversal: ";
    // preorder(root);
    // cout << endl;

    // cout << "Postorder traversal: ";
    // postorder(root);
    // cout << endl;

    // cout << "Search for 12: ";
    // Node* result = search(root, 12);
    // if (result != NULL) {
    //     cout << "Found" << endl;
    // } else {
    //     cout << "Not Found" << endl;
    // }

    // cout << "Delete 45\n";
    // root = deleteNode(root, 45);
    // cout << "Inorder traversal after deletion: ";
    // inorder(root);
    // cout << endl;

    return 0;
}
