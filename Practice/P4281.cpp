#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 , w = 1 ;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e6 + 50;
int n,m;
int dep[MAXN],lg[MAXN],fa[MAXN][40];
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
void add(int x,int y){
	to[++ tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int u,int f){
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for(int i = 1 ; i <= lg[dep[u]] - 1 ; i ++){
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
	for(int i = lg[dep[x]] - 1 ; i >= 0 ; i --){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i] , y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	for(int i = 1 ; i < n ;  i++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read() , z = Read();
		int a = lca(x,y) , b = lca(x,z) , c = lca(y,z);
		int ans,cho;
		if(a == b) cho = c;
		else if(b == c) cho = a;
		else if(a == c) cho = b;
		ans = dep[x] + dep[y] + dep[z] - dep[a] - dep[b] - dep[c];
		printf("%d %d\n",cho,ans);
	}
	return 0;
}
