#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	map<string, string> m;
	string s1;
	char s2[10];
	while (1) {
		char t;
		t = getchar();
		if (t == '\n')break;
		else {
			s1 += t;
			while (1) {
				t = getchar();
				if (t == ' ')
					break;
				else s1 += t;
			}
		}
		scanf("%s", s2);
		getchar();
		m[s2] = s1;
		s1.clear();
	}
	char word[10];
	while (scanf("%s", word) != EOF){
		if (m.find(word) != m.end()) {
			cout << m[word] << endl;
		}
		else printf("eh\n");
	}
	return 0;
}