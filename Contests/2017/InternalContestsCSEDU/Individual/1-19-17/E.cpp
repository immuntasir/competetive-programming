#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
int ai[100010];
int bi[100010];
int ara[100010];
bool possible (int x) {
    for (int i=0; i<m; i++) {
        if (ai[i] <= x) {
            ara[i] = 1 + (x - ai[i]) / bi[i];
            //printf("%d %d %lld %lld\n", ai[i], bi[i], x,  ara[i]);
        }
        else ara[i] = 0;
    }
    sort(ara, ara+m);
    int cnt = 0;
    for (int i=m-1; i>m-1-n && i>= 0; i--) {
        cnt = cnt + ara[i];
       // printf("this %d %d %d %d\n", cnt, k, ara[i], x);
        if (cnt >= k) return true;
    }
    return false;
}
main () {
   //freopen("in.txt", "r", stdin);
    int T;
    scanf("%lld", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%lld %lld %lld", &m, &n, &k);
        for (int i=0; i<m; i++) {
            scanf("%lld", &ai[i]);
        }
        for (int i=0; i<m; i++) scanf("%lld", &bi[i]);
        //cout << possible(4) << " this " << endl;
        //for (int i=0; i<10; i++) cout << possible (i) << " <- " << i << endl;
        int high = 200000000000, low = 0, mid;
        int ans = high;
        while (high > low) {
            mid = (high+low)/2;
            bool flag = possible(mid);
//            printf("%d %d\n", mid, flag);
            if (flag) {
                if (mid < ans) ans = mid;
                high = mid;
            }
            else low = mid+1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
