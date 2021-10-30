#include <bits/stdc++.h>
#define pr pair<long long int, long long int>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
        
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[j][k] == num)
                {
                    a[j][k] = -1;
                }
                
            }
            
        }
    }
    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        if(a[i][0] == -1 && a[i][1] == -1 && a[i][2] == -1)
            flag = 1;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if(a[0][i] == -1 && a[1][i] == -1 && a[2][i] == -1)
            flag = 1;
    }
    if(a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1)
        flag = 1;

    if(a[2][0] == -1 && a[1][1] == -1 && a[0][2] == -1)
        flag = 1;
    if(flag == 1)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}