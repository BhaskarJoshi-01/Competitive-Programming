#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    while(n>1)
    {
        if(n%2==0)
            n/=2;
        else{
            n*=3;
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}
