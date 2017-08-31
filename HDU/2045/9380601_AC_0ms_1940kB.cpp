#include<iostream>
using namespace std;
using LL = long long;

int main()
{
	int n;
	LL A[51];
	A[1] = 3;
	A[2] = 6;
	A[3] = 6;
	for (int i = 4; i <= 50; ++i) {
		A[i] = A[i - 1] +2*A[i-2];
	}
	while (cin >> n) {
		cout << A[n] << endl;
	}
	return 0;
}