#include<iostream>

using namespace std;

struct node{

    int data;
    node *next;

    node(int value){
        data=value;
        next=NULL;
    }
};

node *top=NULL;
node *rear=NULL;

void enqueue(int val){
    node *newelement= new node(val);
    if(top==NULL){
        top=newelement;
        rear=newelement;
    }
    else{
        rear->next=newelement;
        rear=rear->next;
    }

}

void dequeue(){
    node *ptr=top;
    if(top==NULL){
        cout<<"Queue under flow";
    }
    else{
        int y=ptr->data;
        top=top->next;
        delete ptr;
        cout<<"Dequeued "<<y<<" ...";
    }
}

void print(){
    node *ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){

cout<<"Number of elements to enqueue:   ";
int n;
cin>>n;

cout<<"Enter "<<n<<" elements to enqueue:   ";
int x;

for(int i=0;i<n;i++){
    cin>>x;
    enqueue(x);
}

print();

dequeue();

cout<<endl;
print();


dequeue();
cout<<endl;
print();
}
