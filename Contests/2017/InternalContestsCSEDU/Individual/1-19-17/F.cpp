#include <bits/stdc++.h>
using namespace std;
#define MX 2500100
int sz = 0;
bool visited[101000][110];
int nxt[MX][4];
bool created[MX];
int level[MX];
int ans[1010];
int word[MX];
vector <int> edge[1010];
vector <char> cost[1010];
void initialize () {
    sz = 0;
    memset(level, 0, sizeof level);
    memset(nxt, 0, sizeof nxt);
    memset(created, 0, sizeof created);
    memset(ans, 0, sizeof ans);
    memset(word, 0, sizeof word);
    memset(visited, 0, sizeof visited);
}
int id;

bool searchIt (string str) {
    int cur = 0;
    int i=0;
    //cout << str << " as" <<endl;
    while (str[i] != 0) {
        int ch;
        ch = str[i] - '0';
        if (!created[nxt[cur][ch]]) {
            return false;
        }
        cur = nxt[cur][ch];
        i++;
    }
    return true;
}
void dfs (int root, int node) {
    if (!visited[node][id]) {
        visited[node][id] = true;
        word[node]++;
    }
    for (int i=0; i<edge[root].size(); i++) {
        int ch;
        //cout << root << " -> " << str+cost[root][i] << endl;
        if (cost[root][i] == 'L') ch = 0;
        else ch = 1;
        if (!created[nxt[node][ch]]) {
            nxt[node][ch] = ++sz;
            created[nxt[node][ch]] = true;
            level[nxt[node][ch]] = level[node] + 1;
        }
        int cur = nxt[node][ch];
        dfs(edge[root][i], cur);
    }
    return ;
}
int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    assert(T<=5);
    for (int cs=1; cs<=T; cs++) {
        int m, n, a, b;
        char str[3];
        initialize();
        scanf("%d", &m);
        for (int i=0; i<m; i++) {
            id = i;
            scanf("%d", &n);
            for (int i=0; i<1010; i++) {
                edge[i].clear();
                cost[i].clear();
            }
            for (int i=0; i<n-1; i++) {
                scanf("%d %s %d", &a, str, &b);
                edge[a].push_back(b);
                cost[a].push_back(str[0]);
            }
            dfs(1, 0);
        }
        for (int i=1; i<=sz; i++) {
            //printf("%d %d\n", level[i], word[i]);
            ans[word[i]] = max(ans[word[i]], level[i]);
        }
        for (int i=m-1; i>=1; i--) ans[i] = max(ans[i], ans[i+1]);
        for (int i=1; i<m; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[m]);
    }
    return 0;
}
