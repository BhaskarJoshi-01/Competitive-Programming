#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1

int main()
{
    lli t,x,y,k,r;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k;
        r=k;
        r+=(k+k*y+x-3)/(x-1);
        cout<<r<<"\n";
    }
    return 0;
}
