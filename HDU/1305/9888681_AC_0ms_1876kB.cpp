#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int maxn = 10;
bool flag;
struct Trie
{
	Trie *next[maxn];
	int v;
	Trie() {
		v = 0;
		for (int i = 0; i < maxn; i++)
			next[i] = NULL;
	}
};
Trie* root;
void createTrie(char *str)
{
	int len = strlen(str);
	Trie *p = root, *q;
	for (int i = 0; i < len; i++) {
		int id = str[i] - '0';
		if (p->next[id] == NULL) {
			q = new Trie();
			q->v = 1;
			p->next[id] = q;
			p = p->next[id];
		}
		else {
			//p->next[id]->v++;
			p = p->next[id];
			if (p->v == -1) {
				flag = 1;
				break;
			}
		}
	}
	p->v = -1;
}
void release(Trie *p)
{
	if (p == NULL)
		return;
	for (int i = 0; i<maxn; i++)
		if (p->next[i] != NULL)
			release(p->next[i]);
	delete p;
	root = NULL;
	return;
}
int main()
{
	char s[10];
	root = new Trie();
	int cnt = 0;
	flag = 0;
	while (scanf("%s", s) != EOF) {
		if (s[0] != '9') {
			createTrie(s);
		}
		else {
			if (flag)
				printf("Set %d is not immediately decodable\n", ++cnt);
			else
				printf("Set %d is immediately decodable\n", ++cnt);
			release(root);
			root = new Trie();
			flag = 0;
		}
	}
	return 0;
}