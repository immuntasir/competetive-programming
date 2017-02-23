#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int T, n, m, l, o;
int v[16][16][16][16][5][5];
double dp[16][16][16][16][5][5];
double minn (double a, double b, double c, double d) {
    return min(a, min(b, min(c, d)));
}
double dpp (int a, int b, int c, int d, int e, int f)
{
    int ara[5];
    ara[1] = a;
    ara[2] = b;
    ara[3] = c;
    ara[4] = d;
    ara[e]++;
    ara[f]++;
    if (n<=ara[1]&& m<=ara[2] && l<=ara[3] && o<=ara[4]) return 0;
    if (v[a][b][c][d][e][f]) return dp[a][b][c][d][e][f];
    v[a][b][c][d][e][f] = 1;
    int cnt = 0;
    dp[a][b][c][d][e][f] = 1;
    int ct = 0;
    if (e) ct++;
    if (f) ct++;
    if (a<13)
    {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] + ((dpp(a+1, b, c, d, e, f)) * ( (double)(13-a) / (double)(54 - a-b-c-d-ct)));
        cnt++;
    }
    if (b<13)
    {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] + ((dpp(a, b+1, c, d, e, f)) * ( (double)(13-b) / (double)(54 - a-b-c-d-ct)));
        cnt++;
    }
    if (c<13)
    {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] + ((dpp(a, b, c+1, d, e, f)) * ( (double)(13-c) / (double)(54 - a-b-c-d-ct)));
        cnt++;
    }
    if (d<13)
    {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] + ((dpp(a, b, c, d+1, e, f)) * ( (double)(13-d) / (double)(54 - a-b-c-d-ct)));
        cnt++;
    }
    if (!e) {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] +
                            ( (double) 1.0 / (double)(54 - a-b-c-d-ct)) *
                            minn ((dpp(a, b, c, d, 1, f)), (dpp(a, b, c, d, 2, f)), (dpp(a, b, c, d, 3, f)), (dpp(a, b, c, d, 4, f)));
        cnt++;
    }
    if (!f) {
        dp[a][b][c][d][e][f] = dp[a][b][c][d][e][f] +
                            ( (double) 1.0 / (double)(54 - a-b-c-d-ct)) *
                            minn ((dpp(a, b, c, d, e, 1)), (dpp(a, b, c, d, e, 2)), (dpp(a, b, c, d, e, 3)), (dpp(a, b, c, d, e, 4)));
        cnt++;
    }
//if (cnt==0) printf("%d %d %d %d %d %lf\n", a, b, c, d, e, dp[a][b][c][d][e]);
    if (cnt == 0) return dp[a][b][c][d][e][f] = INF;
//dp[a][b][c][d][e] /= cnt;
    return dp[a][b][c][d][e][f];
}
int main ()
{
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++)
    {
        scanf("%d %d %d %d", &n, &m, &l, &o);
        memset(v, 0, sizeof v);
        if (n>15 || m>15 || l>15 || o>15 || n+m+l+o > 54) printf("Case %d: -1\n", cs);
        else if (dpp(0, 0, 0, 0, 0, 0) > 54.000000001) printf("Case %d: -1\n", cs);
        else printf("Case %d: %.10lf\n", cs, dpp(0, 0, 0, 0, 0, 0));
    }
    return 0;
}
