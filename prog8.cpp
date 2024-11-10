#include<iostream>
#include <utility>
#include <cstdlib>
using namespace std;

int push(int arr[],int tos,int val,int msize){
    if(msize!=(tos+1)){
        tos=tos+1;
        arr[tos]=val;
        cout<<"Pushed "<<val<<endl;
        return tos;
    }
    else{
        cout<<"Stack Overflowing!\n";
    }
    return tos;
}
pair<int,int> pop(int arr[],int tos){
    if(tos!=-1){
        int ptos=tos;
        cout<<"Poped "<<arr[ptos]<<endl;
        tos--;
        return {tos,arr[ptos]};
    }
    else{
        cout<<"Stack UnderFlowing\n";
        return {tos,-1};
    }
}
void peek(int arr[], int tos){
    if(tos!=-1){
        cout<<"Top of Stack: "<<arr[tos]<<endl;
    }
    else{
        cout<<"$\n";
    }
}
void display(int arr[],int tos){
    cout<<"Your Stack: [";
    for(int i=0;i<=tos;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    const int maxsize=5;
    int Stack[maxsize];
    int tos=-1,ch;
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
                tos=push(Stack,tos,val,maxsize);
                cout<<endl;                
                break;
            case 2: {
                auto r=pop(Stack,tos);
                tos=r.first;
                // int element=r.second;
                // cout<<element;                
                cout<<endl;                
                break;
            }
            case 3: {
                peek(Stack,tos);
                cout<<endl;                
                break;
            }
            case 4: {
                display(Stack,tos);
                cout<<endl;                
                break;
            }
            default:
                break;
        }
    } while (ch<5 && ch>0);
    // tos=push(Stack,tos,8,maxsize);
    // display(Stack,tos);
    // tos=push(Stack,tos,7,maxsize);
    // display(Stack,tos);
    // tos=push(Stack,tos,15,maxsize);
    // display(Stack,tos);
    // tos=push(Stack,tos,69,maxsize);
    // display(Stack,tos);
    // tos=push(Stack,tos,79,maxsize);
    // display(Stack,tos);
    // tos=push(Stack,tos,99,maxsize);
    // display(Stack,tos);
    // tos=pop(Stack,tos);
    // display(Stack,tos);
   

    return 0;
}