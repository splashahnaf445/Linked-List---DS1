#include<iostream>

using namespace std;

class Stack{


int stk[50];
int top=-1;

public:

void push(int val){
    if(top==49){
        cout<<"Stack is full";
        return;
    }
    top++;
    stk[top]=val;
}

void pop(){
    if(top==-1){
        cout<<"Stack underflow";
        return;
    }
    cout<<"Popped "<<stk[top];
    cout<<endl;
    top--;
}
int peek(){
    if(top==-1){
        cout<<"Stack underflow";
        return -1;
    }
    return top;
}

void print(){
    if(top==-1){
        cout<<"Stack underflow";
        return;
    }
    cout<<"The stack is :   ";
    for(int k=top;k>=0;k--){
        cout<<stk[k]<<" ";
    }
}

};

class Queue{

int que[50];
int front=-1;
int rear=-1;

public:

void enqueue(int val){
    if(rear==49){
        cout<<"Queue is full";
        return;
    }
    if(front==-1 && rear==-1){
        front++;
        rear++;
        que[rear]=val;
    }
    else{
        rear++;
        que[rear]=val;
    }
}


void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
        return;
    }
    if(front==rear){
        cout<<endl;
        cout<<"Dequeued "<<que[front];
        front=-1;
        rear=-1;
    }
    else{
        cout<<endl;
        cout<<"Dequeued "<<que[front];
        front++;
    }

}

void printque(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
        return;
    }
    cout<<"The queue is:    ";
    for(int i=front;i<=rear;i++){
        cout<<que[i]<<" ";
    }

}

};

class circqueue{
int circq[50];
int front=-1;
int rear=-1;

public:


void enqueue(int val){
    if((rear+1)%50==front){
        cout<<"Circular queue is full";
        return;
    }
    if(front==-1 && rear==-1){
        front++;
        rear=(rear+1)%50;
        circq[rear]=val;
    }
    else{
        rear=(rear+1)%50;
        circq[rear]=val;
    }

}


void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Circular queue is empty";
        return;
    }
    cout<<endl;
    if(front==rear){
        cout<<"Dequeued "<<circq[front];
        front=-1;
        rear=-1;
    }
    else{
        cout<<"Dequeued "<<circq[front];
        front=(front+1)%50;
    }


}


void printq(){
    if(front==-1 && rear==-1){
        cout<<"Circular queue is empty";
        return;
    }

    int i=front;
    cout<<"The circular queue:  ";
    while(true){
        cout<<circq[i]<<" ";
        if(i==rear){
            break;
        }
        i=(i+1)%50;
    }
}

};


int main(){

cout<<"Give stack size: ";
int n;
cin>>n;

Stack st1;

cout<<endl;
cout<<"Enter "<<n<<" values to push";
int a;


for(int i=1;i<=n;i++){
    cin>>a;
    st1.push(a);
}

cout<<endl;
st1.print();

cout<<"Enter how many values to pop";
cin>>n;

for(int i=1;i<=n;i++){
    st1.pop();
}

cout<<endl;
st1.print();


cout<<endl<<endl;
cout<<"Initializing Queue....";
cout<<endl;

cout<<"Enter how many values to enqueue:    ";
int x;
cin>>x;

Queue q1;

cout<<"Enter "<<x<<" values:    ";
int b;
for(int j=1;j<=x;j++){
    cin>>b;
    q1.enqueue(b);
}

cout<<endl;
q1.printque();

cout<<"Enter how many values to dequeue:    ";
cin>>b;
for(int k=1;k<=b;k++){
    q1.dequeue();
}

cout<<endl;
q1.printque();

circqueue q2;

cout<<endl<<endl;
cout<<"Initializing Circular Queue....";
cout<<endl;

cout<<"Enter how many values to enqueue:    ";
cin>>x;

cout<<"Enter "<<x<<" values:    ";
for(int j=1;j<=x;j++){
    cin>>b;
    q2.enqueue(b);
}

cout<<endl;
q2.printq();

cout<<"Enter how many values to dequeue:    ";
cin>>b;
for(int k=1;k<=b;k++){
    q2.dequeue();
}

cout<<endl;
q2.printq();

}
