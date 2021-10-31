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

    ll h, w, ans;
    cin >> h >> w;
    if((h * w) % 2 == 0)
        ans = (h*w)/2;
    else
    {
        ans = (h*w)/ 2 + 1;
    }
    if(h == 1 || w == 1)
        ans = 1;
    cout << ans << endl;
    return 0;
}