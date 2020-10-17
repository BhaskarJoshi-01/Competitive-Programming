// https://codeforces.com/contest/1380/problem/B
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
    lli t,n,i;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]=='R')
                s[i]='P';
            else if(s[i]=='P')
                s[i]='S';
            else if(s[i]=='S')
                s[i]='R';
        }
        cout<<s<<"\n";
    }
    return 0;
}
