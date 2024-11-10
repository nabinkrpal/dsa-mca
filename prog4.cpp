#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int info;
    struct node* next;
};
int countnode(struct node* head){
    int count=0;
    struct node* p=head;
    do{
        p=p->next;
        count++;
    }while(p!=head);
    return count;
}
void traverseCLL(struct node* head){
    if(head->info==-1){
        cout<<"CLL is empty"<<endl;
    }
    else{
        struct node* p=head;
        do{
            cout<<p->info<<"->";
            p=p->next;
        }
        while(p!=head);
        cout<<head->info<<" \n";
    }
}
struct node* insertatbeg(struct node* head,int info){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    if(head->info!=-1){
        ptr->info=info;
        ptr->next=head;
        do{
            p=p->next;
        }while(p->next!=head);
        p->next=ptr;
        head=ptr;
    }
    else{
        head->info=info;
    }
    return head; 
}
struct node* insertatloc(struct node* head, int info,int loc){
    int c=countnode(head);
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    if(loc>0 && loc<c){
        int i=0;
        while(i!=(loc-1)){
            p=p->next;
            i++;
        }
        ptr->info=info;
        ptr->next=p->next;
        p->next=ptr;
    }
    else{
        cout<<"Wrong location entered!"<<endl;
    }
    return head;
}
struct node* insertatend(struct node* head,int info){
    if (head->info == -1 && head->next == head) {
        head->info = info;
        return head;
    }
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    while (p->next != head) {
        p = p->next;
    }
    ptr->info = info;
    p->next = ptr;
    ptr->next = head;  
    return head;
} 

struct node* deleteatend(struct node* head){
    if (head->info == -1 ){ 
        cout<<"Can't delete!\n";
        return head;
    }
    else if(head->next == head){
        head->info=-1;
        return head;
    }
    else{
        struct node* p = head;
        while (p->next->next != head) {
            p = p->next;
        }
        struct node* q=p->next;
        p->next=head;
        free(q);
        return head;
    }
} 
struct node* deleteatloc(struct node* head, int loc){
    int c=countnode(head);
    struct node* p=head;
    if(loc>0 && loc<c){
        int i=0;
        while(i!=(loc-1)){
            p=p->next;
            i++;
        }
        struct node* q=p->next;
        p->next=q->next;
        free(q);
    }
    else{
        cout<<"Wrong location entered!\n";
    }
    return head;
    
}
struct node* deleteatbeg(struct node* head){
    if(head->next==head && head->info!=-1){
        head->info=-1;
    }
    else if(head->info==-1){
        cout<<"Can't delete!\n";
    }
    else{
        struct node* p=head;
        struct node* q;
        while(p->next!=head){
            p=p->next;
        }
        q=p->next;
        p->next=head->next;
        head=head->next;
        free(q);
    }
    return head;
    
    
}



int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->info =-1; // storing null info
    head->next = head; //setting pointers next value
    

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
        cout << "1. Traverse CircularLinked List\n";
        cout << "2. Insert element in CircularLinked List\n";
        cout << "3. Delete element in CircularLinked List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                traverseCLL(head); 
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
                    traverseCLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=insertatloc(head,element,loc);
                    traverseCLL(head);
                }
                else if(nestedchoice==3){
                    head=insertatend(head,element);
                    traverseCLL(head);
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
                    traverseCLL(head);
                }
                else if(nestedchoice==2){
                    int loc;
                    cout<<"Enter the location: ";
                    cin>>loc;
                    cout<<'\n';
                    head=deleteatloc(head,loc);
                    traverseCLL(head);
                }
                else if(nestedchoice==3){
                    head=deleteatend(head);
                    traverseCLL(head);
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
    // head->info =7; // setting the info of pointer variable
    // head->next = second; //setting pointers next value

    // second->info =11;
    // second->next = third;
    
    // third->info =14;
    // third->next = fourth;

    // fourth->info =15;
    // fourth->next = head;

    // traverseCLL(head);
    // head=insertatend(head,8);
    // traverseCLL(head);
    // head=insertatend(head,7);
    // traverseCLL(head);
    // head=insertatend(head,9);
    // traverseCLL(head);
    // head=insertatend(head,4);
    // traverseCLL(head);
    // traverseCLL(head);
    // head=insertatend(head,100);
    // traverseCLL(head);
    // head=insertatloc(head,106,2);
    // traverseCLL(head);
    // head=insertatbeg(head,69);
    // traverseCLL(head);
    // head=deleteatend(head);
    // traverseCLL(head);
    // head=deleteatloc(head,2);
    // traverseCLL(head);
    // head=deleteatbeg(head);
    // traverseCLL(head);
}   