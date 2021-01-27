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
const int inf = 1e9 + 59;
int n,m,p,s,t;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot = 1;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXN],now[MAXN];
bool bfs(){
	for(int i = s ; i <= t ; i ++) dis[i] = inf;
	queue<int>Q;
	Q.push(s);
	dis[s] = 0;
	now[s] = head[s];
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] == inf && val[i]){
				dis[v] = dis[u] + 1;
				now[v] = head[v];
				Q.push(v);
				if(v == t) return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int sum){
	if(x == t) return sum;
	int k , res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[x] + 1 && val[i]){
			k = dfs(v,min(val[i],sum));
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
		}
	}
	return res;
}
int a(int x){return x;}
int b(int x){return x + m;}
int c(int x){return x + m + n;}
int d(int x){return x + m + n * 2;}
int main(){
	n = Read() , m = Read() , p = Read();
	s = 0 , t = n * 2 + m + p;
	for(int i = 1 ; i <= n ; i ++){
		int x = Read() , y = Read();
		for(int j = 1 ; j <= x ; j ++){
			int z = Read();
			add(a(z),b(i),1);
			add(b(i),a(z),0);
		}
		for(int j = 1 ; j <= y ; j ++){
			int z = Read();
			add(c(i),d(z),1);
			add(d(z),c(i),0);
		}
		add(b(i),c(i),1);
		add(c(i),b(i),0);
	}
	for(int i = 1 ; i <= m ; i ++){
		add(s,a(i),1);
		add(a(i),s,0);
	}
	for(int i = 1 ; i <= p ; i ++){
		add(d(i),t,1);
		add(t,d(i),0);
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	cout << ans << endl;
	return 0;
}

