#include<bits/stdc++.h>
using namespace std;
int isOprand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='(')
    return 0;
    else
    return 1;
}
int priority(char x){
    if(x=='+'||x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 2;
    if(x=='^')
    return 3;

    return 0;
}
int main(){
    stack<char> s;
    char exp[50];
    char postfix[50];
    cout<<"Enter Expression ";
    gets(exp);
    int i=0,j=0;
    while(exp[i]!='\0'){
        if(isOprand(exp[i]))
        {
            postfix[j]=exp[i];
            j++;
            i++;
        }
        else
        {
            if(priority(s.top())>=priority(exp[i]))
            {
                postfix[j] = s.pop();
                s.push(exp[i]);
                j++;
                i++;
            }
            else
            {
                s.push(exp[i]);
                i++;
            }
        }
    }
    while(!s.empty()){
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0';
    cout<<"Postfix form is ";
    puts(postfix);

    return 0;
}
