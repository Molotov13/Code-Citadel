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
const int MAXN = 1e5 + 50;
int n,m;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dfn[MAXN],low[MAXN],dfx;
int stk[MAXN],top;
int ans[MAXN],sz[MAXN];
bool cut[MAXN];
void tarjan(int u,int fa){
	dfn[u] = low[u] = ++ dfx;
	stk[++top] = u;
	int child = 0, sum = 0;
	sz[u] = 1;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v,fa);
			sz[u] += sz[v];
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]){
				ans[u] += (n - sz[v]) * sz[v];
				sum += sz[v];
				child ++;
				if(u != fa || child > 1)cut[u] = true;
			}
		}
		else low[u] = min(low[u],dfn[v]);
	}
	if(cut[u]) ans[u] += (n - sum - 1) * (sum + 1) + (n - 1);
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!dfn[i]) tarjan(i,i);
	}
	int tot = 0;
	for(int i = 1 ; i <= n ; i ++) tot += cut[i];
	cout << tot << endl;
	for(int i = 1 ; i <= n ; i ++){
		if(cut[i]) printf("%lld\n",ans[i]);
		else printf("%lld\n",(2 * (n - 1)));
 	}
	return 0;
}

