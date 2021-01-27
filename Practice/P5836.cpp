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
const int MAXN = 1e5 + 50;
int n,m;
char s[MAXN];
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dep[MAXN],fa[MAXN][30],sum[MAXN][5],lg[MAXN];
bool co[MAXN];
void dfs(int x,int f){
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	sum[x][0] = !co[x] + sum[f][0];
	sum[x][1] = co[x] + sum[f][1];
	//cout << x << ":" << co[x] << " " << co[f] << " " << g[0][x][0] << " " << g[1][x][0] << endl;
	for(int i = 1 ; i <= lg[dep[x]] - 1 ; i ++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int i = head[x] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		dfs(v,x);
	}
}
int GetLca(int x,int y){
	if(dep[x] > dep[y]) swap(x,y);
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
	scanf("%s",s + 1);
	for(int i = 1 ; i <= n ; i ++) co[i] = (s[i] == 'H'); // H 1, G 0
	for(int i = 1 ; i < n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i ++) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs(1,0);
	//for(int i = 1 ; i <= n ; i ++){
	//	cout << co[i] << ":" << endl;
	//	for(int j = 0 ; j <= 30 ; j ++){
	//		cout << g[0][i][j] << " " << g[1][i][j] << endl;
	//	}
	//}
	for(int i = 1 ; i <= m ; i ++){
		int s = Read() , t = Read();
		char typ;
		cin >> typ;
		bool opt = (typ == 'H');
		int lca = GetLca(s,t);
		if((sum[s][opt] + sum[t][opt] - 2 * sum[fa[lca][0]][opt] > 0)){
			cout << 1;
		}
		else cout << 0;
	}
	return 0;
}

