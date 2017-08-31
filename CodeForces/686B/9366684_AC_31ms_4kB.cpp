#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int A[120];
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = n; i >= 1; i--){
		for (int j = 1; j<i; j++){
			if (A[j]>A[j + 1]){
				swap(A[j], A[j + 1]);
				cout << j << " " << j + 1 << endl;
			}
		}
	}
	return 0;
}