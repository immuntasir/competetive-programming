#include <bits/stdc++.h>
using namespace std;
int main () {
    long long int x1, x2, y1, y2, n, a, b, c, xx, yy, ans = 0;
    scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &n);
    for (int i=0; i<n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        xx = x1*a + y1*b + c;
        yy = x2*a + y2*b + c;
        if (xx > 0 && yy < 0) ans++;
        else if (xx < 0 && yy > 0) ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
