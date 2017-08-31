#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--) {
		int T;
		while (cin >> T) {
			int temp = T;;
			vector<int> ive;
			int i = 0;
			while (T--) {
				int a;
				cin >> a;
				ive.push_back(a);
			}
			if (temp != 0)
				cout << accumulate(ive.begin(), ive.end(), 0) << endl;
		}
	}
	return 0;
}