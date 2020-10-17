// https://m1.codeforces.com/contest/1379/problem/A
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
    lli t,n,i,j,flag,flag2,ct,k;
    string str,var,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>str;
        var="abacaba";
        flag2=0,ct=0;
        for(i=0;i<n;i++)
        {
            for(j=i;(j<i+7)&&(j<n);j++)
            {
                if(str[j]!=var[j-i])
                    break;
                if(j==(i+6))
                    ct++;
            }
        }
        if(ct>1)
        {
            cout<<"No\n";
            continue;
        }
        else if(ct==1)
        {
            for(i=0;i<n;i++)
                if(str[i]=='?')
                    str[i]='z';
            cout<<"Yes\n"<<str<<"\n";
            continue;
        }
        for(i=0;i<n;i++)
        {
            flag=0;
            for(j=i;(j<i+7)&&(j<n);j++)
            {
                if(str[j]==var[j-i] || str[j]=='?');
                else
                    break;
                if(j==(i+6))
                    flag=1;
            }
            if(flag==1)
            {
                tmp=str;
                for(j=i;j<(i+7)&&(j<n);j++)
                {
                    tmp[j]=var[j-i];
                }
                ct=0;
                for(j=0;j<n;j++)
                {
                    for(k=j;(k<j+7)&&(k<n);k++)
                    {
                        if(tmp[k]!=var[k-j])
                            break;
                        if(k==(j+6))
                            ct++;
                    }
                }
                if(ct==1)
                {
                    str=tmp;
                    flag2=1;
                    break;
                }                    
            }
        }
        for(i=0;i<n;i++)
            if(str[i]=='?')
                str[i]='z';
        if(flag2==1)
            cout<<"Yes\n"<<str<<"\n";
        else
            cout<<"No\n";
    }
    return 0;
}
