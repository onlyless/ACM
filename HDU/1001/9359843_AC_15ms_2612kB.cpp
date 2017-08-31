#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main()
{
	int N;
	while (cin >> N) {
		int temp = N;
		vector<int> ive;
		while (N--) {
			ive.push_back(temp);
			temp--;
		}
		cout << accumulate(ive.begin(), ive.end(), 0) << endl;
		if (N != 0)
			cout << endl;
	}
	return 0;
}