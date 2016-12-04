#include <bits/stdc++.h>
using namespace std;
int main () {
    int T;
    scanf("%d", &T);
    string str;
    int x;
    for (int cs=1; cs<=T; cs++) {
        int n, m;
        printf("Case %d:\n", cs);
        vector <int> ara;
        scanf("%d %d", &n, &m);
        for (int i=0; i<m; i++) {
            cin >> str;
            if (str == "pushLeft") {
                cin >> x;
                if (ara.size() == n) printf("The queue is full\n");
                else {
                    ara.insert(ara.begin(), x);
                    printf("Pushed in left: %d\n", x);
                }
            }
            else if (str == "pushRight") {
                cin >> x;
                if (ara.size() == n) printf("The queue is full\n");
                else {
                    ara.insert(ara.end(), x);
                    printf("Pushed in right: %d\n", x);
                }
            }
            else if (str == "popLeft") {
                if (ara.size() == 0) printf("The queue is empty\n");
                else {
                    printf("Popped from left: %d\n", ara[0]);
                    ara.erase(ara.begin());
                }
            }
            else {
                if (ara.size() == 0) printf("The queue is empty\n");
                else {
                    printf("Popped from right: %d\n", ara[ara.size()-1]);
                    ara.erase(ara.begin() + ara.size() - 1);
                }
            }
        }
    }
    return 0;
}
