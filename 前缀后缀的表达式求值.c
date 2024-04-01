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
 
void evaluatepostfix(char *a)//每两个数据量+一个操作量 
{
    int i=0,op1,op2;
//    for(i=0;i<length;i++)
	while(a[i]!='\0')
    {
        if(a[i]>='0' && a[i]<='9')
        {
            push(a[i] - '0');//字符以ASCII的形式储存，0-9在ASCII分别为48-57，因此减去'0'就是减去48，使得字符对应的ASCII码变为数字并以int型储存在栈中 
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

    char  A[] = {'2', '3', '*', '5', '4', '*', '+', '9', '-','\0'};//后缀法计算方式 
    evaluatepostfix(A);
    printf("The result is: %d\n", pop());
}
