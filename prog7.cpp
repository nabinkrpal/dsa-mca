#include<iostream>
using namespace std;
struct node{
    int info;
    struct node* next;
};
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

struct node* merge(struct node* head1, struct node* head2){
    struct node* head = NULL;
    struct node* p = head1;
    struct node* q = head2;
    while(p!=NULL && q!=NULL){
        if(p->info>=q->info){
            head=insertatend(head,q->info);
            q=q->next;
        }
        else if(q->info>=p->info){
            head=insertatend(head,p->info);
            p=p->next;
        }
        // if(q->info==p->info)
        
    }
    while(p!=NULL){
        head=insertatend(head, p->info);
        p=p->next;
    }
    while(q!=NULL){
        head=insertatend(head, q->info);
        q=q->next;
    }
    return head;
}
void displayLL(struct node* ptr){
    if(ptr==NULL){
        cout<<"No data in linked list"<<endl;
    }
    cout<<"Linked List: ";
    while(ptr!=NULL){
        cout<<ptr->info<<" -> ";
        ptr=ptr->next;

    }
    cout<<"NULL";
}
bool checksort(struct node* head){
    struct node* p=head;
    if (p==NULL || p->next==NULL) {
        return true;  
    }
    while(p->next!=NULL){
        if(p->info>p->next->info){
            return false;
            break;
        }
        p=p->next;
    }
    return true;
}

int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
    int n1,n2;
    cout<<"Enter no. of elements of 1st sorted linked list: ";
    cin>>n1;
    for(int i=0;i<n1;i++){
        int info;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>info;
        head1=insertatend(head1,info);
    }
    cout<<"Enter no. of elements of 2nd sorted linked list: ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        int info;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>info;
        head2=insertatend(head2,info);
    }
    cout<<"First linked List: ";
    displayLL(head1);
    cout<<endl;
    cout<<"Second linked List: ";
    displayLL(head2);
    cout<<endl;
    if(checksort(head1) && checksort(head2)){
        struct node* head=merge(head1,head2);
        cout<<"The merged and sorted linked list\n";
        displayLL(head);
    }
    else{
        cout<<"One or both Linked list(s) are Unsorted Can't merge!\n";
    }
    return 0;
}