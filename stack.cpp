// Stack implimentation using Array
#include<iostream>
using namespace std;
struct stack
{
    int top = -1;
    int size;
    int* s;
};
void push(int,struct stack&);
int pop(struct stack&);
int peek(int,struct stack);
int stackTop(struct stack);
bool isEmpty(struct stack);
bool isFull(struct stack);
void display(struct stack);

int main()
{
    int flag =1;
    struct stack st;
    cout<<"Enter size: ";
    cin>>st.size;
    cout<<"Size of Stack "<<st.size<<" is created"<<endl;
    st.s=new int [st.size];
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
            push(n,st);
            break;
        case 2:
            cout<<pop(st)<<" is removed from stack"<<endl;    
            break;
        case 3:
            int pos;
            cout<<"Enter position:";
            cin>>pos;
            cout<<"At position "<<pos<<" element is "<<peek(pos,st)<<endl;
            break;
        case 4:
            cout<<"stack top element is "<<stackTop(st)<<endl;
            break;
        case 5:
            if(isEmpty(st))
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                cout<<"Stack is Not Empty"<<endl;
            }
            break;
        case 6:
            if(isFull(st))
            {
                cout<<"Stack is Full"<<endl;
            }
            else
            {
                cout<<"Stack is Not Full"<<endl;
            }
            break;
        case 7:
            display(st);
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
void push(int n,struct stack &st)
{
    if(isFull(st))
    {
        cout<<"Stack overflow"<<endl;
        exit(-1);
    }
    st.top+=1;
    st.s[st.top]=n;
}
int pop(struct stack &st)
{
    if(isEmpty(st))
    {
        cout<<"Stack underflow"<<endl;
        exit(-1);
    }
    int x = st.s[st.top];
    st.top-=1;
    return x;
}
int peek(int pos,struct stack st)
{
    if(st.top-pos+1<0)
    {
        exit(-1);
    }
    return st.s[st.top-pos+1];
}
int stackTop(struct stack st)
{
    return st.s[st.top];
}
bool isEmpty(struct stack st)
{
    if(st.top==-1)
        return true;
    else 
        return false;
}
bool isFull(struct stack st)
{
    if(st.top==st.size-1)
    return true;
    else
    return false;
}
void display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}
