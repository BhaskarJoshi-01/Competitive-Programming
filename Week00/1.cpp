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
    lli t,n,x,var,f;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        var = 0;
        lli i=1;
        while(i<1020)
        {
            if (i == 1)
            {
                var++;
                var++;
                // continue;
            }
            else
            {
                var += x;
                // continue;
            }
            if ((var-n)>=0)
            {
                cout << i<< "\n";
                break;
            }
            i++;
        }
    }
    return 0;
}
