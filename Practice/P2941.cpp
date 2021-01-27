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
const int MAXN = 500 + 50;
int n,v1,v2;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dfn[MAXN],low[MAXN],co[MAXN],dfx,sccnum;
int stk[MAXN],top;
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
	if(dfn[u] == low[u]){
		co[u] = ++ sccnum;
		while(stk[top] != u){
			co[stk[top]] = sccnum;
			top --;
		}
		top --;
	}
}
int a[MAXN][MAXN],v[MAXN][MAXN];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			a[i][j] = Read();
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!dfn[i]) tarjan(i);
	}
	memset(v,127,sizeof(v));
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			v[co[i]][co[j]] = min(v[co[i]][co[j]],a[i][j]);
			v[co[j]][co[i]] = min(v[co[j]][co[i]],a[j][i]);
		}
	}
	int ans = 0x3f3f3f3f3f;
	for(int i = 1 ; i <= sccnum ; i ++){
		int res = 0;
		for(int j = 1 ; j <= sccnum ; j ++){
			res += v[i][j];
		}
		ans = min(res,ans);
	}
	cout << ans * 2 << endl;
	return 0;
}

