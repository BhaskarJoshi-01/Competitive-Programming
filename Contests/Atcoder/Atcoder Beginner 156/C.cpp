#include<iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, sum = 0, ans = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sum = round((double)(sum)/n);
	for (int i = 0; i < n; ++i)
		ans += (arr[i]-sum)*(arr[i]-sum);
	cout << ans << endl;
	return 0;
}