#include <bits/stdc++.h>
#define int long long
#define int long long
using namespace std;
int dp[600][60];
int func (int run, int ball) {
    if (run < 0) return 1;
    if (ball == 0) return 0;
    if (dp[run][ball]!=-1)return dp[run][ball];
    int ans = 0;
    for(int i = 0;i<=6;i++)
    {
        ans+= func(run-i,ball-1);
    }
    return dp[run][ball] = ans;
}
main () {
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, n, k, m;
    memset(dp,-1,sizeof(dp));
    scanf("%lld", &T);
    for (int i=0; i<T; i++) {
        scanf("%lld %lld %lld", &n, &k, &m);
        printf("%lld\n", func(n-k, m));
    }
    return 0;
}
