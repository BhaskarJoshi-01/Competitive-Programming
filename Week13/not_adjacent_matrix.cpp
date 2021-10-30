#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0, y = 0;
        cin >> n;
        int arr[n][n];
        int upperlimit = n * n;
        if(n == 2){
            cout << -1 << endl;
            continue;
        }
        else if (n % 2)
        {
            for (int i = 0; i < upperlimit; i++)
            {
                int temp = i * 2;
                x = temp % n;
                y = temp / n;
                y %= n;
                arr[y][x] = i + 1;
            }
        }
        else
        {
            int k = 1, x1 = 0, y1 = 0, k1 = upperlimit + 1;
            for (int i = 0; i < upperlimit; i += 2)
            {
                int temp = upperlimit + 1 - i;
                x = i % n;
                y = i / n;
                x1 = temp % n;
                y1 = temp / n;
                arr[y1][x1] = k1--;
                arr[y][x] = k++;
            }
            if (n != 1)
            {
                arr[0][1] = k1--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        // cout << endl;
    }
}