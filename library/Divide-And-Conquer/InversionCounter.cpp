#include <bits/stdc++.h>
using namespace std;
int ara[200000];
int leftt[200000];
int rightt[200000];
int ans = 0;
int merge (int l, int mid, int r) {
    int i=0, j=0, x=0, inva = 0;
    for (x=l; x<=mid; x++) {
        leftt[i++] = ara[x];
    }
    for (; x<=r; x++) {
        rightt[j++] = ara[x];
    }
    int a, b;
    a = b = x = 0;
    x = l;
    while (a<i && b<j) {
        if (leftt[a] <= rightt[b]) {
            ara[x] = leftt[a];
            a++;
        }
        else {
            ara[x] = rightt[b];
            b++;
            inva += (i-a);
        }
        x++;
    }
    while (a < i) ara[x++] = leftt[a++];
    while (b < j) ara[x++] = rightt[b++];
    return inva;
}
int mergeSort (int l, int r) {
    int inv = 0;
    if (l < r) {
        int mid = l + (r-l)/2;
        inv = mergeSort(l, mid);
        inv += mergeSort(mid+1, r);
        inv += merge(l, mid, r);
    }
    return inv;
}
char str[100];
int cnt = 0;
map <string, int> M;
int main () {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs<=T; cs++) {
        int num;
        cnt = 0;
        M.clear();
        scanf("%d", &num);
        for (int i=0; i<num; i++) {
            scanf("%s", str);
            M[str] = ++cnt;
        }
        for (int i=0; i<num; i++) {
            scanf("%s", str);
            ara[i] = M[str];
        }
        printf("%d\n", mergeSort(0, cnt - 1));
    }
    return 0;
}
