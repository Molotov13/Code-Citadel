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
#define int long long
const int MAXN = 6e5 + 50;
int fa[MAXN],n,m,q;
int head[MAXN],nxt[MAXN<<1],to[MAXN<<1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int FindFa(int x){
	if(fa[x] == x) return x;
	return fa[x] = FindFa(fa[x]);
}
bool vis[MAXN];
int dia[MAXN],maxl,d[MAXN],s;
void dfs(int u){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(vis[v]) continue;
		vis[v] = true;
		d[v] = d[u] + 1;
		dfs(v);
		if(d[v] > maxl){
			maxl = d[v];
			s = v;
		}
	}
}
void dfs2(int u,int f){
	dia[s] = max(dia[s],d[u]);
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		d[v] = d[u] + 1;
		fa[v] = u;
		dfs2(v,u);
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read() , q = Read();
	for(int i = 1 ; i <= n ; i++){
		fa[i] = i;
	}
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			vis[i] = 1;
			s = 0;
			maxl = 0;
			d[i] = 0;
			dfs(i);
			d[s] = 0;
			dfs2(s,0);
		}
	}
	for(int i = 1 ; i <= q ; i++){
		int opt = Read();
		if(opt == 1){
			int x = Read();
			printf("%d\n",dia[FindFa(x)]);
		}
		else if(opt == 2){
			int x = Read() , y = Read();
			int f1 = FindFa(x) , f2 = FindFa(y);
			if(f1 == f2) continue;
			fa[f2] = f1;
			dia[f1] = dia[f2] = max(max(dia[f1],dia[f2]),(int)(1 + ceil((double)dia[f1]/2) + ceil((double)dia[f2]/2)));
			/*for(int i = 1 ; i <= n ; i++) cout << dia[i] << " ";
			cout << endl;
			for(int i = 1 ; i <= n ; i++) cout << FindFa(i) << " ";
			cout << endl;*/
		}
	}
	return 0;
}
/*
6 0 6
2 1 2
2 3 4
2 5 6
2 3 2
2 5 3
1 1
*/
