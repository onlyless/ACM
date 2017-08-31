#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	const int N = 1e9 + 7;
	int t = 0,a=0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == 'b')
			t = (t + 1) % N;
		else
		{
			a = (a + t) % N;
			t = (t * 2) % N;
		}
	}
	cout << a << endl;
	return 0;
}