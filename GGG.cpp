#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000000+1;
int n,m,pnt,*P;
long long ans=0;
int S[maxn][10],D[maxn]= {};
void dfs(int p,int ch,int now)
{
    if(now>n)return;
    if(p==pnt)
    {
        if(ch&1)ans-=n/now;
        else ans+=n/now;
        return;
    }
    dfs(p+1,ch,now);
    dfs(p+1,ch+1,now*P[p]);
}

int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;
    n--;
    m--;
    if(m>n)swap(n,m);
    if(!n)
    {
        cout<<0<<endl;
        return 0;
    }
    if(!m)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1; i<=m; i++)
    {
        if(i==1)
        {
            ans+=n;
            continue;
        }
        int t=i,a;
        P=S[i];
        for(a=2; a*a<=t; a++) if(t%a==0)
            {
                while(t%a==0)
                {
                    t/=a;
                }
                break;
            }
        if(t==i)P[D[i]++]=t;
        else
        {
            D[i]=D[t]+1;
            memcpy(P,S[t],sizeof(S[t]));
            P[D[i]-1]=a;
        }
        pnt=D[i];
        dfs(0,0,1);
    }
    cout<<ans+2<<endl;
}
