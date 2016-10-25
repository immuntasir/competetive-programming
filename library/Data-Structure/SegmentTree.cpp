#include <bits/stdc++.h>
using namespace std;
typedef struct element{
    long long val, lazy;
    //constructors
    element(){}
    element(long long _val, long long _laz){
        val = _val;
        lazy = _laz;
    }
   // bool operator <(const element &a)const
    //{
      //  return path_cost < a.path_cost;
   // }

    bool operator >(const element &a)const {
        return val > a.val;
    }
} node;
long long ara[100010];
node tree[300010];

long long buildTree (long long idx, long long left, long long right) {
    if (left==right) {
        tree[idx] = element(ara[left], 0);
        return ara[left];
    }
    long long mid = (left+right)/2;
    long long v1, v2;
    v1 = buildTree(idx*2, left, mid);
    v2 = buildTree(idx*2+1, mid+1, right);
    tree[idx] = element(v1+v2, 0);
    return v1+v2;
}
void updateRange (long long idx, long long left, long long right, long long l, long long r, long long val) {
    if (tree[idx].lazy != 0) {
        tree[idx].val += (right-left + 1)*tree[idx].lazy;
        if (left != right) {
            tree[idx*2].lazy += tree[idx].lazy;
            tree[idx*2 + 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if (l>right || r < left || left > right) return;
    if (l<=left && r>=right) {
        tree[idx].val += (right-left + 1)*val;
        if (left!=right) {
                tree[idx*2].lazy += val;
                tree[idx*2 + 1].lazy += val;
        }
        return;
    }
    long long mid = (left+right)/2;
    updateRange(idx*2, left, mid, l, r, val);
    updateRange(idx*2+1, mid+1, right, l, r, val);
    tree[idx].val = tree[idx*2].val + tree[idx*2+1].val;
}
long long query (long long idx, long long left, long long right, long long l, long long r) {
    if (l>right || r < left || left > right) return 0;
    if (tree[idx].lazy != 0) {
        tree[idx].val += (right-left + 1)*tree[idx].lazy;
        if (left!=right) {
            tree[idx*2].lazy += tree[idx].lazy;
            tree[idx*2 + 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if (l<=left && r>=right) {
        return tree[idx].val;
    }
    long long mid = (left+right)/2;
    long long v1=0, v2=0;
    v1 = query(idx*2, left, mid, l, r);
    v2 = query(idx*2+1, mid+1, right, l, r);
    return v1+v2;
}
int main () {
    //freopen("in.txt", "r", stdin);
    long long T, x, a, b, c;
    scanf("%lld", &T);
    for (long long cs=1; cs<=T; cs++) {
        long long n, q;
        scanf("%lld %lld", &n, &q);
        memset(ara, 0, sizeof ara);
        //for (long long i=0; i<20; i++) ara[i] = i;
        buildTree(1, 1, n);
        printf("Case %lld:\n", cs);
        for (long long i=1; i<=q; i++) {
            scanf("%lld %lld %lld", &x, &a, &b);
            a++;
            b++;
            if (x==0) {
                scanf("%lld", &c);
                updateRange(1, 1, n, a, b, c);
               //for (long long i=0; i<20; i++) printf("%d ", tree[i].val);
                //printf("\n");

            }
            else {
                printf("%lld\n", query(1, 1, n, a, b));
            }
        }
    }
    return 0;
}
