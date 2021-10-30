#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        char arr[3] = {'0','1','?'};
        char str[200000];
        cin>>str;
        int len = strlen(str);
        int i=0,j=0;
        long long int ans = 0;
        for(i=0;i<len;i++){
            char temp = str[i];
            for(j=i+1;j<len;j++){
                if(temp == '?'){
                    temp = str[j];
                }
                else if(str[j] == '?'){
                    if(temp == '0'){
                        temp = '1';
                    }
                    else if(temp =='1'){
                        temp = '0';
                    }
                    continue;
                }
                else if(temp == str[j]){
                    break;
                }
                else{
                    if(temp == '0'){
                        temp = '1';
                    }
                    else if(temp =='1'){
                        temp = '0';
                    }
                }
            }
            int k=i;
            if(temp == '?'){
                k=j-1;
                while(str[k]=='?' && k>0){
                    k--;
                }
                ans += ((j-i)*(j-i+1))/2 - (j-k);
            }
            else{
                ans += ((j-i)*(j-i+1))/2;
            }
            i=k;
        }
        cout<<ans <<endl;
    }
}