#include<bits/stdc++.h>
#define RG register
#define R RG int
#define G if(++ip==iend)fread(ip=buf,1,N,stdin)
#define calc(i,j) a[j]+sq[i-j]//���㺯��ֵ
using namespace std;
const int N=5e5+9;
char buf[N],*iend=buf+N,*ip=iend-1;
int n,a[N],q[N],k[N];
double p[N],sq[N];
inline int in(){
    G;while(*ip<'-')G;
    R x=*ip&15;G;
    while(*ip>'-'){x*=10;x+=*ip&15;G;}
    return x;
}
inline void chkmx(RG double&x,RG double y){
    if(x<y)x=y;
}
inline int bound(R x,R y){//�����ٽ�ֵk
    R l=y,r=k[x]?k[x]:n,m,ret=r+1;//���ƶ������½�
    while(l<=r){
        m=(l+r)>>1;
        if(calc(m,x)<=calc(m,y))
            ret=m,r=m-1;
        else l=m+1;
    }
    return ret;
}
void work(){
    for(R h=1,t=0,i=1;i<=n;++i){
        while(h<t&&calc(k[t-1],q[t])<calc(k[t-1],i))--t;//ά��k����
        k[t]=bound(q[t],i);q[++t]=i;
        while(h<t&&k[h]<=i)++h;//���Ѿ����ŵľ��߳���
        chkmx(p[i],calc(i,q[h]));//��Ϊ����������ȡmax
    }
}
int main(){
    n=in();
    R i,j;
    for(i=1;i<=n;++i)
        a[i]=in(),sq[i]=sqrt(i);
    work();
    for(i=1,j=n;i<j;++i,--j)//���з�ת
        swap(a[i],a[j]),swap(p[i],p[j]);
    work();
    for(R i=n;i;--i)//��ת��������Ҫ�������
        printf("%d\n",max((int)ceil(p[i])-a[i],0));
    return 0;
}
