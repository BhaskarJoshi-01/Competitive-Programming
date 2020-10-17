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

vector<lli> pos;

// void reverseStr(string& str, lli n) 
// {  
//     // Swap character starting from two 
//     // corners 
//     n++;
//     for (lli i = 0; i < n / 2; i++) 
//         swap(str[i], str[n - i - 1]);
//     for(lli i=0;i<n;i++)
//     {
//         if(str[i]=='0')
//             str[i]='1';
//         else
//             str[i]='0';
//     }
// }

int main()
{
    lli t,n,i,j;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a;
        cin>>b;
        pos.clear();
        j=n-1;
        i=0;
        lli p=0;
        while(j>=0)
        {
            if(((a[i]==b[j]) && (p%2==0)) || ((a[i]!=b[j]) && (p%2==1)))
            {
                // reverseStr(a,i);
                if(a[i]=='0')
                    a[i]='1';
                else
                    a[i]='0';
                pos.push_back(1);
                // reverseStr(a,j);
                pos.push_back(j+1);
                if(p&1)
                    i=n-i;
                else
                    i=n-i-1;
                j--;
            }
            else
            {
                // reverseStr(a,j);
                pos.push_back(j+1);
                if(p&1)
                    i=n-i;
                else
                    i=n-i-1;
                j--;
            }
            p++;
        }
        cout<<pos.size()<<" ";
        for(i=0;i<pos.size();i++)
            cout<<pos[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
