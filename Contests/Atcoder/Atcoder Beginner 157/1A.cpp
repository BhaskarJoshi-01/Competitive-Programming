#include <bits/stdc++.h>
#define pr pair<long long int, long long int>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    long long int n;
    cin >> n;
    if(n % 2 == 0)
        cout << n / 2 << endl;
    else
        cout << (n + 1) / 2 << endl;
    return 0;
}