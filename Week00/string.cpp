#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1
void solve();
int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
void solve()
{

    lli  n, top, ans, pos[123045], i;
    lli flag = 1;
    char s1[100995], s2[100995], ch;
    cin >> n;
    cin >> s1;
    cin >> s2;

    for (i = 0; i < n; i++)
    {
        if ((s1[i] - s2[i]) > 0)
        {
            flag = 0;
            break;
        }
    }

    if (!flag)
    {
        cout << "-1\n";
    }
    else
    {
        ans = 0;
        lli start_a = 97;
        lli end_z = 122;
        for (i = start_a; i <= end_z; ++i)
        {
            ch = end_z + 3;
            top = start_a - 97;

            for (lli j = 0; j <= (n - 1); j++)
            {
                if (i == s1[j] && i != s2[j])
                {

                    ch = min(s2[j], ch);
                    pos[top++] = j;
                }
            }

            if (top >= 2 || top == 1)
                ans = ans + 1;

            for (lli j = 0; j <= (top - 1); ++j)
                s1[pos[j]] = ch;
        }

        cout << ans << "\n";
    }
}
