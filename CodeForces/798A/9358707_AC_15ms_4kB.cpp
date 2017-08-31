#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	char s[15];
	while (scanf("%s", s) != EOF) {
		const int len = strlen(s);
		int count = 0;
		int i = 0;
		int j = len - 1;
		while (i <= len / 2&&j>=len /2 ) {
			if (s[i] != s[j]) {
				count++;
			}
			++i;
			--j;
		}
		if (count ==1) {
			printf("YES\n");
		}
		else if(count==0&&len%2!=0)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}