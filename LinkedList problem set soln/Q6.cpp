/*
7. Find the Middle Node of the List
Problem:
Implement a function to find the middle node of a singly linked list. If the list has an even
number of nodes, return the second middle node.
Example Input:
List = [10, 20, 30, 40, 50]
output: 30

6. Reverse a Singly Linked List
Problem:
Write a function to reverse the singly linked list in place.
Example Input:
List = [10, 20, 30, 40]
Example Output:
Reversed List: 40 → 30 → 20 → 10 → NULL

*/


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




//actually insert last
void insertvalue(int val){
    node *newnode = new node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
    node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}
void insertbegin(int val){
    node *newnode = new node(val);
    newnode->next=head;
    head=newnode;
}

void reverseprint(){
    node *ptr=head;
    while(ptr->next!=NULL){
        insertbegin(ptr->data);
        ptr=ptr->next;

    }
    insertbegin(ptr->data);
}





void print(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}



int main(){

insertvalue(10);
insertvalue(20);
insertvalue(30);

reverseprint();

print();

}
