#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Time
{
	long long ci;
	long long di;
};
int main()
{
	int T,num = 0;
	scanf("%d",&T);
	while (T--) {
		int n=0;
		scanf("%d", &n);
		Time *A = new Time[n];
		long long re = 0,ti=0,temp=0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld %lld", &A[i].ci, &A[i].di);
		}
		sort(A, A + n, [](const Time& a, const Time& b) {
			if (a.di != b.di)
				return a.di < b.di;
			else
				return a.ci < b.ci; });
		for (int i = 0; i < n; ++i) {
			ti += A[i].ci;
			if (re < ti - A[i].di)
				re = ti - A[i].di;
		}
		printf("Case %d: %lld\n", ++num, re);
		delete[]A;
	}
	return 0;
}