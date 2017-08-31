#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = 0;
	int *A = new int[n];
	int temp = n;
	while (n--) {
		cin >> A[a++];
	}
	int count = 0;
	for (int i = 0; i < temp; ++i) {
		if (A[i] == 0)
			count++;
	}
	if (temp == 1 && A[0] != 0) {
		cout << "YES" << endl;
	}
	else if (count == 1&&temp!=1) {
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}