#include<iostream>
using namespace std;

int main()
{
	long long int n, k, c = 0;
	cin >> n >> k;
	if(n == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	while(n > 0)
	{
		n /= k;
		c++;
	}
	cout << c << endl;
	return 0;
}