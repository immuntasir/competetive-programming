// Supports character set {a - z}
// Don't forget to check the array limits
#include <bits/stdc++.h>
using namespace std;
#define MX 2500100
int sz = 0;
int ans = 0;
int nxt[MX][4];
char str[60];
bool created[MX];
int prefix[MX];
void initialize() {
    sz = 0;
    memset(nxt, 0, sizeof nxt);
    memset(created, 0, sizeof created);
    ans = 0;
}
void addWord(char *str) {
    int cur = 0;
    int i = 0;
    while (str[i] != '\0') {
        int ch = str[i] - 'a';
        if (!created[nxt[cur][ch]]) {
            nxt[cur][ch] = ++sz;
            prefix[nxt[cur][ch]] = 0;
            created[nxt[cur][ch]] = true;
        }
        prefix[cur]++;
        if (prefix[cur]*i > ans) ans = prefix[cur]*i;
        cur = nxt[cur][ch];
        i++;
    }
    prefix[cur]++;
    if (prefix[cur]*i > ans) ans = prefix[cur]*i;

}
bool search (char *str) {
    int cur = 0;
    int i = 0;
    while (str[i] != '\0') {
        int ch = str[i] - 'a';
        if (!created[nxt[cur][ch]]) {
            return false;
        }
        cur = nxt[cur][ch];
        i++;
    }
    return true;
}
int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        initialize();
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", str);
            addWord(str);
        }
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}
