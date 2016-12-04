#include <bits/stdc++.h>
using namespace std;
long long ara[100010];
int main () {
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        long long n;
        scanf("%lld %lld %lld %lld %lld %lld %lld ", &ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5], &n);
        for (int i=6; i<=n; i++) {
            ara[i] = ara[i-1]+ara[i-2]+ara[i-3]+ara[i-4]+ara[i-5]+ara[i-6];
            ara[i]  %= 10000007;
        }
        printf("Case %d: %lld\n", cs, ara[n]%10000007);
    }
    return 0;
}
