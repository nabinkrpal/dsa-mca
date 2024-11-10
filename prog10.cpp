#include<iostream>
#include<utility>
using namespace std;
const int maxsize=5;

pair<int,int> enqueue(int arr[],int front,int rear,int val){
    if (rear + 1 == maxsize) {
        cout << "Queue overflowing!\n";
    } 
    else {
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = val;
        cout<<"Enqueued: "<<val<<endl;
    }
    return {rear, front};
}

pair<int,int> dequeue(int arr[],int front,int rear){    
    if(front==-1 && rear==-1){
        cout<<"Queue is Empty!\n";
    }
    else if(front<=rear && front<maxsize){
        cout<<"Dequeued: "<<arr[front]<<endl;
        front++;
    }
    else{
        cout<<"Queue is Underflowing!\n";
    }
    return {rear,front};
}

void display(int arr[],int front,int rear){
    if(rear==-1 && front==-1){
        cout<<"Queue is empty!\n";
    }
    else if(rear<front){
        cout<<"Queue is empty!\n";
    }
    else{
        cout<<'[';
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<']';
        cout<<endl;
    }      
}

int main(){
    int front=-1,rear=-1;
    int q[maxsize],ch;
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
                auto r=enqueue(q,front,rear,val);
                front=r.second;
                // cout<<"Front: "<<front<<endl;
                rear=r.first;
                // cout<<"rear: "<<rear<<endl;
                cout<<endl;                
                break;
            }
            case 2: {
                auto r=dequeue(q,front,rear);
                front=r.second;
                // cout<<"Front: "<<front<<endl;
                rear=r.first;
                // cout<<"rear: "<<rear<<endl;
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
    // front=enqueue(q,front,rear,8).second;
    // rear=enqueue(q,front,rear,8).first;
    // display(q,front,rear);
    // front=enqueue(q,front,rear,7).second;
    rear=enqueue(q,front,rear,7).first;
    // display(q,front,rear);
    // front=enqueue(q,front,rear,5).second;
    // rear=enqueue(q,front,rear,5).first;
    // display(q,front,rear);
    // front=enqueue(q,front,rear,8).second;
    // rear=enqueue(q,front,rear,8).first;
    // display(q,front,rear);
    // front=enqueue(q,front,rear,9).second;
    // rear=enqueue(q,front,rear,9).first;
    // display(q,front,rear);
    // front=dequeue(q,front,rear).second;
    // rear=dequeue(q,front,rear).first;
    // display(q,front,rear);
    // front=dequeue(q,front,rear).second;
    // rear=dequeue(q,front,rear).first;
    // display(q,front,rear);
    // front=dequeue(q,front,rear).second;
    // rear=dequeue(q,front,rear).first;
    // display(q,front,rear);
    // front=dequeue(q,front,rear).second;
    // rear=dequeue(q,front,rear).first;
    // display(q,front,rear);
    // front=dequeue(q,front,rear).second;
    // rear=dequeue(q,front,rear).first;
    // display(q,front,rear);
   
    return 0;
}