#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	while (1) {
		string s1, s2;
		cin >> s1;
		if (s1 == "#")break;
		cin >> s2;
		int cnt = 0;
		for (size_t i = 0; i != s1.length();) {
			string s3(s1.begin() + i, s1.end());
			auto t = s3.find(s2);
			if (t != -1) {
				i += t;
				i += s2.length();
				cnt++;
			}
			else i++;
		}
		cout << cnt << endl;
	}
}