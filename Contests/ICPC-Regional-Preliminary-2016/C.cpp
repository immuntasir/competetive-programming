#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
char str[510][510];
int ara[510][510][30];
int cur[30];
int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        int n, m, kost;
        scanf("%d %d %d", &n, &m, &kost);

        for (int i=1; i<=n; i++) {
            scanf("%s", &str[i]);
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<30; j++)
                ara[0][i][j] = INF;
        }
        long long ans = 0;
        for (int i=1; i<=n; i++) {
            //printf("%s\n", str[i]);
            for (int j=0; j<m; j++) {
                for (int k=0; k<27; k++) {
                    int tmp;
                    if (i==1) {
                        if (j>0) tmp = ara[i][j-1][k];
                        else tmp = INF;
                    }
                    else {
                        if (j>0) tmp = min(ara[i-1][j][k], ara[i][j-1][k]);
                        else tmp = ara[i-1][j][k];
                    }
                    if (tmp < INF) tmp++;
                    if (i==1 && j==4 && k==1) {
                        //printf("%d %d\n", ara[i-1][j][k], ara[i][j-1][k]);
                    }
                    ara[i][j][k] = tmp;
                }
                //printf("%d %d %c %d\n", i, j, str[i][j], ara[i][j][str[i][j]-'a']);
                if (ara[i][j][str[i][j] - 'a'] >= INF) ans = ans + kost;
                else ans = ans + min(kost, ara[i][j][str[i][j] - 'a']);
                ara[i][j][str[i][j] - 'a'] = 0;
            }
            for (int j=m-2; j>=0; j--) {
                for (int k=0; k<27; k++) {
                    ara[i][j][k] = min(ara[i][j][k], ara[i][j+1][k] + 1);
                }
            }
        }
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}
