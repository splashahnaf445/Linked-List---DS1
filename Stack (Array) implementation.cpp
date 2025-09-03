// Online C++ compiler to run C++ program online
#include<iostream>

using namespace std;

int top=-1;

void push(int stk[],int n,int val){
    if(top>=n-1){
        cout<<"Stack over flow";
    }
    else{
        top++;
        stk[top]=val;
    }
}

void pop(int stk[],int n){
    if(top<=-1){
        cout<<"Stack under flow";
    }
    else{
        int y=stk[top];
        top--;
       cout<<"Popped "<<y<<" from stack";
    }
}

int main(){

cout<<"Enter stack size:    ";
int n;
cin>>n;

int arr[n];

cout<<endl;
cout<<"Enter "<<n<<" elements:  ";

int v;
for(int i=0;i<n;i++){
    cin>>v;
    push(arr,n,v);

}


for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
pop(arr,n);

for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }

}
