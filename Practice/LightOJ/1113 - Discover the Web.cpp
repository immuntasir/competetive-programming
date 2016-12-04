#include <bits/stdc++.h>
using namespace std;
stack <string> b;
stack <string> f;
string cur, tmp;
int main () {
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        printf("Case %d:\n", cs);
        cur = "http://www.lightoj.com/";
        while (!b.empty()) b.pop();
        while (!f.empty()) f.pop();
        while (1) {
            cin >> tmp;
            if (tmp == "QUIT") break;
            else if (tmp == "VISIT") {
                b.push(cur);
                cin >> cur;
                cout << cur << "\n";
                while (!f.empty()) f.pop();
            }
            else if (tmp == "BACK") {
                if (b.empty()) {
                    printf("Ignored\n");
                    continue;
                }
                f.push(cur);
                cur = b.top();
                b.pop();
                cout << cur << "\n";
            }
            else {
                if (f.empty()) {
                    printf("Ignored\n");
                    continue;
                }
                b.push(cur);
                cur = f.top();
                f.pop();
                cout << cur << "\n";
            }
        }
    }
    return 0;
}
