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
    while(p->next!=head){
            p=p->next;
            count++;
    }
    return count;
}
void traverseCDLL(struct node* head){
    if(head->info==-1){
        cout<<"Double Linked list empty!\n";
    }
    else if(head->next==head && head->prev==head && head->info!=-1){
        cout<<head->info<<"->,<-"<<head->info<<endl;
    }
    else{
        struct node* p=head;
        do{
            cout<<p->info<<"->,<-";
            p=p->next;
        }while(p!=head);
        cout<<head->info<<"\n";
    }
}

struct node* insertatend(struct node* head, int info){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(head->info==-1){
        head->info=info;
        return head;
    }
    else if(head->next==head && head->prev==head && head->info!=-1){
        ptr->info=info;
        ptr->next=head;
        ptr->prev=head;
        head->next=ptr;
        head->prev=ptr;
        return head;
    }
    else{
        struct node* p=head;
        ptr->info=info;
        p=p->prev;
        p->next=ptr;
        head->prev=ptr;
        ptr->next=head;
        ptr->prev=p;
        return head;
    }
    
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
        ptr->prev=p;
        p->next->prev=ptr;
        p->next=ptr;
    }
    else{
        cout<<"Wrong location entered!\n";
    }
    return head;
}
struct node* insertatbeg(struct node* head, int info){
    if(head->info!=-1){
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->info=info;
        ptr->next=head;
        ptr->prev=head->prev;
        head->prev->next=ptr;
        head->prev=ptr;
        head=ptr;
    }
    else{
        head->info=info;
    }
    return head;
}

struct node* deleteatend(struct node* head){
    struct node* p=head;
    struct node* q=p->prev;
    if(head->info!=-1){
        q->prev->next=head;
        head->prev=q->prev;
        free(q);
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
        q->next->prev=p;
        free(q);
    }
    else{
        cout<<"Wrong location entered!\n";
    }
    return head;
}
struct node* deleteatbeg(struct node* head){
    if(head->info==-1){
        cout<<"Can't delete\n";    
    }
    else if(head->next==NULL && head->prev==NULL){
        head->info=-1;
    }
    else{
        struct node* p=head;
        struct node* q=p->next;
        q->prev=p->prev;
        p->prev->next=q;
        head=q;
        free(p);
    }
    return head;
}

int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->info=-1;
    head->next=head;
    head->prev=head;
    
    
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
                traverseCDLL(head); 
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
                    traverseCDLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=insertatloc(head,element,loc);
                    traverseCDLL(head);
                }
                else if(nestedchoice==3){
                    head=insertatend(head,element);
                    traverseCDLL(head);
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
                    traverseCDLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=deleteatloc(head,loc);
                    traverseCDLL(head);
                }
                else if(nestedchoice==3){
                    head=deleteatend(head);
                    traverseCDLL(head);
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
    while (trash != head) {
        struct node* nextNode = trash->next;
        free(trash);
        trash = nextNode;
    }
    return 0;
    // traverseCDLL(head);
    // head=insertatend(head,100);
    // traverseCDLL(head);
    // head=insertatend(head,10);
    // traverseCDLL(head);
    // head=insertatend(head,15);
    // traverseCDLL(head);
    // head=insertatend(head,19);
    // traverseCDLL(head);
    // head=insertatloc(head,29,2);
    // traverseCDLL(head);
    // head=insertatbeg(head,69);
    // traverseCDLL(head);
    // head=deleteatend(head);
    // traverseCDLL(head);
    // head=deleteatloc(head,2);
    // traverseCDLL(head);
    // head=deleteatbeg(head);
    // traverseCDLL(head);
}