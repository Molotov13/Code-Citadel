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
		vis[v] = 1;
		if(!match[v] || dfs(match[v])){
			match[v] = u;
			return true;
		}
	}
	return false;
}
int n,m,ans;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		int s = Read();
		for(int j = 1 ; j <= s ; j ++){
			int v = Read();
			add(i,v + n);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)){
			ans ++;
		}
	}
//	for(int i = n + 1 ; i <= m + n ; i ++) cout << match[i] << " : " << i << endl;
	cout << ans << endl;
	return 0;
}
