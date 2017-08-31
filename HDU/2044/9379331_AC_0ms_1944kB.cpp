#include<iostream>
using namespace std;
using LL =long long;

int main()
{
	int T;
	cin >> T;
	LL A[50];
	A[1]= 1;
	A[2]= 2;
	for (int i = 3; i <= 50; ++i) {
		A[i ] = A[i - 1] + A[i - 2];
	}
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << A[b - a] << endl;
	}
	return 0;
}