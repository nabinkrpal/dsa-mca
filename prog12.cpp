#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int info;
    struct node* next;
};
void peek(struct node* ptr){
    if(ptr==NULL){
        cout<<"Empty!";
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }    
    cout<<"Top of the stack is "<<ptr->info<<endl;
}
void traverselinkedlist(struct node* ptr){
    if(ptr==NULL){
        cout<<"Empty!"<<endl;
    }
    while(ptr!=NULL){
        cout<<ptr->info<<" -> ";
        ptr=ptr->next;

    }
    cout<<"NULL\n";
}

struct node* insertatend(struct node* head,int info){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->info=info;
    if(head==NULL){
        head=ptr;
        ptr->next=NULL;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=ptr;
        ptr->next=NULL;
    }
    return head;
}
struct node* deletefrombeg(struct node* head){
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node* deletefromend(struct node* head){
    struct node* p= head;
    if(head==NULL){
        cout<<"Underflowing!\n";
    }
    else if(p->next==NULL){
        head=NULL;
    }
    else{
        while(p->next->next!=NULL){
            p=p->next;
        }
        struct node* q=p->next;
        p->next=NULL;
        free(q);
    }
    return head;
}

int main(){
    
    struct node* head = NULL; 
    struct node* head1 = NULL; 

    int ch;
    do {
        cout << ".......Menu......\n";
        cout << "1. Push onto Stack\n";
        cout << "2. Pop from Stack\n";
        cout << "3. Peek from Stack\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                int val;
                cout<<"Enter Value to Push: ";
                cin>>val;
                head=insertatend(head,val); 
                break;
            case 2: {
                head=deletefromend(head);               
                break;
            }
            case 3: {
                peek(head);                
                break;
            }
            case 4: {
                traverselinkedlist(head);   
                break;
            }
            default:
                break;
        }
    } while (ch<5 && ch>0); 
   
    
    struct node* trash = head;
    while (trash != NULL) {
        struct node* nextNode = trash->next;
        free(trash);
        trash = nextNode;
    }

    do {
        cout << ".......Menu......\n";
        cout << "1. Enqueue in queue\n";
        cout << "2. Dequeue from queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                int val;
                cout<<"Enter Value to Enqueue: ";
                cin>>val;
                head1=insertatend(head1,val);
                break;
            }
            case 2: {
                head1=deletefrombeg(head1);                              
                break;
            }
            case 3: {
                traverselinkedlist(head1);                
                break;
            }
            default:{
                break;
            }
        }
    } while (ch<4 && ch>0);

    struct node* trash1 = head1;
    while (trash1 != NULL) {
        struct node* nextNode = trash1->next;
        free(trash1);
        trash1 = nextNode;
    }
    return 0;
}