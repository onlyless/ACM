#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
	int n;
	LL A[51];
	A[1] = 1;
	A[2] = 2;
	for (int i = 3; i <= 50; ++i) {
		A[i] = A[i - 1] + A[i-2];
	}
	while (cin >> n) {
		cout << A[n] << endl;
	}
}