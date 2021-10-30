#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char str[n];
        cin >> str;
        int k = 0, k1;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                k++;
            }
        }
        bool p = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] == str[n - 1 - i])
            {
                p = true;
            }
            else
            {
                p = false;
                break;
            }
            if(str[i] != str[n - 1 - i] && (str[i] == '1' || str[n-i-1] == '1')){
                k1++;
            }
        }
        if (p)
        {
            if (k == 1)
            {
                cout << "BOB" << endl;
            }
            else
            {
                if (k % 2 == 1)
                {
                    cout << "ALICE" << endl;
                }
                else
                {
                    cout << "BOB" << endl;
                }
            }
            continue;
        }
        else
        {
            if (k == 2 && k1 == 1)
            {
                cout << "DRAW" << endl;
                continue;
            }
            cout << "ALICE" << endl;
        }
    }
}