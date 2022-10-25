#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
          char* arr;
          int Top;
          int size;
}s;
void push(struct Stack* s,char data)
{
          if(s->Top == s->size-1)
          {
                    printf("Stack overflow");
                    exit(-1);
          }
          s->Top++;
          s->arr[s->Top] = data;
}
char pop(struct Stack* s)
{
          char x;
          if(s->Top == -1)
          {
                    printf("Stack underflow");
                    exit(-1);
          }
          x = s->arr[s->Top];
          s->Top--;
          return x;
}
int match(char x,char y)
{
          if(y == ')' && x == '(')
                    return 1;
          if(y == '}' && x == '{')
                    return 1;
          if(y == ']' && x == '[')
                    return 1;
          return 0;
}
int check(char str[])
{
          int i;
          for(i=0;i<strlen(str);i++)
          {
                    if(str[i] =='(' || str[i] == '{' || str[i] == '[')
                    {
                              push(&s,str[i]);
                    }
                    else
                    {
                              if(s.Top == -1){
                                        return 0;
                              }
                              else{
                                        if(!match(pop(&s),str[i]))
                                        {
                                                  return 0;
                                        }
                              }

                    }
          }
          if(s.Top == -1)
          {
                    return 1;
          }

}
int main()
{
          char str[50];
          s.Top = -1;
          printf("Enter Stack Size : ");
          scanf("%d",&s.size);
          s.arr = (char*)malloc(s.size*sizeof(char));
          printf("Enter Prenthesis : ");
          scanf("%s",str);
          if(check(str))
                    printf("Prenthesis matched");
          else
                    printf("Prenthesis not matched");
          return 0;
}
