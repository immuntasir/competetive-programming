#include <bits/stdc++.h>
using namespace std;
int ara[500010];
int cnt[1000100];
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &ara[i]);
    int indiv = 0;
    int ansi, ansj, ans;
    ans = ansi = ansj = -1;
    int i=0;
    int j=0;
    while (i<n) {
        if (cnt[ara[j]] == 0) indiv++;
        cnt[ara[j]]++;
        if (indiv > k) {
            cnt[ara[i]]--;
            if (cnt[ara[i]] == 0) indiv--;
            i++;
        }
        if (j-i+1 > ans) {
            ans = j-i+1;
            ansi = i;
            ansj = j;
        }
        if (j<n-1) j++;
        else i = n;

    }
    printf("%d %d\n", ansi + 1, ansj + 1);
    return 0;
}
