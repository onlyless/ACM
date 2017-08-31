#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ive;
	int n = 0;
	int t, s, x;
	cin >> t >> s >> x;
	int a = 1, b = 0;
	while (1) {
		int a1 = t;
		int a2 = t + a*s;
		int a3 = t + a*s + 1;
		a++;
		if (a1 == x || a2 == x || a3 == x) {
			cout << "YES" << endl;
			n++;
			break;
		}
		if (a2 > x) break;
	}
	if (n == 0)
		cout << "NO" << endl;
	return 0;
}