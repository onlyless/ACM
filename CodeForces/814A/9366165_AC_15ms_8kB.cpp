#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool not_sort(int A[],int n)
{
	for (int i = 0; i < n-1; ++i) {
		if (A[i] >= A[i + 1])
			return true;
	}
	return false;
}
int jie(int j)
{
	if (j == 1) return 1;
	return j*jie(j - 1);
}
int main()
{
	int n, k;
	cin >> n >> k;
	int *A = new int[n];
	int *B = new int[k];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < k; ++i) {
		cin >> B[i];
	}
	int j = 0, a = 0;
	int *C = new int[k];
	for (int i = 0; i < n; ++i) {
		if (A[i] == 0) {
			C[j++] = i;
			A[i] = B[a++];
		}
	}
	int jud = 0,ak = 0;
	vector<int> ive(B, B + k);
	while (1) {
		random_shuffle(ive.begin(), ive.end());
		for (int temp = 0; temp < ive.size(); ++temp)
			for (int i = 0; i < j; ++i) {
				A[C[i]] = ive[temp];
			}
		if (!not_sort(A, n)) {
			cout << "NO" << endl;
			jud++;
			break;
		}
		ak++;
		if (ak > jie(k))
			break;
	}
	if (jud == 0)
		cout << "YES" << endl;
	return 0;
}
