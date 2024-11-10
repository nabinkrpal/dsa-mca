#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct StackNode {
    Node* info;
    StackNode* next;
};


StackNode* push(StackNode* head, Node* info) {
    StackNode* ptr = (StackNode*)malloc(sizeof(StackNode));
    ptr->info = info;
    ptr->next = head;
    head = ptr;
    return head;
}

StackNode* pop(StackNode* head, Node*& info) {
    if (head == NULL) {
        cout << "Stack Underflow!" << endl;
        info = NULL;
        return head;
    }
    StackNode* temp = head;
    info = head->info;
    head = head->next;
    free(temp);
    return head;
}

bool isEmpty(StackNode* head) {
    return head == NULL;
}

Node* peek(StackNode* head) {
    return (head != NULL) ? head->info : NULL;
}


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

void inorderTraversal(Node* root) {
    StackNode* stack = NULL;
    Node* current = root;

    cout << "Inorder Traversal: ";
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            stack = push(stack, current);
            current = current->left;
        }
        stack = pop(stack, current);
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}


void preorderTraversal(Node* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    stack = push(stack, root);

    cout << "Preorder Traversal: ";
    while (!isEmpty(stack)) {
        Node* current;
        stack = pop(stack, current);
        cout << current->data << " ";

        if (current->right != NULL) {
            stack = push(stack, current->right);
        }
        if (current->left != NULL) {
            stack = push(stack, current->left);
        }
    }
    cout << endl;
}


void postorderTraversal(Node* root) {
    if (root == NULL) return;
    StackNode* stack1 = NULL;
    StackNode* stack2 = NULL;
    stack1 = push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* current;
        stack1 = pop(stack1, current);
        stack2 = push(stack2, current);

        if (current->left != NULL) {
            stack1 = push(stack1, current->left);
        }
        if (current->right != NULL) {
            stack1 = push(stack1, current->right);
        }
    }

    cout << "Postorder Traversal: ";
    while (!isEmpty(stack2)) {
        Node* current;
        stack2 = pop(stack2, current);
        cout << current->data << " ";
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    int ch;
    do {
        cout << ".......Menu......\n";
        cout << "1. Insert a Node in BST\n";
        cout << "2. Traversal in Inorder pf BST\n";
        cout << "3. Traversal in Preorder of BST\n";
        cout << "4. Traversal in Postorder of BST\n";
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
                break;
            }
            case 3: {
                preorderTraversal(root);
                break;
            }
            case 4: {
                postorderTraversal(root);
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

    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);

    return 0;
}
