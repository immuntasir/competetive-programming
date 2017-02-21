#include <bits/stdc++.h>
using namespace std;
int main () {
    int T, n, sum, q, a;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        sum = q = 0;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a);
            if (a<=0) {
                q++;
                a = -a;
            }
            sum += a;
        }
        q = n-q;
        if (q==0) printf("Case %d: inf\n", cs);
        else {
            int gc = __gcd(sum, q);
            printf("Case %d: %d/%d\n", cs, sum/gc, q/gc);
        }
    }
    return 0;
}
