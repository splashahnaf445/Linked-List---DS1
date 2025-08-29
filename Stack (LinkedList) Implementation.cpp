#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int value) {
        data = value;
        next = NULL;
    }
};


node* top = NULL;

void push(int val){
    node *newstack= new node(val);
    newstack->next=top;
    top=newstack;
}

void pop(){
    node *temp=top;
    if(top==NULL){
        cout<<"Stack under flow";
    }
    else{
        cout<<"Deleting "<<temp->data<<" from Stack";
        top=top->next;
        delete temp;
    }
}

void printstack(){
    node *ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}


int main(){

push(10);
push(55);

printstack();

pop();
cout<<endl;
printstack();
}
