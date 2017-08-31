#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	map<string, string> m;
	char s1[10],s2[10];
	char temp[10];
	string str;
	while (scanf("%s",s1)) {
		if (s1[0] == 'S')
			scanf("%s", s1);
		if (s1[0] == 'E')
			break;
		scanf("%s", s2);
		m[s2] = s1;
	}
	scanf("%s", temp);
	getchar();
	char ch=' ';
	while (scanf("%c",&ch)) {
		if (isalpha(ch))
			str += ch;
		else {
			if (str[0] == 'E')break;
			if (m.find(str) != m.end())
				cout << m[str];
			else cout << str;
			printf("%c", ch);
			str.clear();
		}
	}
	return 0;
}