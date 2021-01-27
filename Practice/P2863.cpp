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
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int low[MAXN],dfn[MAXN],dfx;
int co[MAXN],sccnum;
int stk[MAXN],ans,top;
void tarjan(int u){
	stk[++top] = u;
	dfn[u] = low[u] = ++ dfx;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(!co[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]){
		co[u] = ++sccnum;
		if(stk[top] != u) ans ++;
		while(stk[top] != u){
			co[stk[top]] = sccnum;
			top --;
		}
		top --;
	}
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		add(x,y);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!dfn[i]) tarjan(i);
	}
	cout << ans << endl;
	return 0;
}

