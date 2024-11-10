#include<iostream>
using namespace std;

const int maxsize=5;

pair<int,int> enqueue(int arr[],int front,int rear,int val){
    if(front==-1 && rear==-1){
        front=(front+1)%maxsize;
        rear=(rear+1)%maxsize;
        arr[rear]=val;
        cout<<"Enqueued: "<<val<<endl;
    }
    else if(front==0 && rear==0){
        rear=(rear+1)%maxsize;
        arr[rear]=val;
        cout<<"Enqueued: "<<val<<endl;

    }
    else if(front==((rear+1)%maxsize)){
         cout<<"Circular Queue is overflowing!\n";
    }
    else{
        rear=(rear+1)%maxsize;
        arr[rear]=val;
        cout<<"Enqueued: "<<val<<endl;
    }
    return {rear, front};
}

pair<int,int> dequeue(int arr[],int front,int rear){    
    if(front==-1 && rear==-1){
        cout<<"Circular Queue is underflowing\n";
    }
    else if(front==rear){
        rear=-1;
        front=-1;
    }
    else{
        cout<<"Dequeued: "<<arr[front]<<endl;
        front=(front+1)%maxsize;
    }
    return {rear,front};
}


void display(int arr[],int front,int rear){
    if(rear==-1 && front==-1){
        cout<<"Circular Queue is empty!\n";
    }
    else{
        if(front==0 && rear==0){
            cout<<'['<<arr[0]<<"] ";
            cout<<endl;
        }
        else if(front==rear){
            cout<<'['<<arr[rear]<<"] ";
            cout<<endl;
        }
        else if(rear>front){
            cout<<'[';
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<']';
            cout<<endl;

        }
        else if(rear<front){
            cout<<'[';
            for(int i=front;i<maxsize;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<']';
            cout<<endl;
        }
        
    }      
}



//Using circular linked list
struct node{
    int info;
    struct node* next;
};

void traverseCLL(struct node* head){
    if(head->info==-1){
        cout<<"Circular Queue is empty"<<endl;
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

struct node* insertatend(struct node* head,int info){
    if (head->info == -1 && head->next == head) {
        head->info = info;
        cout<<"Enqueued: "<<info<<endl;
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
    cout<<"Enqueued: "<<info<<endl;
    return head;
} 


struct node* deleteatbeg(struct node* head){
    if(head->next==head && head->info!=-1){
        cout<<"Dequeued: "<<head->info<<endl;
        head->info=-1;
    }
    else if(head->info==-1){
        cout<<"Circular Queue is Underflowing\n";
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
        cout<<"Dequeued: "<<q->info<<endl;
        free(q);
    }
    return head;
}

int main(){
    int front=-1,rear=-1;
    int q[maxsize],ch;
    do {
        cout << ".......Menu......\n";
        cout << "1. Enqueue in Circular Queue\n";
        cout << "2. Dequeue from Circular Queue\n";
        cout << "3. Display Circular Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                int val;
                cout<<"Enter Value to Enqueue: ";
                cin>>val;
                auto r=enqueue(q,front,rear,val);
                front=r.second;
                cout<<"Front: "<<front<<endl;
                rear=r.first;
                cout<<"rear: "<<rear<<endl;
                cout<<endl;                
                break;
            }
            case 2: {
                auto r=dequeue(q,front,rear);
                front=r.second;
                cout<<"Front: "<<front<<endl;
                rear=r.first;
                cout<<"rear: "<<rear<<endl;
                cout<<endl;                               
                break;
            }
            case 3: {
                display(q,front,rear);
                cout<<endl;                
                break;
            }
            default:{
                break;
            }
        }
    } while (ch<4 && ch>0);


    //using linked list
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->info =-1; // storing null info
    head->next = head; //setting pointers next value
    

    int choice,element;;
    do {
        cout << "\n.......Menu using linked list......\n";
        cout << "1. Enqueue in Circular Queue\n";
        cout << "2. Dequeue from Circular Queue\n";
        cout << "3. Display Circular Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout<<"Enter Value to Enqueue: ";
                cin>>val;
                head=insertatend(head,val);           
                break;
            }
            case 2: {
                head=deleteatbeg(head);                             
                break;
            }
            case 3: {
                traverseCLL(head);
                cout<<endl;                
                break;
            }
            default:{
                break;
            }
        }
    } while (choice<4 && choice>0);

    struct node* trash = head;
    while (trash != head) {
        struct node* nextNode = trash->next;
        free(trash);
        trash = nextNode;
    }
    return 0;
}