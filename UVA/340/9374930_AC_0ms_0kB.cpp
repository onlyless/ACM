#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int count = 0;
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		cout << "Game " << ++count <<":"<< endl;
		int *A = new int[n];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		while (1) {
			int x = 0,y = 0;
			int *B = new int[n];
			for (int i = 0; i < n; ++i)
				cin >> B[i];
			if (B[0]==0) break;
			for (int i = 0; i < n; i++) {
				if (B[i] == A[i]) {
					x++;
				}
			}
			for (int d = 1; d <= 9; d++) {
				int c1 = 0, c2 = 0;
				for (int i = 0; i < n; i++) {
					if (A[i] == d) c1++;        
					if (B[i] == d) c2++;
				}        
				if (c1 < c2) y += c1; 
				else y += c2;
				}
			printf("    (%d,%d)\n", x, y - x);
			delete[]B;
		}
		delete[]A;
	}
	return 0;
}