#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int len = s.size();
		string s2 = s + s;
		vector<string> sve;
		for (auto i =0; i !=len; i++) {
			string temp=s2.substr(i, len);
			sve.push_back(temp);
		}
		sort(sve.begin(), sve.end());
		cout << sve[0] << endl;
	}
	return 0;
}