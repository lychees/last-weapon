#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,u,v,w,rt,T,_,mt[N],cnt[N],k,pv[N],mark[N];
ll ans;
vector<PII> e[N];
vector<array<ll,3>> dis;

void dfs(int u,int f,int br,ll d) {
	dis.pb({d,br,u});
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u,br==rt?v:br,d+p.se);
	}
}

void solve(int x) {
	rt=x;
	dis.clear();
	dfs(rt,0,rt,0);
	sort(all(dis)); reverse(all(dis));
	T++;
	ll tmp=0;
	int pt=0;
	for (auto x:dis) {
		if (mt[x[1]]!=T) mt[x[1]]=T,cnt[x[1]]=0;
		if (pt<k&&cnt[x[1]]<k/2) {
            pt++; cnt[x[1]]++; tmp+=x[0]; mark[x[2]]=T;
            if (pt == k) {
               if (tmp>ans) {
                    ans=tmp;
                    rep(i,1,n+1) pv[i]=(mark[i]==T);
                }
                return;
            }
		 }
	}
}

int q[N],f[N],vis[N],sz[N],ms[N];
int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j].fi;
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}

void gao(int u) {
	u=find(u);
	solve(u);
	T++;
	int maj=-1;
	rep(i,0,k) {
		auto x=dis[i];
	//	printf("dd %lld %lld %lld\n",x[0],x[1],x[2]);
		if (mt[x[1]]!=T) mt[x[1]]=T,cnt[x[1]]=0;
		cnt[x[1]]++;
		if (cnt[x[1]]>k/2) maj=x[1];
	}
	vis[u]=1;
	//fprintf(stderr,"%d %d\n",u,maj);
	if (maj!=-1&&!vis[maj]) gao(maj);
}

pair<ll,int> dfs(int u,int f) {
	int fv=pv[u];
	ll mdis=0;
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		auto z=dfs(v,u);
		if (z.se<k/2) z.fi+=p.se;
		fv+=z.se;
		mdis=max(mdis,z.fi);
	}
	if (pv[u]) mdis=-(1ll<<60);
	return mp(mdis,fv);
}

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) e[i].clear(),vis[i]=0;
	ans=0;
	for (int i=1;i<n;i++) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	/*
	if (k%2==1) {
		--k;
		gao(1);
		ans+=dfs(rt,0).fi;
	} else */
	gao(1);
	printf("%lld\n",2*ans);
}

int main() {
	for (scanf("%d",&_);_;_--) solve();
}
