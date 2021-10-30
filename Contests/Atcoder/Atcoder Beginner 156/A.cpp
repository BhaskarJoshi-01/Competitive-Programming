#include <iostream>
using namespace std;
int main()
{
	int n, r, ans;
	cin >> n >> r;
	if(n >= 10)
		ans  = r;
	else
		ans = r + 100 * (10 - n);
	cout << ans << endl;
	return 0;
}