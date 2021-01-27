#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || '0' > ch){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while('9' >= ch && ch >= '0'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e4 + 50;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot,n;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dep[MAXN],fa[MAXN][40],lg[MAXN << 1],blg[MAXN];
void dfs(int u,int f){
	dep[u] = dep[f] + 1;
	blg[dep[u]] ++;
	fa[u][0] = f;
	for(int i = 1 ; i <= lg[dep[u]] - 1; i ++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v != f){
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	while(dep[x] > dep[y]){
		x = fa[x][lg[dep[x] - dep[y]] - 1];
	}
	if(x == y) return x;
	for(int i = lg[dep[x] - 1] ; i >= 0 ; i --){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	for(int i = 1 ; i < n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	int u = Read() , v = Read();
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++ ) ans = max(dep[i],ans);
	cout << ans << endl;
	ans = 1;
	for(int i = 1 ; i <= n ; i ++ ) ans = max(blg[i],ans); 
	cout << ans << endl; 
	cout << 2 * (dep[u] - dep[lca(u,v)]) + (dep[v] - dep[lca(u,v)]) << endl; 
	return 0;
}
