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
int ans;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
int match[MAXN];
bool vis[MAXN];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool dfs(int u){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(vis[v]) continue;
		vis[v] = true;
		if(!match[v] || dfs(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}
int n,m;
int main(){
	m = Read() , n = Read();
	while(1){
		int u = Read() , v = Read();
		if(u == -1 && v == -1) break;
		add(u,v);
	}
	for(int i = 1 ; i <= m ; i ++){
		memset(vis,false,sizeof(vis));
		ans += dfs(i);
	}
	cout << ans << endl;
	for(int i = m + 1 ; i <= n ; i ++){
		if(match[i]){
			cout << match[i] << " " << i << endl;
		}
	}
	return 0;
}
