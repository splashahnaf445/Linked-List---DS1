#include<iostream>

using namespace std;

int top=-1;
int rear=-1;


void enqueue(int val,int n, int myQ[]){
    if(rear>=n-1){
        cout<<"Queue over flow";
    }
    else if(top==-1 && rear==-1){
        top=rear=0;
        myQ[rear]=val;
    }
    else{
        rear++;
        myQ[rear]=val;
    }
}

void dequeue(int n, int myQ[]){
    if((top>rear)||(top==-1 && rear==-1)){
        cout<<"Queue under flow";
    }
    else{
        int y=myQ[top];
        top++;
        cout<<"Dequeued "<<y<<" from the queue....";
    }

}


int main(){

cout<<"Enter Queue size:    ";
int n;
cin>>n;

int myQ[n];

int x;

for(int i=0;i<n;i++){
cout<<"Enter value to enqueue:    ";
cin>>x;
enqueue(x,n,myQ);
}

for(int i=top;i<=rear;i++){
    cout<<myQ[i]<<" ";
}

dequeue(n,myQ);

cout<<endl;

for(int i=top;i<=rear;i++){
    cout<<myQ[i]<<" ";
}

dequeue(n,myQ);
cout<<endl;

for(int i=top;i<=rear;i++){
    cout<<myQ[i]<<" ";
}


}
