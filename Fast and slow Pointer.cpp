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

void insert1st(int val){
    node *newnode = new node(val);
    newnode->next=head;
    head=newnode;
}

void midposition(){
    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Mid index data is : "<<slow->data;
}
void print(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){

insert1st(10);
insert1st(20);
insert1st(30);
insert1st(40);
insert1st(50);
print();

midposition();

}

