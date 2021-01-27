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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e5 + 50;
int n,k;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],val[MAXN << 1],tot = 1,d[MAXN],upd[MAXN],fa[MAXN];
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int s,dia,dia2 = - 19260817,t;
void dfs(int u,int f,int &maxl,int &pos){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		d[v] = d[u] + val[i];
		upd[v] = i;
		fa[v] = u;
		dfs(v,u,maxl,pos);
		if(maxl < d[v]){
			maxl = d[v];
			pos = v;
		}
	}
}
int DP(int u,int f){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		DP(v,u);
		dia2 = max(dia2 , d[u] + d[v] + val[i]);
		//cout << v << ":" << dia2 << " " << d[u] << " " << d[v] << " " << val[i] << endl;
		d[u] = max(d[u] , d[v] + val[i]);
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read();
	for(int i = 1 ; i < n ; i++){
		int x = Read() , y = Read();
		add(x,y,1);
		add(y,x,1);
	}
	d[1] = 0;
	dfs(1,0,dia,s);
	d[s] = 0;
	dia = 0;
	dfs(s,0,dia,t);
	if(dia < 0) dia = 0;
	if(k == 1){
		cout << (n - 1) * 2 - dia + 1 << endl;
		return 0; 
	}
	for(int i = t ; i != s ; i = fa[i]){
		val[upd[i]] = -1;
		val[upd[i] ^ 1] = -1;
	}
	memset(d,0,sizeof(d));
	DP(1,0);
	if(dia2 < 0) dia2 = 0;
	cout << (n - 1) * 2 - dia - dia2 + 2 << endl;
	return 0;
}
