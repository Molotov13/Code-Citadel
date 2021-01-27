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
const int inf = 0x7f7f7f7f;
int n,m,s,t;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],cst[MAXN << 1],tot = 1;
void add(int x,int y,int v,int c){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
	cst[tot] = c;
}
void addedge(int x,int y,int v,int c){
	add(x,y,v,-c);
	add(y,x,0,c);
}
int mc;
int dis[MAXN],now[MAXN];
bool vis[MAXN];
bool SPFA(){
	memcpy(now,head,sizeof(head));
	memset(dis,127,sizeof(dis));
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
	int k , res = 0;
	vis[x] = true;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[x] + cst[i] && val[i] && !vis[v]){
			k = dfs(v,min(val[i],sum));
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
			mc += k * cst[i];	
		}	
	}
	vis[x] = false;
	return res;
}
int id(int x,int y,bool t){
	return (x - 1) * m + y + t * m * n;
} 
bool check(int x,int y){
	return x > 0 && x <= n && y > 0 && y <= m;
}
int k,mp[300][300];
int mx[2] = {0,1};
int my[2] = {1,0};
int main(){
	n = Read() , k = Read();
	m = n;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			mp[i][j] = Read();
		}
	}
	s = 0 , t = id(n,m,1) + 10;
	addedge(s,id(1,1,0),k,0);
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			for(int k = 0 ; k < 2 ; k ++){
				if(!check(i + mx[k],j + my[k])) continue;
				addedge(id(i,j,1),id(i + mx[k],j + my[k],0),inf,0);
			}
			addedge(id(i,j,0),id(i,j,1),1,mp[i][j]);
			addedge(id(i,j,0),id(i,j,1),inf,0);
		}
	}
	addedge(id(n,m,1),t,inf,0);
	int mf = 0;
	while(SPFA()){
		mf += dfs(s,inf);
	}
	cout << -mc << endl;
	return 0;
}

