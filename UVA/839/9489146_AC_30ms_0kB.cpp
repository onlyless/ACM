#include<iostream>
#include<cstdio>
using namespace std;

struct Tree
{
	int weight;
	int length;
	int re;
	Tree *left, *right;
	Tree() :weight(0),re(0), length(0), left(NULL), right(NULL) {}
	Tree(int a, int b) :weight(a),re(a*b), length(b), left(NULL), right(NULL) {}
};
Tree* newTree(int a, int b) { return new Tree(a, b); }
void addTree(Tree* root)
{
	int wl = 0, wr = 0, dl = 0, dr = 0;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	root->left = newTree(wl, dl);
	root->right = newTree(wr, dr);
	if (wl == 0) {
		addTree(root->left);
	}
	if (wr == 0) {
		addTree(root->right);
	}
}
bool failed;
int check(Tree* root)
{
	if (root->left->weight==0) {
		root->left->weight = check(root->left);
	}
	if (root->right->weight==0) {
		root->right->weight = check(root->right);
	}
	if (root->left->weight*root->left->length != root->right->weight*root->right->length)
		failed = true;
	return root->left->weight + root->right->weight;
}
void DeleteBiTree(Tree* u)
{
	if (u) {
		DeleteBiTree(u->left);
		DeleteBiTree(u->right);
		delete u;
		u = NULL;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		failed = false;
		Tree* root = new Tree;
		addTree(root);
		check(root);
		failed ? printf("NO\n") : printf("YES\n");
		if(n) printf("\n");
		DeleteBiTree(root);
	}
	return 0;
}