#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
int stack[MAX];
int  pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
void push(int c)
{
    if(top==MAX-1){
        printf("Stack is full\n");
    }
    else{
        stack[++top]=c;
    }
}
void top_Num()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%c\n",stack[top]);
    }
}
void print()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void evaluatepostfix(char *a)
{
    int i=0,op1,op2;
//    for(i=0;i<length;i++)
	while(a[i]!='\0')
    {
        if(a[i]>='0' && a[i]<='9')
        {
            push(a[i] - '0');
        }
        else
        {   
            op2=pop();
            op1=pop();
            
            switch(a[i])
            {
                case '+':push(op1+op2);break;
                case '-':push(op1-op2);break;
                case '*':push(op1*op2);break;
                case '/':push(op1/op2);break;
            }
        }
        i++;
    }
    
}
int main()
{   

    char  A[] = {'2', '3', '*', '5', '4', '*', '+', '9', '-','\0'};
    evaluatepostfix(A);
    printf("The result is: %d\n", pop());
}
