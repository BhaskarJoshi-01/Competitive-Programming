#include <bits/stdc++.h>
#define pr pair<long long int, long long int>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], flag = 0;
    for (int i = 0; i < n; i++)
        a[i] = -1;
    for (int  i = 0; i < m; i++)
    {
        int s, c;
        cin >> s >> c;
        s--;
        if(a[s] == -1)
            a[s] = c;
        else if(a[s] == c)
            continue;
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag != 1)
    {
        if(n == 1)
        {
            if(a[0] == -1)
                a[0] = 0;
        }
        else
        {
            if(a[0] == -1)
                a[0] = 1;
            else if(a[0] == 0)
                flag = 1;
            for (int j = 1; j < n; j++)
            {
                if(a[j] == -1)
                    a[j] = 0;
            }
            
        }
    }
    if(flag == 1)
        cout << "-1" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}