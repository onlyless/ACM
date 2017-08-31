#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;
bool ispal(const int& temp)
{
	string s;
	stringstream stream;
	stream << temp;
	stream >> s;
	if (s.size() == 3)
		s.insert(0, "0");
	if (s.size() == 2) {
		s.insert(0, "00");
	}
	if (s.size() == 1) {
		s.insert(0, "000");
	}
	int i = 0, j = s.size() - 1;
	while (i <= s.size() / 2&&j>=s.size()/2 ) {
		if (s[i] != s[j])
			return false; 
		i++;
		j--;
	}
	return true;
}
int main()
{
	int HH, MM;
	int temp = 0,i =0,k = 0;
	scanf("%d:%d", &HH, &MM);
	while (1) {
		int hh = HH;
		temp = MM + i;
		int a = temp / 60;
		hh += a;
		temp -= a * 60;
		if (hh == 24) {
			hh = 0;
		}
		int time = hh * 100 + temp;
		//cout << time << endl;
		if (ispal(time)) {
			cout << i << endl;
			break;
		}
		i++;
	}
	return 0;
}