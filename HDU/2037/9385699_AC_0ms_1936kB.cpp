#include<iostream>
#include<algorithm>
using namespace std;
struct Time
{
	int Ti_s;
	int Ti_e;
	int Ti_t;
};
int main()
{
	while (1) {
		int N=0,re =0;
		cin >> N;
		int time = 0;
		if (N == 0) break;
		Time *A = new Time[N];
		for (int i = 0; i < N; ++i) {
			cin >> A[i].Ti_s >> A[i].Ti_e;
			A[i].Ti_t = A[i].Ti_e - A[i].Ti_s;
		}
		//cout << endl;
		sort(A, A + N, [](const Time& a, const Time& b) {return a.Ti_e < b.Ti_e; });
		//cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N-i; ++j) {
				if (A[i].Ti_e>=A[i+j].Ti_s&&time<=A[i].Ti_s) {
					re++;
					time = A[i].Ti_e;
				//	cout << A[i].Ti_s << " " << A[i].Ti_e << endl;
					break;
				}
			}
		}
		if (A[N - 1].Ti_s >= A[N - 2].Ti_e) re++;
		cout << re << endl;
		delete[]A;
	}
	return 0;
}