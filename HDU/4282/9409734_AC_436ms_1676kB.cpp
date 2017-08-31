#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

int main()
{
	while (1) {
		ll k=0;
		scanf("%lld", &k);
		if (k == 0) break;
		int count = 0;
		int temp = sqrt(k);
		if (temp*temp == k)
			count += (temp - 1) >> 1;
		for (int z = 3; z < 31; z++) {
			for (int x = 1; ; ++x) {
				ll a = pow(x, z);
				if (a > k / 2) break;
				for (int y = x + 1; ; ++y) {
					ll b = pow(y, z);
					if (a + b + x*y*z > k) break;
					else if (a + b + x*y*z == k) {
						//printf("%d %d %d\n", x, y, z);
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}