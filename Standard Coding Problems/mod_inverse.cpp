// C++ program to find modular
// inverse of a under modulo m
#include <iostream>
using namespace std;

int modInverse(int a, int m)
{
	for (int x = 1; x < m; x++)
		if (((a%m) * (x%m)) % m == 1)
			return x;
}

// Driver code
int main()
{
	int a = 3, m = 11;

	// Function call
	cout << modInverse(a, m);
	return 0;
}
