#include<stdio.h>

int main(){
    int t;scanf("%d",&t);
    while(t--){
        long long int n;scanf("%lld",&n);
        int val=0;
        // vector<bool>bitmask(32,false);
        int bitmask[32]={0};
        for(long long int i=0;i<32;i++){
            if((1LL<<i)&n){
                bitmask[i]=1;
                val++;
            }
        }
        long long int ans = 1;
        if(val!=2&&val!=1) printf("No\n");
        else if(val==2){
            printf("Yes\n");
            for(int i=31;i>=0;i--){
                ans =1;
                if(bitmask[i])printf("%lld ",(1<<i));
            }
            printf("\n");
        }
        else{
            for(int i=31;i>=0;i--){
                if(bitmask[i] && i>0){
                    ans=1;
                    printf("Yes\n");
                    printf("%lld %lld\n",(1<<(i-1)),(1<<(i-1)));
                }
            }
        }
    }
}