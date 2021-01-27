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
int inf;
int n,m,s,t;
int mf,mc;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],val[MAXN << 1],cst[MAXN << 1],tot = 1;
void add(int x,int y,int v,int c){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
	cst[tot] = c;
}
void addedge(int x,int y,int v,int c){
	add(x,y,v,c);
	add(y,x,0,-c);
}
bool vis[MAXN];
int dis[MAXN],now[MAXN];


bool SPFA(){
	memset(dis,127,sizeof(dis));
	memcpy(now,head,sizeof(head));
	queue<int>Q;
	Q.push(s);
	dis[s] = 0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		vis[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] > dis[u] + cst[i] && val[i]){
				dis[v] = dis[u] + cst[i];
				if(!vis[v]){
					Q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return dis[t] != inf;
}
int dfs(int x,int sum){
	if(x == t) return sum;
	vis[x] = true;
	int k , res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[x] + cst[i] && val[i] && !vis[v]){
			k = dfs(v,min(sum,val[i]));
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
			mc += cst[i] * k;
		}
	}
	vis[x] = false;
	return res;
}
int p,tt[2],c[2];
#undef int 
int main(){
	#define int long long
	memset(dis,127,sizeof(dis));
	inf = dis[0];
	n = Read();
	s = 0 , t = 2 * n + 1;
	for(int i = 1 ; i <= n ; i ++){
		int x = Read();
		addedge(i,t,x,0);
		addedge(s,i + n,x,0);
	}
	p = Read() , tt[0] = Read() , c[0] = Read() , tt[1] = Read() , c[1] = Read();
	for(int i = 1 ; i <= n ; i ++){
		addedge(s,i,inf,p);
	}
	for(int i = 1 ; i + 1 <= n ; i ++){
		addedge(i + n,i + 1 + n,inf,0);
	}
	for(int i = 1 ; i + tt[0] <= n ; i ++){
		addedge(i + n,i + tt[0],inf,c[0]);
	}
	for(int i = 1 ; i + tt[1] <= n ; i ++){
		addedge(i + n,i + tt[1],inf,c[1]);
	}
	while(SPFA()){
		mf += dfs(s,inf);
	}
	cout << mc;
	return 0;
}

