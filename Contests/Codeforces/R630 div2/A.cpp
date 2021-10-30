#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d, x, y, x1, x2, y1, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        ll fx = x - a + b;
        ll fy = y - c + d;
        if (fx <= x2 && fx >= x1 && fy <= y2 && fy >= y1 && x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            ll flag = 0;
            if (a != 0 || b != 0)
            {
                if (!(x + 1 <= x2 || x - 1 >= x1))
                    flag = 1;
            }
            if (c != 0 || d != 0)
            {
                if (!(y + 1 <= y2 || y - 1 >= y1))
                    flag = 1;
            }
            if (flag == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}