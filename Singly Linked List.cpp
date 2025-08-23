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

node *head=NULL;

void insertFirst(int val){
    node *newNode = new node(val);
    newNode->next=head;
    head=newNode;
}

void insertLast(int val){
    node *newNode= new node(val);
    node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}

void deleteFirst(){
    node *ptr=head;
    head=head->next;
    //head=NULL;
    delete ptr;
}

void deleteLast(){
    node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    delete ptr->next;
}

void insertAt(int pos, int value){
    node *newNode = new node(value);
    int currpos=0;

    if(pos<0){
        cout<<"Invalid position!";
    }
    else if(pos==0){
        insertFirst(value);
    }
    else{
        node *current=head;
        while(current!=NULL && currpos<pos-1){
            current=current->next;
            currpos++;
        }
        if(current==NULL){
            cout<<"The position exceeds the Linked list limit";
            cout<<endl;
        }
        else{
            newNode->next=current->next;
            current->next=newNode;
        }
    }

}


void print(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){

int n,m,o;
cout<<"Enter the value to insert first in the Linked List: ";
cin>>n;
cout<<endl;

cout<<"Enter 2nd value to insert first: ";
cin>>m;
cout<<endl;

cout<<"Enter 3rd value to insert first: ";
cin>>o;
cout<<endl;

insertFirst(n);
insertFirst(m);
insertFirst(o);

cout<<"The list after insertions:   ";
print();
cout<<endl;

int p,q;

cout<<"Enter the value to insert last:  ";
cin>>p;
cout<<endl;

cout<<"Enter 2nd value to insert last:  ";
cin>>q;

insertLast(p);
insertLast(q);
cout<<endl;

cout<<"The updated list after insertions:   ";
print();
cout<<endl;


cout<<"The list after deleting first element:   ";
deleteFirst();
print();
cout<<endl<<endl;

cout<<"The list after deleting last element:   ";
deleteLast();
print();
cout<<endl<<endl;

int a,b;
cout<<"Enter the value and the position to insert the value in the list:    ";
cin>>a;
cin>>b;

insertAt(b,a);

cout<<endl<<endl;

cout<<"The final Linked List is:    ";
print();

}
