#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

ll dfs(ll node, ll par, vector<ll> v[], ll value, ll dist[], ll br, ll branch[], ll parent[], ll nbelow[])
{
    dist[node] = value;
    branch[node] = br;
    parent[node] = par;
    ll below = 0;
    for (ll i = 0; i < (ll)v[node].size(); i++)
    {
        if (v[node][i] != par)
            below += 1 + dfs(v[node][i], node, v, value + 1, dist, br, branch, parent, nbelow);
    }
    nbelow[node] = below;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, a, b, c;
    cin >> n >> k;
    vector<ll> v[n + 1];
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll dist[n + 1], branch[n + 1], count = 0, par[n + 1], nodesbel[n + 1];

    priority_queue<tp, vector<tp>, less<tp>> pq;
    nodesbel[1] = dfs(1, -1, v, 0, dist, 0, branch, par, nodesbel);
    for (ll i = 1; i < n + 1; i++)
        pq.push(make_tuple(dist[i] - nodesbel[i], i, branch[i]));
    ll ans = 0;
    int used[n + 1];
    memset(used, 0, sizeof(used));
    while (count < k)
    {
        tp to = pq.top();
        pq.pop();
        ans += get<0>(to);
        count++;
    }
    cout << ans << endl;
    return 0;
}