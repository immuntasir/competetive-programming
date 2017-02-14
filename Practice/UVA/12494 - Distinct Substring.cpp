#include <bits/stdc++.h>
using namespace std;
#define int long long
char str[500];
map <string, bool> M;
char S[500];
#define MOD 1000000007
#define MOD2 1000000009
int hash1[500];
int hash2[500];
#define HASH 30
string convert (string s1) {
int len = s1.length();
    int mn = 0;
    int cur = 1;
    int mndex = 0;
    int pcur = 1;
    hash1[0] = hash2[0] = 0;
    for (int i=0; i<len; i++) {
        S[i] = s1[i];
        hash1[0] = hash1[0] + ((cur%MOD)*(S[i] - 'a'))%MOD;
        hash1[0] %= MOD;

        hash2[0] = hash2[0] + ((cur%MOD2)*(S[i] - 'a'))%MOD2;
        hash2[0] %= MOD2;

        pcur = cur;
        cur *= HASH;
        cur %= MOD;
    }

    for (int i=len; i<len*2; i++) S[i] = S[i-len];
    S[len*2] = 0;
    cur = pcur;
    int chash1 = hash1[0];
    int chash2 = hash2[0];
    for (int i=len-1; i>0; i--) {
       // printf("%s deleted\n", S+i);

        hash1[i] = chash1 - ((cur%MOD)*(S[i] - 'a'))%MOD + MOD;
        hash2[i] = chash2 - ((cur%MOD2)*(S[i]-'a'))%MOD2 + MOD2;
        hash1[i] *= HASH;
        hash1[i] %= MOD;

        hash2[i] *= HASH;
        hash2[i] %= MOD2;

        hash1[i] = hash1[i] + ((S[i] - 'a'))%MOD;
        hash2[i] = hash2[i] + ((S[i] - 'a'))%MOD2;

        hash1[i] %= MOD;
        hash2[i] %= MOD2;

        chash1 = hash1[i];
        chash2 = hash2[i];
        if (hash1[i] == hash1[mndex]) {
            if (hash2[i] < hash2[mndex]) {
                mndex = i;
            }
        }
        if (hash1[i] < hash1[mndex]) {
            mndex = i;
        }
    }
    S[mndex+len] = 0;
    //printf("%s\n", S+mndex);
    return S+mndex;
}
void turnTrue (string s1) {
    M[s1] = true;
}
string s;
 main(){
    //freopen("in.txt", "r", stdin);
//    cout  << convert("abcd") << endl;
//    cout  << convert("bcda") << endl;
//    cout  << convert("cdab") << endl;
//    cout  << convert("dabc") << endl;
    int T;
    scanf("%lld",&T);
    for (int cs=1;cs<=T;cs++) {
        scanf("%s",str);
        int ans=0;
        M.clear();
        int len = strlen(str);
        for (int i=0; i<len; i++) {
            s.clear();
            for (int j=i; j<len; j++) {
                s.push_back(str[j]);
               // cout << "Looking for " << s << " " << convert(s) << " " << M[convert(s)] ;
                if (M.find(convert(s)) == M.end()) {
                 //   cout << " here ";
                    ans++;
                    turnTrue(convert(s));
                }
               // cout << endl;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
