#include<iostream>

/*
1. Implement a Stack Using Array
• Problem: Create a stack using an array. Implement push, pop, peek, and isEmpty
operations.
• Example Input:
Operations: push(10), push(20), push(30), pop()
• Example Output:
Stack: 10 → 20

*/

using namespace std;

class stack{

int stk[100];

int top=-1;

public:

void push(int val){
    if(top==99){
        cout<<"Stack overflow";
        cout<<endl;
        return;
    }

    top++;
    stk[top]=val;
}

int pop(){
    if(top==-1){
        cout<<"Stack under flow";
        cout<<endl;
        return -1;
    }
    int y=stk[top];
    top--;
    return y;

}


int peek(){
    if(top==-1){
        cout<<"Stack under flow";
        cout<<endl;
        return -1;
    }
    return stk[top];
}


void printstack(){
    if(top==-1){
        cout<<"Stack under flow";
    }
    cout<<"The stack is: ";
    for(int i=top;i>=0;i--){
        cout<<stk[i]<<" ";
    }

}

};



int main(){

class stack st1;

st1.push(10);
st1.push(20);
st1.push(30);
st1.printstack();
st1.pop();
st1.printstack();


int x=st1.peek();
cout<<endl;
cout<<x;


}
