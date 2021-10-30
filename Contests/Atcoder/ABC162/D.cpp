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
    char s[n + 1];
    cin >> s;
    vector<int> r, g, b;
    int arr[n][3];
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            r.push_back(i);
        else if (s[i] == 'B')
            b.push_back(i);
        else
            g.push_back(i);
    }
    // arr[n - 1][0] = arr[n - 1][1] = arr[n - 1][2] = 0;
    // for (ll i = n - 2; i >= 0; i--)
    // {
    //     arr[i][0] = arr[i + 1][0];
    //     arr[i][1] = arr[i + 1][1];
    //     arr[i][2] = arr[i + 1][2];

    //     if (s[i + 1] == 'R')
    //         arr[i][0]++;
    //     else if (s[i + 1] == 'B')
    //         arr[i][2]++;
    //     else
    //         arr[i][1]++;
    // }
    ll total = 0, index, index2;
    for (ll i = 0; i < (ll)r.size(); i++)
    {
        index = lower_bound(g.begin(), g.end(), r[i]) - g.begin();
        for (ll j = index; j < (ll)g.size(); j++)
        {
            index2 = lower_bound(b.begin(), b.end(), g[j]) - b.begin();
            total += b.size() - index2;
            if (binary_search(b.begin(), b.end(), 2 * g[j] - r[i]))
                total--;
        }
    }
    for (ll i = 0; i < (ll)r.size(); i++)
    {
        index = lower_bound(b.begin(), b.end(), r[i]) - b.begin();
        for (ll j = index; j < (ll)b.size(); j++)
        {
            index2 = lower_bound(g.begin(), g.end(), b[j]) - g.begin();
            total += g.size() - index2;
            if (binary_search(g.begin(), g.end(), 2 * b[j] - r[i]))
                total--;
        }
    }
    for (ll i = 0; i < (ll)g.size(); i++)
    {
        index = lower_bound(b.begin(), b.end(), g[i]) - b.begin();
        for (ll j = index; j < (ll)b.size(); j++)
        {
            index2 = lower_bound(r.begin(), r.end(), b[j]) - r.begin();
            total += r.size() - index2;
            if (binary_search(r.begin(), r.end(), 2 * b[j] - g[i]))
                total--;
        }
    }
    for (ll i = 0; i < (ll)g.size(); i++)
    {
        index = lower_bound(r.begin(), r.end(), g[i]) - r.begin();
        for (ll j = index; j < (ll)r.size(); j++)
        {
            index2 = lower_bound(b.begin(), b.end(), r[j]) - b.begin();
            total += b.size() - index2;
            if (binary_search(b.begin(), b.end(), 2 * r[j] - g[i]))
                total--;
        }
    }
    for (ll i = 0; i < (ll)b.size(); i++)
    {
        index = lower_bound(r.begin(), r.end(), b[i]) - r.begin();
        for (ll j = index; j < (ll)r.size(); j++)
        {
            index2 = lower_bound(g.begin(), g.end(), r[j]) - g.begin();
            total += g.size() - index2;
            if (binary_search(g.begin(), g.end(), 2 * r[j] - b[i]))
                total--;
        }
    }
    for (ll i = 0; i < (ll)b.size(); i++)
    {
        index = lower_bound(g.begin(), g.end(), b[i]) - g.begin();
        for (ll j = index; j < (ll)g.size(); j++)
        {
            index2 = lower_bound(r.begin(), r.end(), g[j]) - r.begin();
            total += r.size() - index2;
            if (binary_search(r.begin(), r.end(), 2 * g[j] - b[i]))
                total--;
        }
    }
    cout << total << endl;
    return 0;
}