#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
map <int, int> fro;
map <int, int> bac;
set <int> cards;
int main () {
    //freopen("in.txt", "r", stdin);
    int n, a, b, m;
    scanf("%d", &n);
    m = n;
    if (n%2 == 1) n = n/2 + 1;
    else n = n/2;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        fro[a]++;
        if (a != b)bac[b]++;
        cards.insert(a);
        cards.insert(b);
    }
    int ans = INF;
    set <int> :: iterator  it;
    for (it = cards.begin(); it!=cards.end(); it++) {
        if (fro[*it] >= n) {
            ans = 0;
            break;
        }
        if (fro[*it] + bac[*it] >= n) ans = min(ans, (n-fro[*it]));
    }
    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
