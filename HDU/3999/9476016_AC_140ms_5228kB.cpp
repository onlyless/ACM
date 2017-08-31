#include<iostream>
#include<cstdio>
using namespace std;
int A[100000];
int n;
struct Tree
{
	int v;
	Tree *left, *right;
	Tree() :v(0), left(NULL), right(NULL) {}
};
Tree* newTree() {
	return new Tree();
}
void addTree(Tree* root)
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	root->v = A[0];
	for (int i = 1; i < n; i++) {
		Tree* tem = root;
		while (1) {
			if (tem->v < A[i]) {
				if (tem->right == NULL) {
					tem->right = newTree();
					tem = tem->right;
					tem->v = A[i];
					break;
				}
				else
					tem = tem->right;
			}
			else {
				if (tem->left == NULL) {
					tem->left = newTree();
					tem = tem->left;
					tem->v = A[i];
					break;
				}
				else
					tem = tem->left;
			}
		}
	}
}
void print(Tree* u,int ju)
{
	if (u == NULL) return;
	ju ? printf(" ") : ju = 1;
	printf("%d", u->v);
	print(u->left,ju);
	print(u->right,ju);
}
void DeleteBiTree(Tree* u)
{
	if(u != NULL) {
		DeleteBiTree(u->left);
		DeleteBiTree(u->right);
		delete u;
		u = NULL;
	}
}
int main()
{
	while (scanf("%d", &n) != EOF) {
		Tree* root = new Tree();
		addTree(root);
		int ju = 0;
		print(root, ju);
		printf("\n");
		DeleteBiTree(root);
	}
	return 0;
}