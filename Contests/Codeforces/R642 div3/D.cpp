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
        ll n;
        cin >> n;
        ll size, l, r, a[n], ind;
        memset(a, 0, sizeof(a));
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.emplace(-1 * n, 0, n - 1);
        ll i = 1;
        while (!pq.empty())
        {
            tp x = pq.top();
            pq.pop();
            tie(size, l, r) = x;
            size *= -1;
            if (size % 2 == 0)
                ind = (l + r - 1) / 2;
            else
                ind = (l + r) / 2;
            a[ind] = i;
            i++;
            if (ind != l)
                pq.emplace(-1 * (ind - l), l, ind - 1);
            if (ind != r)
                pq.emplace(-1 * (r - ind), ind + 1, r);
        }
        for (ll i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}