#include<iostream>
#include<cmath>
using namespace std;
using LL = long long;
int main()
{
	int n=0;
	LL A[41];
	A[1] = 3;
	A[2] = 8;
	for (int i = 3; i <= 40; ++i) {
		A[i] = 2 * (A[i - 1] + A[i - 2]);
	}
	while (cin >> n) {
		cout << A[n] << endl;
	}
	return 0;
}