#include<stdio.h>
#include<math.h>

int main(){
    int t;scanf("%d",&t);
    while(t--){
        float c;scanf("%f",&c);
        double i = sqrt(c);
        for(;;i-=0.000002){
            if((i*i)+sqrt(i)-c<0.00002) break;
        }
        printf("%0.6f\n",i);
    }
}

// other method that can be used is binary search between cuberoot(c) & sqrt(c);