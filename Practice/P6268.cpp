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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 10000;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],match[MAXN],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool co[MAXN],vis[MAXN];
int dfs(int u){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(vis[v]) continue;
		vis[v] = true;
		co[v] = co[u] ^ 1;
		dfs(v);
	}
}
int dfs2(int u){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(vis[v]) continue;
		vis[v] = true;
		if(!match[v] || dfs2(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}
int n,m,ans;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int u = 1 + Read() , v = 1 + Read();
		add(u,v);
		add(v,u);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[i]){
			vis[i] = true;
			co[i] = 1;
			dfs(i);
		}	
	}
	for(int i = 1 ; i <= n ; i ++){
		if(co[i]){
			memset(vis,false,sizeof(vis));
			ans += dfs2(i);
			//cout << ans << endl;
		}
	}
	cout << n - ans << endl;
	return 0;
}
/*
8 6
0 2
2 3
3 5
1 4
1 6
3 1
*/
