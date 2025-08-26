/*
1. Create and Display a Singly Linked List
Problem:
Write a program to create a singly linked list and display its elements. Allow the user to input
the values for the nodes.
Example Input:
Values = [10, 20, 30, 40]
*/

/*
2. Insert at the Beginning of the List
Problem:
Implement a function to insert a new node at the beginning of a singly linked list.
Example Input:
List = [20, 30, 40], Value = 10
*/


/*
3. Insert at the End of the List
Problem:
Write a function to insert a new node at the end of the singly linked list.
Example Input:
List = [10, 20, 30], Value = 40

*/


/*
4. Delete a Node by Value
Problem:
Write a function to delete the first node with a specific value in a singly linked list.

*/

/*
5. Search for an Element in the List
Problem:
Implement a function to search for a specific value in the singly linked list and return its position. If not found, return -1.
Example Input:
List = [10, 20, 30, 40], Value = 30
Example Output:
Position: 3
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


void deleteval(int val){
    node *ptr=head;
    if(ptr->data==val){
        head=ptr->next;
        delete ptr;
    }
    else{
        node *prev=nullptr;
        while(ptr!=NULL && ptr->data!=val){
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"Not found!";
        }
        else{
            prev->next=ptr->next;
            delete ptr;
        }
    }
}


int searchnode(int val){
    int pos=1;
    node *curr=head;
    while(curr!=NULL && curr->data!=val){
        curr=curr->next;
        pos++;
    }
    if(curr==NULL){
        return -1;
    }
    else{
        return pos;
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

int n;
cout<<"how many values: ";
cin>>n;

int s;

cout<<"Enter "<<n<<" values:    ";
for(int i=0;i<n;i++){
    cin>>s;
    insertvalue(s);
}
print();

cout<<endl;

int f;
cout<<"give value to Insert first: ";
cin>>f;

insertbegin(f);
cout<<endl;

print();

int q;
cout<<"give the value to delete from the list: ";
cin>>q;

cout<<endl;

deleteval(q);

print();

int r;
cout<<"give the value to search in the list: ";
cin>>r;

int res=searchnode(r);

cout<<endl;
cout<<res;


}
