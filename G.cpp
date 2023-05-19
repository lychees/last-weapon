#include <lastweapon/io>
using namespace lastweapon;
typedef long long ll;
#define chkmin checkMin
#define pb PB
#define find Find



const int MAXN=5e6;
int n,m,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],val[MAXN+5],ec=1;
vector<int>g[MAXN+5];

int typ[MAXN+5];

LL res;


void adde(int u,int v,int w){
	to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;val[ec]=w;nxt[ec]=hd[v];hd[v]=ec;
}
int dfn[MAXN+5],low[MAXN+5],tim=0,stk[MAXN+5],tp=0;
int e_stk[MAXN+5],e_top,ncnt,in[MAXN+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;stk[++tp]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]){
			e_stk[++e_top]=e>>1;in[e>>1]=1;
			tarjan(y);chkmin(low[x],low[y]);
			if(low[y]>=dfn[x]){
				vector<int>V,E;
				int o;++ncnt;
				do{o=stk[tp--];V.pb(o);}while(o^y);V.pb(x);
				do{o=e_stk[e_top--];in[o]=0;E.pb(o);}while(o^(e>>1));
				static int msk[MAXN+5];
				for(int z:V)g[ncnt].pb(z),g[z].pb(ncnt),msk[z]=0;
				int totmsk=0,sum=0;
				for(int z:E){
					totmsk|=(1<<val[z<<1]);
					msk[to[z<<1]]|=(1<<val[z<<1]);
					msk[to[z<<1|1]]|=(1<<val[z<<1]);
				}
				typ[ncnt]=totmsk-1;
				for(int z:V)sum+=(msk[z]==3);
				//if(sum==2)res--;
			}
		}else{
			chkmin(low[x],dfn[y]);
			if(dfn[y]<dfn[x]&&!in[e>>1])e_stk[++e_top]=e>>1;
		}
	}
}
int f[MAXN+5],siz[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);f[x]=y;siz[y]+=siz[x];}
int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif


	scanf("%*d%d%d",&n,&m);res=1ll*n*(n-1)/2;
	for(int i=1,u,v;i<=m;i++){
		static char buf[6];scanf("%d%d%s",&u,&v,buf+1);
		adde(u,v,buf[1]=='D');adde(v,u,buf[1]=='D');
	}ncnt=n;tarjan(1);
	for(int i=1;i<=n;i++)siz[i]=1;
	for(int i=n+1;i<=ncnt;i++)if(typ[i]==0)for(int y:g[i])merge(i,y);
	//for(int i=1;i<=ncnt;i++)if(find(i)==i)res-=1ll*siz[i]*(siz[i]-1)/2;
	memset(f,0,sizeof(f));memset(siz,0,sizeof(siz));
	for(int i=1;i<=n;i++)siz[i]=1;
	for(int i=n+1;i<=ncnt;i++)if(typ[i]==1)for(int y:g[i])merge(i,y);
	//for(int i=1;i<=ncnt;i++)if(find(i)==i)res-=1ll*siz[i]*(siz[i]-1)/2;
	printf("%lld\n",res);
	return 0;
}
