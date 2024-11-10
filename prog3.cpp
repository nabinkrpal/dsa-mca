#include<iostream>
#include<cstdlib>
#include <unistd.h>
using namespace std;
struct node{
    int info;
    struct node* next;
};
int countnodes(struct node* ptr){
    int c=0;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    return c;
}
void traverselinkedlist(struct node* ptr){
    if(ptr==NULL){
        cout<<"No data in linked list"<<endl;
    }
    cout<<"Linked List: ";
    while(ptr!=NULL){
        // cout<<"Element: "<<ptr->info<<" at "<<(&(ptr->info))<<" and point at "<<(ptr->next)<<endl;
        cout<<ptr->info<<" -> ";
        ptr=ptr->next;

    }
    cout<<"NULL";
}
struct node* insertatbeg(struct node* head,int info){
    struct node* ptr= (struct node*) malloc(sizeof(struct node));
    ptr->next=head;
    ptr->info=info;
    return ptr;    
}
struct node* insertatloc(struct node* head,int info,int loc){
    int c=countnodes(head);
    if (loc>0 && loc<c){
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        struct node* p=head;
        int i=0;
        while(i!=loc-1){
            p=p->next;
            i++;
        }
        ptr->info=info;
        ptr->next=p->next;
        p->next=ptr;
    }
    else{
        cout<<"Wrong location entered"<<endl;
    }  
    return head;  
}
struct node* insertafternode(struct node* head,int nodeinfo, int newinfo){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int status=1;
    while(p!=NULL){
        if (p->info==nodeinfo){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        cout<<"entered node not in Linked list!\n";
    }
    else{
        ptr->info=newinfo;
        ptr->next=p->next;
        p->next=ptr;
    }
    return head;
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
struct node* deletefromloc(struct node* head, int loc){
    int c=countnodes(head);
    if (loc>0 && loc<c){
        struct node* p=head;
        int i=0;
        while(i!=loc-1){
            p=p->next;
            i++;
        }
        struct node* q = p->next;
        p->next=q->next;
        free(q);
    }
    else{
        cout<<"Wrong location entered"<<endl;
    }
    // cout<<q->info<<endl;
    return head;   
}
struct node* deletefromend(struct node* head){
    struct node* p= head;
    if(head==NULL){
        cout<<"Can't Delete!\n";
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
struct node* reverselinkedList(struct node* head) {
    struct node* p = NULL;
    struct node* q = head;
    struct node* r = NULL;
    
    while (q != NULL) {
        r = q->next;   
        q->next = p;   
        p = q;         
        q = r;         
    }
    return p;  
}
// class complex{
//     int a=8;
//     public:
//             void show(){
//                 cout<<a<<endl;
//             }
// };
int main(){
    int n; 
    struct node* head = NULL; 
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }


    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;
        head=insertatend(head,value);
    }

    int choice,element,nestedchoice;;
    do{ cout << "\nMenu:\n";
        cout << "1. Traverse Linked List\n";
        cout << "2. Insert element in Linked List\n";
        cout << "3. Delete element in Linked List\n";
        cout << "4. Reverse Linked List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                traverselinkedlist(head); 
                break;
            case 2:
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at location\n";
                cout << "3. Insert at Ending\n";
                cout << "4. Insert after a node\n";
                cout << "Enter your choice: ";
                cin >> nestedchoice;

                cout << "Enter element to insert: ";
                cin >> element;
                if(nestedchoice==1){
                    head=insertatbeg(head,element);
                    traverselinkedlist(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=insertatloc(head,element,loc);
                    traverselinkedlist(head);
                }
                else if(nestedchoice==3){
                    head=insertatend(head,element);
                    traverselinkedlist(head);
                }
                else if(nestedchoice==4){
                    int v;
                    cout<<"Enter the node value after which you want to insert new node: ";
                    cin>>v;
                    cout<<endl;
                    head=insertafternode(head,v,element);
                    traverselinkedlist(head);
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
                    head=deletefrombeg(head);
                    traverselinkedlist(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=deletefromloc(head,loc);
                    traverselinkedlist(head);
                }
                else if(nestedchoice==3){
                    head=deletefromend(head);
                    traverselinkedlist(head);
                }
                else{
                    cout<<"Wrong choice entered! \n";
                }
                break;
            case 4:
                head=reverselinkedList(head);
                traverselinkedlist(head);
                     
            default:                
                break;
        }

    }
    while(choice!=0 && choice<5);
    
    struct node* trash = head;
    while (trash != NULL) {
        struct node* nextNode = trash->next;
        free(trash);
        trash = nextNode;
    }
    return 0;
    // cout<<'\n';
    // head=insertatbeg(head,85);
    // traverselinkedlist(head);

    // cout<<'\n';
    // head=insertatloc(head,35,3);
    // traverselinkedlist(head);
    // cout<<'\n';
    // head=insertatend(head,69);
    // traverselinkedlist(head);
    // cout<<'\n';
    // head=deletefrombeg(head);
    // traverselinkedlist(head);
    // cout<<'\n';
    // head=deletefromloc(head,2);
    // traverselinkedlist(head);
    // cout<<'\n';
    // head=deletefromend(head);
    // traverselinkedlist(head);
    // cout<<'\n';
    // head=reverselinkedList(head);
    // traverselinkedlist(head);

    
    
    

    
    
    // complex c1;
    // complex *ptr = &c1;
    // c1.show();

    // // complex *ptr = new complex;
    // (*ptr).show();
    // ptr->show();
    // int a=69;
    // int* b=&a;
    // cout<<b<<endl;
    // cout<<&a<<endl;
    // cout<<*b<<endl;

    // int** c=&b;
    // cout<<c<<endl;
    // cout<<*c<<endl;
}