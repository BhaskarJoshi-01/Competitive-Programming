// The following code finds the Nth fibonacci number 
// where 1st fiboacci number is assumed to be 0.

#include<stdio.h>
int main()
{
    long long int N;
    scanf("%lld",&N);
    if(N==1){ printf("0\n");}
    else if(N==2){printf("1\n");}
    else
    {
        int a=0,b=1;
        for(int i=3;i<=N;i++)
        {
            b=b+a;
        }
        printf("%lld\n",N);
    }
    
    return 0;
}
