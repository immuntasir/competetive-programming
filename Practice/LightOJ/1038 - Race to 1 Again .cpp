#include <bits/stdc++.h>
using namespace std;
#define MX 100010
int isPrime[MX];
vector <int> divi[MX];
void sieve () {
    int sqr = sqrt(MX);
    for (int i=2; i<MX; i++) divi[i].push_back(i);
    isPrime[0] = isPrime[1] = 1;
    for (int i=2+2; i<MX; i+=2) {
        isPrime[i] = 1;
        divi[i].push_back(2);
    }
    for (int i=3; i<sqr; i+=2) {
        if (!isPrime[i]) {
            for (int j=i+i; j<MX; j+=i) isPrime[i] = 1;
        }
    }
    for (int i=3; i<MX; i++) {
        for (int j=i+i; j<MX; j+=i) {
            divi[j].push_back(i);
        }
    }
}
int v[MX];
double dp[MX];
double func (int n) {
    if (n==1) return 0;
    if (v[n]) return dp[n];
    v[n] = 1;
    int sz = divi[n].size();
    double a = 0;
    for (int i=0; i<sz; i++) {
        a += (1+func(n/divi[n][i]));
    }
    a = a/(sz);
    a = a + (1.0/(double)sz);
    dp[n] = a;
}
int main () {
    sieve();
    int T, n;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%d", &n);
        printf("Case %d: %.10lf\n", cs, func(n));
    }
    return 0;
}
