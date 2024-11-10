#include<iostream>
using namespace std;
void displayarray(int arr[][20],int r, int c){
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";  
        }
        cout<<endl;
    }
}
void displaysparce(int arr[100][3],int elements){
     for(int i = 0; i < elements; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";  
        }
        cout<<endl;
    }
}


int main(){
    const int max=20;
    int A[max][max];
    int arr[(max*max)/4][3];
    int i,j,e,r,c,elements=0,count=0;
    cout<<"Enter rows of your sparce matrix: ";
    cin>>r;
    cout<<endl;
    cout<<"Enter columns of your sparce matrix: ";
    cin>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Enter element "<<i<<","<<j<<": ";
            cin>>e;
            A[i][j]=e;
            if(e!=0){
                elements++;
            }
        }
        cout<<endl;
    }
    
    if(elements>int((r*c)/4) && elements!=0){
        cout<<"Your matrix"<<endl;
        displayarray(A,r,c);
        
    }
    else if(elements==0){
    	cout<<"Matrix is sparse but have all zero's"<<endl;
	    displayarray(A,r,c);	
    }
    else{
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(A[i][j]!=0){
                    arr[count][0]=i;
                    arr[count][1]=j;
                    arr[count][2]=A[i][j];
                    count++;
                }
            }
        }
        cout<<"Your matrix: "<<endl;
        displayarray(A,r,c);
        cout<<endl;
        cout<<"Your sparce array: "<<endl;
        cout<<"row, column, info"<<endl;
        displaysparce(arr,elements);
    }
    return 0;
}