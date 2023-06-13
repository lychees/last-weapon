#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef double db;
const int N=2002;
const db inf=1e11,eps=1e-9;
int n,sx,sy,ex,ey,sb,eb;db V,ans;
int X1[N],X2[N],Y1[N],Y2[N],L[N],R[N];db f[N][2];
db getk(db xx1,db yy1,db xx2,db yy2) {return (yy2-yy1)/(xx2-xx1);}
db dist(db xx1,db yy1,db xx2,db yy2)
	{return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));}
void work() {
	if(sx==ex) {printf("%.8lf\n",dist(sx,sy,ex,ey)/V);return;}//起点终点横坐标相同
	for(RI i=1;i<=n;++i) f[i][0]=f[i][1]=inf;
	for(RI i=1;i<n;++i) L[i]=max(Y1[i],Y1[i+1]),R[i]=min(Y2[i],Y2[i+1]);
	db kl=-inf,kr=inf;ans=inf;
	for(RI i=sb;i<eb;++i) {
		if(i==sb&&sx==X2[i]) {//起点和第一个关键点横坐标相同
			f[i][0]=dist(sx,sy,X2[i],L[i]);
			f[i][1]=dist(sx,sy,X2[i],R[i]);
			if(sy<Y1[i]||sy>Y2[i]) {kl=inf,kr=-inf;break;}
		}
		db ll=getk(sx,sy,X2[i],L[i]),rr=getk(sx,sy,X2[i],R[i]);
		if(kl<ll+eps&&kr+eps>ll) f[i][0]=dist(sx,sy,X2[i],L[i]);
		if(kl<rr+eps&&kr+eps>rr) f[i][1]=dist(sx,sy,X2[i],R[i]);
		kl=max(kl,ll),kr=min(kr,rr);
	}
	db kk=getk(sx,sy,ex,ey);
	if(kl<kk+eps&&kr+eps>kk) ans=dist(sx,sy,ex,ey);
	for(RI i=sb;i<eb;++i) {
		db kl1=-inf,kr1=inf,kl2=-inf,kr2=inf;

		cout << "(" << X2[i] << ", " << " " << L[i] << "): " << f[i][0] << " " << endl;
		cout << "(" << X2[i] << ", " << " " << R[i] << "): " << f[i][1] << " " << endl;

		for(RI j=i+1;j<eb;++j) {
			db ll=getk(X2[i],L[i],X2[j],L[j]),rr=getk(X2[i],L[i],X2[j],R[j]);
			if(kl1<ll+eps&&kr1+eps>ll)
				f[j][0]=min(f[i][0]+dist(X2[i],L[i],X2[j],L[j]),f[j][0]);
			if(kl1<rr+eps&&kr1+eps>rr)
				f[j][1]=min(f[i][0]+dist(X2[i],L[i],X2[j],R[j]),f[j][1]);
			kl1=max(kl1,ll),kr1=min(kr1,rr);
			ll=getk(X2[i],R[i],X2[j],L[j]),rr=getk(X2[i],R[i],X2[j],R[j]);
			if(kl2<ll+eps&&kr2+eps>ll)
				f[j][0]=min(f[i][1]+dist(X2[i],R[i],X2[j],L[j]),f[j][0]);
			if(kl2<rr+eps&&kr2+eps>rr)
				f[j][1]=min(f[i][1]+dist(X2[i],R[i],X2[j],R[j]),f[j][1]);
			kl2=max(kl2,ll),kr2=min(kr2,rr);
		}
		if(i==eb-1&&ex==X1[eb]) {//终点和最后一个关键点横坐标相同
			if(ey<Y1[eb]||ey>Y2[eb]) continue;
			ans=min(ans,f[i][0]+dist(X2[i],L[i],ex,ey));
			ans=min(ans,f[i][1]+dist(X2[i],R[i],ex,ey));
			continue;
		}



		db ll=getk(X2[i],L[i],ex,ey),rr=getk(X2[i],R[i],ex,ey);
		if(kl1<ll+eps&&kr1+eps>ll)
			ans=min(ans,f[i][0]+dist(X2[i],L[i],ex,ey));
		if(kl2<rr+eps&&kr2+eps>ll)
			ans=min(ans,f[i][1]+dist(X2[i],R[i],ex,ey));
	}
	printf("%.8lf\n",ans/V);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

	scanf("%d",&n);
	for(RI i=1;i<=n;++i)
		scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	if(sx>ex) swap(sx,ex),swap(sy,ey);
	scanf("%lf",&V);
	sb=eb=1;
	for(RI i=n;i>=1;--i) {
		if(X1[i]<=sx&&X2[i]>=sx&&Y1[i]<=sy&&Y2[i]>=sy) sb=i;
		if(X1[i]<=ex&&X2[i]>=ex&&Y1[i]<=ey&&Y2[i]>=ey) eb=i;
	}
	work();
	return 0;
}
