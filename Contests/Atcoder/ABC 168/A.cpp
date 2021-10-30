#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    if (n % 10 == 3)
        cout << "bon\n";
    else if (n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8)
        cout << "pon\n";
    else
        cout << "hon\n";
    return 0;
}