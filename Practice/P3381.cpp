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
int n,m,s,t;
int mf,mc;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],cst[MAXN << 1],tot = 1;
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
int inf;
bool SPFA(){
	memcpy(now,head,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	inf = dis[0];
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
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
	return dis[t] != inf;
}
int dfs(int x,int sum){
	if(x == t) return sum;
	vis[x] = true;
	int k ,res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[x] + cst[i] && val[i] && !vis[v]){
			k = dfs(v,min(sum,val[i]));
			if(!k) dis[v] = inf;
			mc += cst[i] * k;
			val[i] -= k;
			val[i ^ 1] += k;
			sum -= k;
			res += k;
		}
	}
	vis[x] = false;
	return res;
}
int main(){
	n = Read() , m = Read() , s = Read() , t = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read() , w = Read() , c = Read();
		addedge(x,y,w,c);
	}
	while(SPFA()){
		mf += dfs(s,inf);
	}
	cout << mf << " " << mc << endl;
	return 0;
}

