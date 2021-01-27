#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int MAXN = 5e6 + 50;
int n,m,x[MAXN],y[MAXN];
int head[MAXN],tot,to[MAXN << 1],nxt[MAXN << 1],co[MAXN],val[MAXN],sccnum;
void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int dfn[MAXN],low[MAXN],dfx,stk[MAXN],top;
int tarjan(int u){
	dfn[u] = low[u] = ++dfx;
	stk[++top] = u;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[v],low[u]);
		}
		else if(!co[v]) low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){
		sccnum ++;
		do{
			co[stk[top]] = sccnum;
			val[sccnum] ++;
			top--;
		}while(stk[top + 1] != u);
	}
}
int otd[MAXN];
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		x[i] = Read() , y[i] = Read();
		add(x[i],y[i]);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j=head[i]; j; j = nxt[j]){
			if(co[i] != co[to[j]]){
				otd[co[i]]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= sccnum ; i++){
		if(!otd[i]){
			if(ans){
				cout << 0 << endl;
				return 0;
			}
			ans = i;
		}
	}
	cout << val[ans] << endl;
	return 0;
}
