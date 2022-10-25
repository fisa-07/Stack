// Stack implimentation using Array
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Stack   // creates a node mane as stack
{
    int data;
    struct Stack* next;
}*Top = NULL;   // top pointer for accessing node decleried as global variable so it can access by any function to access the node

void push(int);
int pop();
int peek(int);
int stackTop();
bool isEmpty();
bool isFull();
void display();

int main()
{
    int flag =1;
    struct Stack st;
    int ch;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Peek"<<endl;
    cout<<"4.stackTop"<<endl;
    cout<<"5.isEmpty"<<endl;
    cout<<"6.isFull"<<endl;
    cout<<"7.display"<<endl;
    cout<<"8.Exit"<<endl;
    while(flag)
    {
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            int n;
            cout<<"Enter an element:";
            cin>>n;
            push(n);
            break;
        case 2:
            cout<<pop()<<" is removed from stack"<<endl;
            break;
        case 3:
            int pos;
            cout<<"Enter position:";
            cin>>pos;
            cout<<"At position "<<pos<<" element is "<<peek(pos)<<endl;
            break;
        case 4:
            cout<<"stack top element is "<<stackTop()<<endl;
            break;
        case 5:
            if(isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                cout<<"Stack is Not Empty"<<endl;
            }
            break;
        case 6:
            if(isFull())
            {
                cout<<"Stack is Full"<<endl;
            }
            else
            {
                cout<<"Stack is Not Full"<<endl;
            }
            break;
        case 7:
            display();
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    }
    return 0;
}
void push(int n)
{
    if(isFull())
    {
        cout<<"Stack overflow"<<endl;
        exit(-1);
    }
    struct Stack* temp = new struct Stack;
    temp->data = n;
    temp->next = Top;
    Top = temp;
}
int pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        exit(-1);
    }
    int x = Top->data;
    struct Stack* Temp = Top;
    Top = Top->next;
    free(Temp);
    return x;
}
int peek(int pos)
{
    struct Stack* Temp = Top;
    while(Temp != NULL && pos--){
        Temp = Temp->next;
    }
    if(Temp==NULL){
        cout<<"Position is invalid";
        exit(-1);
    }
    return Temp->data;
}
int stackTop()
{
    return Top->data;
}
bool isEmpty()
{
    if(Top==NULL)
        return true;
    else
        return false;
}
bool isFull()
{
    struct Stack* Temp = new Stack;
    if(Temp == NULL)
    return true;
    else
    return false;
}
void display()
{
    struct Stack* p = Top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
