#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int count = 0;
	int ac = 0;
	while (1) {
		over2:
		char A[5][5];
		int x = 0, y = 0,judge=0;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				char temp = getchar();
				if (temp == '\n') { --j; continue; }
				A[i][j] = temp;
				if (A[i][j] == 'Z') goto over;
			}
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (A[i][j] == ' ') {
					x = i; y = j;
					goto over3;
			}
				}
		}
		over3:
		//cout << x << " " << y << endl;
		string s;
		char a;
		while (1) {
			a = getchar();
			if (a == '0') break;
			if (a == '\n') continue;
			s.push_back(a);
		}
		//cout << s << endl;
		if (ac != 0)
			cout << endl;
		cout << "Puzzle #" << ++count << ":" << endl;
		for (int i = 0; i < s.size(); ++i) {
			switch (s[i])
			{
			case'A':swap(A[x][y], A[x - 1][y]); --x; break;
			case'B':swap(A[x][y], A[x + 1][y]); ++x; break;
			case'R':swap(A[x][y], A[x][y + 1]); ++y; break;
			case'L':swap(A[x][y], A[x][y - 1]); --y; break;
			default:
				break;
			}
			if (x > 4 || x < 0 || y>4 || y < 0) {
				cout << "This puzzle has no final configuration." << endl;
				goto over2;
			}
		}
		for (int i = 0; i < 5; i++) {
			int ju = 0;
			for (int j = 0; j < 5; j++) {
				if (ju != 0) cout << " ";
				cout << A[i][j];
				ju++;
			}
			cout << endl;
		}
		ac++;
	}
	over:
	return 0;
}