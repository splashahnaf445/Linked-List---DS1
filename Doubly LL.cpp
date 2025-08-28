#include<iostream>

using namespace std;

struct node{
    int data;
    node *prev;
    node *next;

    node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }

};

node *head=NULL;

void insertfirst(int val){
    node *newnode= new node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertlast(int val){
    node *newnode= new node(val);
    node *ptr=head;
    while(ptr!=NULL && ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
}

void insertat(int val, int pos){
    node *newnode=new node(val);
    if(pos<0){
        cout<<"invalid";
    }
    else if(pos==0){
        insertfirst(val);
    }
    else{
        int currpos=0;
        node *ptr=head;
        while(ptr!=NULL && currpos<pos-1){
            ptr=ptr->next;
            currpos++;
        }
        if(ptr==NULL){
            cout<<"out of bound";
        }
        else{
        newnode->next=ptr->next;
        newnode->prev=ptr;
        ptr->next->prev=newnode;
        ptr->next=newnode;
        }

    }

}

void deletefirst(){
    node *ptr=head;
    head=ptr->next;
    ptr->next->prev=NULL;
    delete ptr;
}

void deletelast(){
    node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    delete ptr->next;

}

void deleteany(int val){
node *ptr=head;

    if(ptr->data==val){
    deletefirst();
    }

    else{
        while(ptr!=NULL && ptr->data!=val){
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"Out of bound";
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            delete ptr;
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

void reverseprint(){
    node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    node *ptr=current;
    while(ptr->prev!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<ptr->data;

}

int main(){

cout<<"Enter number of values:      ";
int n;
cin>>n;

int v;
cout<<"Enter"<<n<<" values to insert first:     ";
for(int i=1;i<=n;i++){
    cin>>v;
    insertfirst(v);
}

cout<<endl;

print();

cout<<"Enter number of values:      ";
cin>>n;


cout<<"Enter"<<n<<" values to insert last:     ";
for(int i=1;i<=n;i++){
    cin>>v;
    insertlast(v);
}

cout<<endl;
print();


cout<<"Enter the value and the position to insert:      ";
cin>>v;
cin>>n;

insertat(v,n);

cout<<endl;
print();

cout<<endl;
cout<<"Deleting the first value of the list.... ";
deletefirst();

cout<<endl;
cout<<endl;
print();

cout<<endl;
cout<<"Deleting the lastt value of the list.... ";
deletelast();
cout<<endl;
print();

cout<<"Enter the value to delete:      ";
cin>>v;

deleteany(v);
cout<<endl;
cout<<"Deleting the value from the list.... ";

cout<<endl;
print();

cout<<endl;
cout<<"The final doubly linked list is:     ";
print();
cout<<endl;

cout<<"The reversed doubly linked list is:     ";
reverseprint();

}
