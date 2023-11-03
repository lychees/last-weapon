// LUOGU_RID: 131236374
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
int n,m,tot,trie[N][26];
string str[N];
struct node{
    int to[26],link,len,x,y;
    ll cnt;
}t[N];
void ins(int j,string &s){
    int it=0;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(!t[it].to[c])t[it].to[c]=++tot,t[tot].x=j,t[tot].y=i;
        it=t[it].to[c],t[it].cnt++;
    }
}
void extend(int cur,int p,int c){
    t[cur].len=t[p].len+1,p=t[p].link;
    while(p!=-1&&t[p].to[c]==0){
        t[p].to[c]=cur;
        p=t[p].link;
    }
    if(p!=-1){
        int q=t[p].to[c];
        if(t[q].len==t[p].len+1){
            t[cur].link=q;
        }
        else{
            int clone=++tot;
            for(int i=0;i<26;i++)t[clone].to[i]=t[t[q].to[i]].len?t[q].to[i]:0;
            t[clone].link=t[q].link,t[clone].len=t[p].len+1,t[clone].x=t[q].x,t[clone].y=t[q].y;
            while(p!=-1&&t[p].to[c]==q){
                t[p].to[c]=clone;
                p=t[p].link;
            }
            t[q].link=t[cur].link=clone;
        }
    }
}
queue<int>Q;
void build(){
    t[0].link=-1;
    for(int i=0;i<26;i++){
        if(t[0].to[i]){
            extend(t[0].to[i],0,i);
            Q.push(t[0].to[i]);
        }
    }
    while(Q.size()){
        int u=Q.front();Q.pop();
        for(int i=0;i<26;i++){
            if(t[u].to[i]){
                extend(t[u].to[i],u,i);
                Q.push(t[u].to[i]);
            }
        }
    }
}
vector<int>G[N];
int len;
bool cmp(int a,int b){
    return str[t[a].x][t[a].y-len]<str[t[b].x][t[b].y-len];
}
ll now,X[N];
vector<int>vec;
void dfs(int u){
    len=t[u].len,sort(G[u].begin(),G[u].end(),cmp);
    if(u)vec.pb(u);
    for(auto v:G[u])dfs(v),t[u].cnt+=t[v].cnt;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;for(int i=1;i<=n;i++)cin>>str[i],reverse(str[i].begin(),str[i].end()),ins(i,str[i]);
    build();for(int i=1;i<=tot;i++)G[t[i].link].pb(i);
    dfs(0);cin>>m;for(int i=1;i<=m;i++)cin>>X[i];
    int it=1;
    for(auto e:vec){
        now+=(t[e].len-t[t[e].link].len)*t[e].cnt;
        while(it<=m&&X[it]<=now){
            int cnt=(now-X[it])/t[e].cnt;
            int x=t[e].x,y=t[e].y,z=y-t[e].len+1+cnt;
            y=str[x].size()-y,z=str[x].size()-z;
            cout<<x<<" "<<y<<" "<<z<<"\n";
            it++;
        }
    }
}
