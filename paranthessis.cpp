#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    string exp;
    cout<<"Enter Expression ";
    cin>>exp;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='(')
        s.push('(');
        else if(exp[i]==')')
        {
            if(s.empty())
            {
               cout<<"Parenthessis is Not Matched";
               return 0;
            }
            s.pop();
        }
    }
    if(s.empty())
    cout<<"Parenthessis Match";
    else
    cout<<"Parenthessis Not Match";
    return 0;
}
