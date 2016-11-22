#include <bits/stdc++.h>
using namespace std;
int ara[110];
int main() {
	// your code goes here
	int T;
	scanf("%d", &T);
	for (int cs=1; cs<=T; cs++) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		for (int i=0; i<n; i++) scanf("%d", &ara[i]);
		for (int i=0; i<n-1; i++) {
			int mn = ara[i];
			int idx = i;
			for (int j=i+1; j<n; j++) {
				if (ara[j] < mn) {
					mn = ara[j];
					idx = j;
				}
			}
			if (idx!=i) {
				ara[idx] = ara[i];
				ara[i] = mn;
				cnt++;
			}
		}
		printf("Case %d: %d\n", cs, cnt);
	}
	return 0;
}
