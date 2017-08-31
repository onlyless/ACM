#include<iostream>
#include<string>
using namespace std;
int main()
{
		string s;
		int x = 0;
		while (getline(cin,s)) {
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == '"'&&x == 0) {
					s.replace(i, 1, "`");
					s.insert(i, "`");
					x++;
				}
				if (s[i] == '"'&&x == 1) {
					s.replace(i, 1, "'");
					s.insert(i, "'");
					x = 0;
				}
			}
		cout << s << endl;
	}
	return 0;
}