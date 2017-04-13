// Problem Name: Sequence Analysis
// Problem Link: http://codeforces.com/gym/101252/problem/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long func (ll a, ll b, ll c, long long x) {
    return ((a*x)%c + (x%b)%c) % c;
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b, c;
    cin >> a >> b >> c;
    a = a % c;
    ll cnt = 0;
    ll x1 = 1; // This is the tortoise 
    ll x2 = 1; // This is the hare 
    while ((cnt == 0 || x1 != x2) && cnt <= 40000001) {
        x1 = func(a, b, c, x1); // x1 is moving only one step
        x2 = func(a, b, c, func(a, b, c, x2)); // x2 is stepping two steps at a time
        cnt++;
    }
    if (x1 != x2) {
        printf("-1\n"); // x1 and x2 has not met yet
        return 0;
    }
    cnt = 0;
    // we are moving the tortoise here to find the length of the cycle
    while (cnt == 0 || x1 != x2) {
        x1 = func(a, b, c, x1);
        cnt++;
    }
    // the tortoise had to go cnt steps. So the length = cnt
    ll lambda = cnt;
    // now we move the hare to f(0), and keep the tortoise at s+x
    // they move at the same speed
    x2 = 1;
    cnt = 0;
    while (x1 != x2) {
        x2 = func(a, b, c, x2);
        x1 = func(a, b, c, x1);
        cnt++;
    }
    // they meet again after cnt steps
    // so the starting point of the cycle = cnt
    ll miu = cnt;
    if (lambda + miu <= 20000000) cout << miu + lambda << "\n";
    else cout << "-1\n";
    return 0;
}
