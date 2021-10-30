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

    char s[7];
    cin >> s;
    if (s[3] == s[2] && s[5] == s[4])
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}