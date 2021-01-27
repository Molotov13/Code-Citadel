#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';	
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 3e6 + 50;
struct Edge{
	int u,v,val;
}s[MAXN];
int head[MAXN],nxt[MAXN << 1],dep[MAXN << 1],lg[MAXN << 1],fq[MAXN][50],cnt,to[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int u,int f){
	dep[u] = dep[f] + 1;
	fq[u][0] = f;
	for(int i = 1 ; i <= lg[dep[u]] ; i++){
		fq[u][i] = fq[fq[u][i - 1]][i - 1];
	}
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v != f){
			dfs(v,u);
		}
	}
}
int n,m,fa[MAXN];
bool cmp(Edge a,Edge b){
	return a.val > b.val;
}
int fid(int x){
	if(fa[x] != x){
		fa[x] = fid(fa[x]);
	}
	return fa[x];
}
void Kruskal(){
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	sort(s + 1,s + 1 + m,cmp);
	int k = 0;
	for(int i = 1 ; k < n - 1 && i <= m ; i ++){
		int f1 = fid(s[i].u) , f2 = fid(s[i].v);
		if(f1 != f2){
			fa[f1] = fa[f2] = fa[++cnt] = cnt;
			val[cnt] = s[i].val;
			//cout << s[i].u << " " << s[i].v << " (" << f1 << " , " << f2 << "):" << cnt << " " << val[cnt] << endl;
			add(cnt,f1) , add(f1,cnt);
			add(cnt,f2) , add(f2,cnt);
			k ++;
		}
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	while(dep[x] > dep[y]){
		x = fq[x][lg[dep[x] - dep[y]] - 1];
	}
	if(x == y) return x;
	for(int i = lg[dep[x] - 1] ; i >= 0 ; i --){
		if(fq[x][i] != fq[y][i]){
			x = fq[x][i] , y = fq[y][i];
		}
	}
	return fq[x][0];
}
int main(){
	n = Read() , m = Read();
	cnt = n;
	for(int i = 1 ; i <= n ; i ++){
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read() , z = Read();
		s[i].u = x;
		s[i].v = y;
		s[i].val = z;
	}
	Kruskal();
	dfs(cnt,0);
	int q = Read();
	for(int i = 1 ; i <= q ; i++){
		int u = Read() , v = Read();
		if(fid(u) != fid(v)){
			cout << -1 << endl;
			continue;
		}
		cout << val[lca(u,v)] << endl;
	}
	return 0;
}
