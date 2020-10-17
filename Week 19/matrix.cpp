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
    lli t, n, m, i, j, a[110][110], cnt, avg;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                cin >> a[i][j];
        cnt = 0;
        for (i = 1; i <= n / 2; i++)
        {
            for (j = 1; j <= m / 2; j++)
            {
                avg = a[i][j] + a[n - i + 1][j] + a[i][m - j + 1] + a[n - i + 1][m - j + 1];
                avg/=4;
                // cout<<"oh "<<avg<<" ";
                lli var = 0, var2 = 0;
                var += abs(avg-a[i][j]);
                var += abs(avg-a[n-i+1][j]);
                var += abs(avg-a[i][m-j+1]);
                var += abs(avg-a[n-i+1][m-j+1]);
                avg++;
                var2 += abs(avg-a[i][j]);
                var2 += abs(avg-a[n-i+1][j]);
                var2 += abs(avg-a[i][m-j+1]);
                var2 += abs(avg-a[n-i+1][m-j+1]);
                cnt+=min(var,var2);
            }
            if(m%2==1)
            {
                lli var = 0, var2 = 0;
                avg = a[i][j] + a[n-i+1][j];
                avg /= 2 ;
                var += abs(avg-a[i][j]);
                var += abs(avg-a[n-i+1][j]);
                avg++;
                var2 += abs(avg-a[i][j]);
                var2 += abs(avg-a[n-i+1][j]);
                cnt+=min(var,var2);
            }
            // cout<<"\n";
        }
        if(n%2==1)
        {
            for (j = 1; j <= m / 2; j++)
            {
                avg = a[i][j] + a[i][m - j + 1];
                avg/=2;
                // cout<<"oh "<<avg<<" ";
                lli var = 0, var2 = 0;
                var += abs(avg-a[i][j]);
                var += abs(avg-a[i][m-j+1]);
                avg++;
                var2 += abs(avg-a[i][j]);
                var2 += abs(avg-a[i][m-j+1]);
                cnt+=min(var,var2);
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
