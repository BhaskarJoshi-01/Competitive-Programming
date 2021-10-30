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

    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v[n + 1];
    ll ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for (ll i = 1; i < n; i++)
    {
        v[i].push_back(i + 1);
        v[i + 1].push_back(i);
    }
    v[x].push_back(y);
    v[y].push_back(x);
    for (ll i = 1; i <= n; i++)
    {
        ll explored[n + 1];
        memset(explored, 0, sizeof(explored));
        queue<pr> q;
        q.push({i, 0});
        explored[i] = 1;
        while (!q.empty())
        {
            pr node = q.front();
            q.pop();
            ans[node.second]++;
            for (ll j = 0; j < (ll)v[node.first].size(); j++)
            {
                if (explored[v[node.first][j]] == 0)
                {
                    explored[v[node.first][j]] = 1;
                    q.push({v[node.first][j], node.second + 1});
                }
            }
        }
    }
    for (ll i = 1; i < n; i++)
        cout << ans[i] / 2 << endl;
    return 0;
}