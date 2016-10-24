#include<bits/stdc++.h>
using namespace std;
#define mx 18
int a[mx+3],n,m;
vector<int>divsr[mx];
int dp[1<<mx][mx];
int func(int mask, int pos)
{
    int i,j,r,mask2;
    if(pos>=n || m/a[pos]==0)
        return 0;
    else if(mask&(1<<pos))
        return func(mask,pos+1);
    else if(~dp[mask][pos])
        return dp[mask][pos];
    r=divsr[pos].size();
    dp[mask][pos]=m;
    for(i=0;i<r;i++){
        mask2=mask;
        for(j=pos;j<n;j++){
            if(a[j]%divsr[pos][i]==0){
                mask2=(mask2|(1<<j));
            }
        }
        dp[mask][pos]=min(dp[mask][pos], m/divsr[pos][i] + func(mask2,pos+1));
    }
    return dp[mask][pos];
}
int main()
{
    int t,cs=1,i,j,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<mx;i++){
            divsr[i].clear();
        }
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0;i<n;i++){
            r=sqrt(a[i]);
            for(j=1;j<=r;j++){
                if(a[i]%j==0){
                    divsr[i].push_back(j);
                    if(j!=a[i]/j)
                        divsr[i].push_back(a[i]/j);
                }
            }
            sort(divsr[i].begin(),divsr[i].end());

        }
        r=func(0,0);
        printf("Case %d: %d\n",cs++,r);
    }
    return 0;
}
