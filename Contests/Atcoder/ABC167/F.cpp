#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

pr oc(char s[], ll n)
{
    stack<char> st;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else
            st.push(s[i]);
    }
    ll o = 0, c = 0;
    while (!st.empty())
    {
        if (st.top() == '(')
            c++;
        else
            o++;
    }
    return make_pair(o, c);
}

bool comp(const tp &a, const tp &b)
{
    return (get<1>(a) < get<1>(b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    char s[1000010];
    vector<tp> v;
    vector<tp> v2;
    for (ll i = 0; i < n; i++)
    {
        cin >> s;
        pr temp = oc(s, (ll)strlen(s));
        if (temp != make_pair((ll)0, (ll)0))
        {
            v.emplace_back(temp.first, temp.second, i);
            v2.emplace_back(temp.first, temp.second, i);
        }
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end(), comp);
    pr cur = {0, 0};
    int used[n];
    memset(used, 0, sizeof(used));
    ll j = 0;
    for (ll i = 0; i < (ll)v.size(); i++)
    {
        if (used[get<2>(v[i])] == 0)
        {
            used[get<2>(v[i])] = 1;
            cur.first += get<0>(v[i]);
            cur.second += get<1>(v[i]);
            while (used[get<2>(v2[j])] == 1)
                j++;
            if (j < (ll)v2.size())
            {
                if (cur.second > get<0>(v2[j]))
                    cur.second = cur.second - get<0>(v2[j]) + get<1>(v2[j]);
                else
                {
                    cur.first = cur.first + get<0>(v2[j]) - cur.second;
                    cur.second = get<1>(v2[i]);
                }
            }
        }
    }
    if (cur == make_pair((ll)0, (ll)0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}