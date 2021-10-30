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

    ll n;
    cin >> n;
    ll flag = 0;
    while (n)
    {
        if (n % 10 == 7)
        {
            cout << "Yes\n";
            return 0;
        }
        n /= 10;
    }
    cout << "No\n";
    return 0;
}