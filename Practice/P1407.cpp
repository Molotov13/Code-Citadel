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
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
map<string,int>id;
int n,m,cnt;
int match[MAXN][2],co[MAXN],sccnum,ans;
int low[MAXN],dfn[MAXN],dfx;
int stk[MAXN],top;
void tarjan(int u){
	low[u] = dfn[u] = ++ dfx;
	stk[++top] = u;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if (!co[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]){
		co[u] = ++ sccnum;
		while(stk[top] != u){
			co[stk[top]] = sccnum;
			top --;
		}
		top --;
	}
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		string a,b;
		cin >> a >> b;
		if(id.find(a) == id.end()) id[a] = ++ cnt;
		if(id.find(b) == id.end()) id[b] = ++ cnt;
		match[i][0] = id[a] , match[i][1] = id[b];
		add(id[a],id[b]);
	}
	/*for(int i = 1 ; i <= n ; i ++){
		cout << match[i][0] << "," << match[i][1] << endl;
	}*/
	m = Read();
	for(int i = 1 ; i <= m ; i ++){
		string a,b;
		cin >> a >> b;
		add(id[b],id[a]);
	}
	for(int i = 1 ; i <= cnt ; i ++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(co[match[i][0]] == co[match[i][1]]) printf("Unsafe");
		else printf("Safe");
		printf("\n");
	} 
	return 0;
}

