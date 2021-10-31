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

    ll a, b, c;
    cin >> a >> b >> c;
    if((4 * a * b) < (c-a-b)*(c-a-b))
    // if(sqrt(a) + sqrt(b) < sqrt(c))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}