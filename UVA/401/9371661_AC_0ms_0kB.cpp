#include<iostream>
#include<string>
using namespace std;
bool judge(const string& s)
{
	int ju = 0,ak=0;
	int i = 0;
	int j = s.size() - 1;
	while (i <= s.size() / 2 && j >= s.size() / 2) {
		if (s[i] != s[j]) {
			ju++;
			switch (s[i])
			{
			case'Z':if (s[j] == '5') ak++; break;
			case'2':if (s[j] == 'S') ak++; break;
			case'3':if (s[j] == 'E') ak++; break;
			case'5':if (s[j] == 'Z') ak++; break;
			case'S':if (s[j] == '2') ak++; break;
			case'E':if (s[j] == '3') ak++; break;
			case'L':if (s[j] == 'J') ak++; break;
			case'J':if (s[j] == 'L') ak++; break;
			default:
				break;
			}
		}
		i++;
		j--;
	}
	if (ju != ak)
		return false;
	return true;
}
bool ispal(const string& s)
{
	int i = 0, j = s.size() - 1;
	while (i <= s.size() / 2 && j >= s.size() / 2) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}
bool ismir_pal(const string& s)
{
	if (!ispal(s)) return false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' && s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'W' && s[i] != 'X' && s[i] != '8'&&s[i]!='Y')
			return false;
	}
	return true;

}
int main()
{
	string s;
	while(getline(cin, s)) {
		if (ispal(s)) {
			if (!ismir_pal(s))
				cout << s << " -- is a regular palindrome." <<"\n"<< endl;
			else
				cout << s << " -- is a mirrored palindrome."<<"\n" << endl;
		}
		else if (judge(s))
			cout << s << " -- is a mirrored string." <<"\n"<< endl;
		else
			cout << s << " -- is not a palindrome." <<"\n"<< endl;
	}
	return 0;
}