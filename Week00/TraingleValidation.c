/*
    The following code validate a traingle is possible or not given it's all 3 sides length
*/

#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    if((a>b+c) || (b>a+c) || (c>a+b))
    {
        printf("YES, valid Triangle\n");
    }
    else
    {
        printf("Not Valid Triangle\n");
    }
}
