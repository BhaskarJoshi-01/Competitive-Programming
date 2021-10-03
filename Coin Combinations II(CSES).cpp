#include <iostream>
using namespace std;
#define M 1000000007
#define ll long long int
 
int main()
{
    ll n,x;
    cin >> n >> x;
    ll mem[x+1]={0}, weight[n];
    for(int i=0;i<n;i++) cin >> weight[i];
    mem[0]=1;
    for(int j=0;j<n;j++)
        for(int i=1;i<=x;i++)
            if(i>=weight[j])
                mem[i]=(mem[i]+mem[i-weight[j]])%M;
    cout << mem[x] << endl;
    return 0;
}
