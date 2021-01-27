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
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
int n,m;
int dfn[MAXN],low[MAXN],dfx;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

bool cut[MAXN];
void tarjan(int u,int fa){
	dfn[u] = low[u] = ++ dfx;
	int child = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v,fa);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u] && u != fa){
				cut[u] = true;
			}
			if(u == fa){
				child ++;
			}
		}
		low[u] = min(low[u],dfn[v]);
	}
	if(fa == u && child >= 2){
		cut[u] = true;
	}
}

int main(){
	memset(dfn,0,sizeof(dfn));
    memset(head,0,sizeof(head));
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!dfn[i]){
			tarjan(i,i);
		}
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(cut[i]) cnt ++;
	}
	cout << cnt << endl;
	for(int i = 1 ; i <= n ; i ++){
		if(cut[i]) printf("%d ",i);
	}
	return 0;
}
