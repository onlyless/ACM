#include<iostream>
#include<algorithm>
using namespace std;
struct Stick
{
	int length;
	int weight;
};
int main()
{
	int T = 0;
	cin >> T;
	while (T--) {
		int N = 0;
		cin >> N;
		int re = 0,mix =0;
		int *ju = new int[N];
		Stick *A = new Stick[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i].length >> A[i].weight;
			ju[i] = 0;
		}
		sort(A, A + N, [](const Stick& a, const Stick& b) {
			if (a.length != b.length)
				return a.length > b.length;
			else 
				return a.weight > b.weight;
		});
		for (int i = 0; i < N; ++i) {
			if (ju[i]) continue;
			mix = A[i].weight;
			for (int j = i+1; j < N; ++j) {
				if (mix >= A[j].weight && !ju[j]) {
					mix = A[j].weight;
					ju[j] = 1;
				}
			}
			re++;
		}
		cout << re << endl;
	}
	return 0;
}