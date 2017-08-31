#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char *A = new char[n];
	for (int i = 0; i < n; i += 4) {
		A[i] = 'a';
		if (n > 1)
			A[i + 1] = 'a';
		if (n > 2)
			A[i + 2] = 'b';
		if (n > 3)
			A[i + 3] = 'b';
	}
	for (int i = 0; i < n; ++i)
		cout << A[i];
	cout << endl;
	return 0;
}