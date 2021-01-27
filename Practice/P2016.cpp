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
const int MAXN = 100000;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot,dp[MAXN][2];
void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int DP(int u){
	dp[u][1] = 1 , dp[u][0] = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		DP(v);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1],dp[v][0]);
	}
}
int n;
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		int u = Read() , k = Read();
		for(int j = 1 ; j <= k ; j ++){
			int v = Read();
			add(u,v);
		}
	}
	DP(0);
	cout << min(dp[0][1],dp[0][0]);
	return 0;
}
