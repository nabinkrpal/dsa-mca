#include<iostream>
#include <math.h>
#include<utility>
using namespace std;

const int max_size = 100; 

char operands[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char operators[][2] = {{'^',1},{'*',0},{'/',0},{'%',0},{'+',-1},{'-',-1}};  

void traverse(char arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void display(char arr[],int tos){
    cout<<"Your Stack: [";
    for(int i=0;i<=tos;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearSearch(char arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}
int returnindex(char arr[],int size, char val){
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
            break;
        }
    }
    return -1;
}

pair<bool,int> searchop(char arr[][2],int r,int element){
    for(int i=0;i<r;i++){
        int pres;
        if(arr[i][0]==element){
            pres=arr[i][1];
            return {true,pres};
        }
    }
    return {false,-2};
}

int push(char arr[],int tos,char val){
    if(max_size!=(tos+1)){
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

pair<int,char> pop(char arr[],int tos){
    if(tos!=-1){
        int ptos=tos;
        cout<<"Poped "<<arr[ptos]<<endl;
        tos--;
        return {tos,arr[ptos]};
    }
    else{
        cout<<"Stack UnderFlowing\n";
        return {tos,'\0'};
    }
}


void topostfix(char arr[],char p[]){
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    arr[len]=')';
    len=len+1;
    if(len<=max_size-2){
        int i=len;
        while(i>=0){
            arr[i]=arr[i-1];
            i--;
        }
        arr[0]='(';
        len++;
    }
    else{
        cout<<"Can't solve expression not enough memory!";
    }
    cout<<"Your infix expression: ";
    for (int i = 0;i<len;i++) {  
        cout << arr[i] << " ";
    }
    cout << endl;
    

    char stack[max_size/2];
    int tos=-1;
    int j=0;
    for(int i=0;i<len;i++){
        if(arr[i]=='('){
            tos=push(stack,tos,arr[i]);
        }
        else if(linearSearch(operands,52,arr[i])){
            p[j]=arr[i];
            j++;
        }
        else if(searchop(operators,6,arr[i]).first){
            while(tos!=-1 && searchop(operators,6,stack[tos]).second >= searchop(operators,6,arr[i]).second) {
                auto r = pop(stack,tos);
                tos=r.first;
                p[j]=r.second;
                j++;
            }
            tos = push(stack, tos, arr[i]);
        }
        
        else if(arr[i]==')'){
            while(tos!=-1 && stack[tos]!='('){
                auto r=pop(stack,tos);
                tos=r.first;
                p[j]=r.second;
                j++;
            }
            tos--;
           
        }
    }

    cout<<"Your Postfix expression: ";
    for (int i=0;i<j;i++){  
        cout << p[i] << " ";
    }
    cout << endl;

}
void evaluatepostfix(char pexp[]){
    int result;
    char stack[max_size/2];
    int tos=-1;
    char variables[(max_size*3)/4];
    int val[(max_size*3)/4];
    int rIndex=-1;  

    int len=0;
    while(pexp[len]!='\0'){
        len++;
    }

    int j=0;
    for(int i=0;i<len-1;i++) {
        if(linearSearch(operands,52,pexp[i])) {
            if(!linearSearch(variables,j,pexp[i])){
                variables[j]=pexp[i];
                cout<<"Enter the Value of Variable "<<pexp[i]<<": ";
                cin>>val[j];
                j++;
            }
        }
    }

    int k=0;
    while(pexp[k]!='\0'){
        if(linearSearch(operands,52,pexp[k])) {
            tos=push(stack,tos,pexp[k]);
            display(stack, tos);
        } else if(searchop(operators,6,pexp[k]).first){  
            if(tos!=-1 && tos!=0) {
                char op=pexp[k];
                auto r=pop(stack,tos);
                tos=r.first;
                char top=r.second;
                int topval=returnindex(variables,j,top);

                auto r1=pop(stack,tos);
                tos=r1.first;
                char ntop=r1.second;
                int ntopval=returnindex(variables,j,ntop);

                if(op=='+'){
                    result=(val[ntopval]+val[topval]);
                } 
                else if(op=='-'){
                    result=(val[ntopval]-val[topval]);
                } 
                else if(op=='*'){
                    result=(val[ntopval]*val[topval]);
                } 
                else if(op=='/'){
                    result=(val[ntopval]/val[topval]);
                } 
                else if(op=='%'){
                    result=(val[ntopval]%val[topval]);
                } 
                else if(op=='^'){
                    result=pow(val[ntopval],val[topval]);
                }
                
                if (rIndex==-1) { 
                    rIndex=j;     
                    variables[j]='R'; 
                }
                val[rIndex]=result; 
                tos=push(stack,tos,variables[rIndex]); 
                j++;
                display(stack,tos);
            }
        }
        k++;
    }
    cout<<"\nResult of the evaluated postfix expression: "<<val[rIndex]<<endl;

}

int main() {
    char infixarray[max_size]; 
    char p[max_size];
    cout << "Enter an infix expression: ";
    cin.getline(infixarray, max_size);  
    cout << "The infix expression you entered is: " << infixarray << endl;
    cout << "Characters in the infix expression:" << endl;
    topostfix(infixarray,p);
    cout<<'\n';
    evaluatepostfix(p);
    return 0;

}