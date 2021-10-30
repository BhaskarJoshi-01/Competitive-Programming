#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        std::cin>>temp;
        std::cout<<100/std::__gcd(100,temp) << std::endl;
    }
}