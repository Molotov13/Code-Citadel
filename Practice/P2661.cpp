#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 50;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int n,sz[MAXN],scc[MAXN],dfn[MAXN],low[MAXN],ans = 19260817,tot,sccnum,stk[MAXN],top,nxt[MAXN];
void tarjan(int x){
	dfn[x] = low[x] = ++tot;
	stk[++top] = x;
	int v = nxt[x];
	if(!dfn[v]){
		tarjan(v);
		low[x] = min(low[x],low[v]);
	}
	else if(!scc[v]) low[x] = min(dfn[v],low[x]);
	if(low[x] == dfn[x]){
		scc[x] = ++sccnum;
		sz[sccnum] = 1;
		while(stk[top] != x){
			scc[stk[top]] = sccnum;
			top --;
			sz[sccnum] ++;
		}
		top --;
	}
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		nxt[i] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1 ; i <= sccnum ; i++){
		if(sz[i] != 1) ans = min(ans,sz[i]);
	}
	cout << ans << endl;
	return 0;
}
