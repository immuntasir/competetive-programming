#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
int v[110][10010];
double dp[110][10010];
int ara[110];
double pro[110];
int T, n;
double p;
double func (int idx, int sum) {
    //printf("dp te %d %d\n", idx, sum);
    if (idx >= n && sum > 0) return INF;
    if (sum <= 0) return 0;
    if (v[idx][sum]) return dp[idx][sum];
    v[idx][sum] = 1;
   // printf("%d %d %d %lf: %lf %lf %lf\n", idx, sum, ara[idx], pro[idx], func(idx+1, sum), pro[idx] + (1.0-pro[idx]) * func(idx+1, sum-ara[idx]), min(func(idx+1, sum), pro[idx] + (1.0-pro[idx])*func(idx+1, sum-ara[idx])));
    return dp[idx][sum] = min(func(idx+1, sum), pro[idx] + (1.0-pro[idx])*func(idx+1, sum-ara[idx]));
}
int main () {
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%lf %d", &p, &n);
        int high=0, low=0, mid;
        for (int i=0; i<n; i++) {
            scanf("%d %lf", &ara[i], &pro[i]);
            high += ara[i];
        }
        int ans = 0;
        memset(v, 0, sizeof v);
        //printf("%lf\n", func(0, 201));
        while (low <= high) {
            mid = (low+high)/2;
            //printf("%d: %d %d %d %lf %lf\n", cs, low, high, mid, func(0, mid), p);
            if (func(0, mid) < p) {
                //printf("dhukchi %d: %d %d\n", mid, low, ans);
                if (mid>ans) ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}
