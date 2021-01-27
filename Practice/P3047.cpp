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
int n,k;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],a[MAXN],tot;
int d[MAXN][30],f[MAXN][30];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x,int fa,int u){
	d[x][u] += a[x];
	for(int i = head[x] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa) continue;
		d[x][u] += d[v][u - 1];
		dfs(v,x,u);
	}
}
void calc(int x,int fa,int u){
	int w = (u - 2 >= 0 ? d[x][u - 2]:0);
	f[x][u] = f[fa][u - 1] - w + d[x][u];
	for(int i = head[x] ; i ; i = nxt[i]){
		if(to[i] != fa) calc(to[i],x,u);
	}
}
void work(int u){
	for(int i = head[1] ; i ; i = nxt[i]){
		calc(to[i],1,u);
	}
}
int main(){
	n = Read() , k = Read();
	for(int i = 1 ; i < n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		d[i][0] = a[i];	
	}
	if(!k){
		for(int i = 1 ; i <= n ; i ++){
			printf("%d\n",a[i]);
		}
		return 0;
	}
	for(int i = 1 ; i <= k ; i++) dfs(1,0,i) , f[1][i] = d[1][i];
	for(int i = 1 ; i <= n ; i ++) f[i][0] = a[i];
	for(int i = 1 ; i <= k ; i ++) work(i);
	for(int i = 1 ; i <= n ; i ++) printf("%d\n",f[i][k]);
	return 0;
}
