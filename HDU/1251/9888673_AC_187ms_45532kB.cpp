#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 26;

struct Trie
{
	Trie* next[maxn];
	int cnt;
	Trie() {
		cnt = 0;
		for (int i = 0; i < maxn; i++)
			next[i] = NULL;
	}
};
Trie *root;
void createTrie(char *str)
{
	int len = strlen(str);
	Trie *p = root, *q;
	len--;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] == NULL) {
			q = new Trie();
			q->cnt = 1;
			p->next[id] = q;
			p = p->next[id];
		}
		else {
			p->next[id]->cnt++;
			p = p->next[id];
		}
	}
}
int findTrie(char *str)
{
	int len = strlen(str);
	Trie* p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] != NULL) {
			p = p->next[id];
		}
		else return 0;
	}
	return p->cnt;
}
void release(Trie *p)
{
	if (p == NULL)
		return;
	for (int i = 0; i < maxn; i++)
		if (p->next[i] != NULL)
			release(p->next[i]);
	delete p;
	root = NULL;
	return;
}
int main()
{
	char s[20];
	root = new Trie();
	while (fgets(s, 20, stdin) && strcmp(s, "\n") != 0) {
		createTrie(s);
	}
	while (scanf("%s", s) != EOF) {
		printf("%d\n", findTrie(s));
	}
	release(root);
	return 0;
}