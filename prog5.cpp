#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int info;
    struct node* prev;
    struct node* next;
};
int countnodes(struct node* head){
    int count=0;
    struct node* p=head;
    while(p->next!=NULL){
            p=p->next;
            count++;
    }
    return count;
}
void traverseDLL(struct node* head){
    if(head==NULL){
        cout<<"Double Linked list empty!\n";
    }
    else if(head->next==NULL && head->prev==NULL && head!=NULL){
        cout<<head->info<<"->,<-NULL\n";
    }
    else{
        struct node* p=head;
        while(p!=NULL){
            cout<<p->info<<"->,<-";
            p=p->next;
        }
        cout<<"NULL\n";
    }
}

struct node* insertatend(struct node* head, int info){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->info=info;
    if(head==NULL){
        head=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        ptr->next=NULL;
        p->next=ptr;
        ptr->prev=p;
    }
    return head;
}

struct node* insertatloc(struct node* head, int info,int loc){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int c=countnodes(head),i=0;
    if(loc>0 && loc<c){
        while(i!=(loc-1)){
            p=p->next;
            i++;
        }
        ptr->info=info;
        ptr->next=p->next;
        p->next->prev=ptr;
        p->next=ptr;
        ptr->prev=p;
    }
    else{
        cout<<"Wrong location entered!\n";
    }
    return head;
}
struct node* insertatbeg(struct node* head, int info){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=info;
    ptr->next=head;
    ptr->prev=NULL;
    head->prev=ptr;
    head=ptr;
    return head;
}

struct node* deleteatend(struct node* head){
    struct node* p=head;
    if(head!=NULL){
        while(p->next!=NULL){
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);
    }
    else{
        cout<<"Can't delete\n";
    }
    return head;
}
struct node* deleteatloc(struct node* head,int loc){
    struct node* p=head;
    int c=countnodes(head),i=0;
    if(loc>0 && loc<c){
        while(i!=(loc-1)){
            p=p->next;
            i++;
        }
        struct node* q=p->next;
        p->next=q->next;
        q->next->prev=q->prev;
        free(q);

    }
    else{
        cout<<"Wrong location entered!\n";
    }
    return head;
}
struct node* deleteatbeg(struct node* head){
    if(head==NULL){
        cout<<"Can't delete\n";    
    }
    else if(head->next==NULL && head->prev==NULL){
        head=NULL;
    }
    else{
        struct node* p=head;
        p->next->prev=NULL;
        head=head->next;
        free(p);
    }
    return head;
}

int main(){
    struct node* head=NULL;
    
    int n;
    cout<<"Enter no. of elements you want to enter in circular Linked List: ";
    cin>>n;
    if (n < 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            cout<<"Enter the value of node "<<(i+1)<<": ";
            int value;
            cin>>value;
            head=insertatend(head,value);
        }
    }
    int choice,element,nestedchoice;;
    do{ cout << "\nMenu:\n";
        cout << "1. Traverse Double Linked List\n";
        cout << "2. Insert element in Double Linked List\n";
        cout << "3. Delete element in Double Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                traverseDLL(head); 
                break;
            case 2:
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at location\n";
                cout << "3. Insert at Ending\n";
                cout << "Enter your choice: ";
                cin >> nestedchoice;

                cout << "Enter element to insert: ";
                cin >> element;
                if(nestedchoice==1){
                    head=insertatbeg(head,element);
                    traverseDLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=insertatloc(head,element,loc);
                    traverseDLL(head);
                }
                else if(nestedchoice==3){
                    head=insertatend(head,element);
                    traverseDLL(head);
                }
                else{
                    cout<<"Wrong choice entered! \n";
                }
                break;
            case 3:
                cout << "1. Delete at Beginning\n";
                cout << "2. Delete at location\n";
                cout << "3. Delete at Ending\n";
                cout << "Enter your choice: ";
                cin >> nestedchoice;

                if(nestedchoice==1){
                    head=deleteatbeg(head);
                    traverseDLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=deleteatloc(head,loc);
                    traverseDLL(head);
                }
                else if(nestedchoice==3){
                    head=deleteatend(head);
                    traverseDLL(head);
                }
                else{
                    cout<<"Wrong choice entered! \n";
                }
                break;
                                 
            default:                
                break;
        }

    }
    while(choice!=0 && choice<4);

    struct node* trash = head;
    while (trash != NULL) {
        struct node* nextNode = trash->next;
        free(trash);
        trash = nextNode;
    }
    return 0;
    
    // struct node* second=(struct node*)malloc(sizeof(struct node));
    // struct node* third=(struct node*)malloc(sizeof(struct node));
    // struct node* fourth=(struct node*)malloc(sizeof(struct node));
    // head->info=-1;
    // head->prev=NULL;
    // head->next=NULL;
    // second->info=10;
    // second->prev=head;
    // second->next=third;
    // third->info=15;
    // third->prev=second;
    // third->next=fourth;
    // fourth->info=25;
    // fourth->prev=third;
    // fourth->next=NULL;
    // traverseDLL(head);
    // head=insertatend(head,100);
    // traverseDLL(head);
    // head=insertatend(head,5);
    // traverseDLL(head);
    // head=insertatend(head,10);
    // traverseDLL(head);
    // head=insertatend(head,110);
    // traverseDLL(head);
    // head=insertatend(head,119);
    // traverseDLL(head);
    // head=insertatloc(head,106,2);
    // traverseDLL(head);
    // head=insertatbeg(head,69);
    // traverseDLL(head);
    // traverseDLL(head);
    // head=insertatend(head,100);
    // traverseDLL(head);
    // head=insertatloc(head,106,2);
    // traverseDLL(head);
    // head=insertatbeg(head,69);
    // traverseDLL(head);
    // head=deleteatend(head);
    // traverseDLL(head);
    // head=deleteatloc(head,2);
    // traverseDLL(head);
    // head=deleteatbeg(head);
    // traverseDLL(head);
}