#include<algorithm>
#include<iostream>
#include<cmath>
#include<numeric>
using namespace std;
struct Thing
{
	int count;
	int value;
};
int main()
{
	while (1) {
		int a, b,n=0;
		int re = 0;
		cin >> a;
		if (a == 0) break;
		cin >> b;
		Thing *A = new Thing[b];
		while (b--) {
			cin >> A[n].value >> A[n].count;
			n++;
		}
		sort(A, A + n, [](const Thing& a, const Thing& b) {return a.value > b.value; });
		int i = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += A[i].count;
		}
		if (a < sum) {
			while (a > 0) {
				if (a > A[i].count)
					a -= A[i].count;
				else {
					re += a * A[i].value;
					break;
				}
				re += A[i].count*A[i].value;
				i++;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				re += A[i].count*A[i].value;
			}
		}
		cout << re << endl;
		delete[]A;
	}
	return 0;
}