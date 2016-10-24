#include<bits/stdc++.h>
using namespace std;
long long int m,k;
long long int dp[100009];
long long int func(long long int n)
{
    if(n==0ll)
        return 1;
    else if(n==1ll)
        return (k)%m;
    else if(dp[n] != -1)
        return dp[n];
    else return dp[n]=(((func(n-1))%m)*(func(n-2))%m)%m;
}
int main()
{
    int t,i,cs=1;
    long long int n,res;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&k,&m);
        //printf("%lld %lld %lld\n", n, k, m);
        res=1;
        memset(dp,-1,sizeof(dp));
        res=func(n+2);
        //printf("%lld %lld %lld\n", n, k, m);
        printf("Case %d: %lld\n",cs++,(res)%m);
    }
    return 0;
}
