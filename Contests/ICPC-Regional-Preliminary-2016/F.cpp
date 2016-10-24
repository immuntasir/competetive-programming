#include <bits/stdc++.h>
using namespace std;
#define golt 2*i,s,mid
#define gort 2*i+1,mid+1,e
#define l 2*i
#define r 2*i+1
struct node
{
    int mn,lazy;
};
struct node tr[400005],tmp;
int ar[400005];
node gmerge(node a,node b)
{
    if(a.mn>b.mn)return b;
    else return a;
}
void init(int i,int s,int e)
{
    if(s==e){
        tr[i].mn = ar[s];
        tr[i].lazy = 0;
        return;
    }
    int mid = (s+e)/2;
    init(golt);
    init(gort);
    tr[i] = gmerge(tr[l],tr[r]);
}
void update(int i,int s,int e,int a,int b,int v)
{
    if(s>=a && e<=b)
    {
        if(tr[i].mn<v)
        {
            tr[i].mn = v;
            tr[i].lazy = v;

        }
        return;
    }
    else if(s>b||e<a)return;
    else
    {
   if(tr[i].lazy!=0)
    {
        int mid = (s+e)/2;
        update(golt,s,mid,tr[i].lazy);
        update(gort,mid+1,e,tr[i].lazy);
        tr[i].lazy = 0;
    }



        int mid =(s+e)/2;
        update(golt,a,b,v);
        update(gort,a,b,v);
        tr[i] = gmerge(tr[l], tr[r]);
//put a gmerge here
    }
}
node query(int i,int s,int e,int a,int b)
{
    if(a<=s && b>=e)return tr[i];
    else if(b<s||a>e)
    {
        tmp.mn=1000000009;
        return tmp;
    }
    if(tr[i].lazy!=0)
    {
        int mid = (s+e)/2;
        update(golt,s,mid,tr[i].lazy);
        update(gort,mid+1,e,tr[i].lazy);
        tr[i].lazy = 0;
    }
    int mid = (s+e)/2;
    node aa = query(golt,a,b);
    node bb = query(gort,a,b);
    return gmerge(aa,bb);
}
main()
{
    int n,q,a,b,t,tc,c;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            ar[i]=-1;
        }
        init(1,1,n);
        printf("Case %d: ",t);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            update(1,1,n,a,b,c);
        }
        for(int i=1;i<n;i++)
        {
            struct node answer = query(1,1,n,i,i);
            if(answer.mn>0)printf("%d ",answer.mn);
            else printf("1000 ");

        }
        struct node answer = query(1,1,n,n,n);
        if(answer.mn>0)printf("%d\n",answer.mn);
        else printf("1000\n");

    }
    return 0;
}
