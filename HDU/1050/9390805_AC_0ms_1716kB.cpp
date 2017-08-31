#include<iostream>
#include<algorithm>
using namespace std;
struct Room
{
	int a;
	int b;
};
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N=0;
		cin >> N;
		int re = 0;
		Room *A = new Room[N];
		int *B = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i].a >> A[i].b;
			B[i] = 0;
			if (A[i].a > A[i].b)
			swap(A[i].a, A[i].b);
			A[i].a = (A[i].a + 1) / 2;
			A[i].b = (A[i].b + 1) / 2;
		}
		sort(A, A + N, [](const Room& a, const Room& b) {return a.a < b.a;});
		while(1){
			int ans = -1;
			for (int j =  0; j < N; ++j) {
				if (A[j].a>ans&&!B[j]) {
					ans= A[j].b;
					B[j] = 1;
				}
			}
			if(ans!=-1)
			re++;
			else break;
		}
		cout << 10 * re << endl;
		delete[]A;
		delete[]B;
	}
	return 0;
}