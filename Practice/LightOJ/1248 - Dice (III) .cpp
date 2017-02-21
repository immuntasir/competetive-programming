#include <bits/stdc++.h>
using namespace std;
double func (double n) {
    double ret = 0;
    for (int i=1; i<=n; i++) ret += (n/i);
    return ret;
}
int main () {
    int T, n;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%d", &n);
        printf("Case %d: %.10lf\n", cs, func(n));
    }
    return 0;
}
