#include<iostream>
#include<string>
using namespace std;
int num_size(int n)
{
	int count = 1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return count;
}
int main()
{
	int T;
	cin >> T;
	int *A = new int[T];
	for (int i = T-1; i >= 0; --i) {
		cin >> A[i];
	}
	while (T--) {
		int ju = 0;
		int x = num_size(A[T]);
		int *B = new int[x];
		for (int i =A[T]-100; i < A[T]; ++i) {
			int temp = i;
			int sum = 0;
			for (int j = 0; j < num_size(i); ++j) {
				B[j] = temp % 10;
				temp /= 10;
				sum += B[j];
			}
			if (A[T] == sum + i) {
				cout << i << endl;
				ju++;
				break;
			}
		}
		if (ju == 0)
			cout << "0" << endl;
		delete[]B;
	}
	delete[]A;
	return 0;
}