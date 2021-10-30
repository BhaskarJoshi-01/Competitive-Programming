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

    ll n, m, a, b, node, dist, parent;
    cin >> n >> m;
    vector<ll> v[n + 1];
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll par[n + 1], vis[n + 1];
    fill(par, par + n + 1, infinity);
    fill(vis, vis + n + 1, 0);
    queue<tp> q;
    q.emplace(1, 0, -1);
    vis[1] = 1;
    while (!q.empty())
    {
        tp x = q.front();
        q.pop();
        tie(node, dist, parent) = x;
        if (par[node] == infinity)
            par[node] = parent;
        for (ll i = 0; i < (ll)v[node].size(); i++)
        {
            if (par[v[node][i]] == infinity && vis[v[node][i]] == 0)
            {
                q.emplace(v[node][i], dist + 1, node);
                vis[v[node][i]] = 1;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (par[i] == infinity)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (ll i = 2; i <= n; i++)
        cout << par[i] << endl;
    return 0;
}