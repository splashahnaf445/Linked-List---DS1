#include<iostream>

using namespace std;

class myqueue{

int front=-1;
int rear=-1;

int que[50];

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
        return;
    }
    rear++;
    que[rear]=val;
}

int dequeue(){
    if(front==-1 || front>rear){
        cout<<"Queue is empty";
        return -1;
    }
    int y=que[front];
    front++;
    return y;
}

int peek(){
    int x=que[rear];
    return x;
}

void reversequeue(){
    if(front==-1 || front>rear){
        return;
    }
    int x=dequeue();
    reversequeue();
    enqueue(x);

}

void printqueue(){
    for(int i=front;i<=rear;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;
}


};


int main(){

myqueue q1;

q1.enqueue(10);
q1.enqueue(20);
q1.enqueue(30);
q1.enqueue(40);

//q1.dequeue();
//q1.dequeue();

q1.printqueue();

// reverse the queue
q1.reversequeue();

q1.printqueue();

}
