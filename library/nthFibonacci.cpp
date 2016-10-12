// This will hopefully generate the nth fibonacci number modulo something
// n is a 32-bit integer
// the modulus value is 10^9 + 7

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void print(int ara[2][2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) printf("%d ", ara[i][j]);
        printf("\n");
    }
}
// This will add the two matrices and store the result in a1
void MatAdd (int a1[2][2], int a2[2][2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            a1[i][j] += a2[i][j];
            a1[i][j] %= MOD;
        }
    }
}
// this will multiply the two arrays and store the result in a1
void MatMultiply (int a1[2][2], int a2[2][2]) {
    long long ans[2][2];
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            ans[i][j] = 0;
            for (int k=0; k<2; k++) {
                ans[i][j] = ans[i][j] + ((long long)a1[i][k]%MOD*(long long)a2[k][j]%MOD) %MOD;
                ans[i][j]%=MOD;
            }
        }
    }
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            a1[i][j] = (int)ans[i][j];
}
// This function will raise the power of the input array to n
void MatExpo (int ara[2][2], int n) {
    int ret = n&1;
    int ans[2][2] = {{1, 0}, {0, 1}};
    while (n || ret) {
        n = n >> 1;
        if (ret) MatMultiply(ans, ara);
        MatMultiply(ara, ara);
        ret = n&1;
    }
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            ara[i][j] = ans[i][j];
}
// This function will calculate F(n) = F(n-1) + F(n-2) magically
int F(int n) {
    int ara[2][2] = {{0, 1}, {1, 1}};
    MatExpo(ara, n);
    return ara[1][1];
}
int main () {
    for (int i=2; i<10000; i++) {
        if (F(i) != (F(i-1)%MOD + F(i-2)%MOD) % MOD) printf("WRONG at %d\n", i);
    }
    return 0;
}
