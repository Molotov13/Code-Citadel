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
const int MAXN = 1e6 + 50;
const int inf = 1e9 + 50;
#define int long long
int n,m,s,t;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot = 1;
int k = 1926;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXN],now[MAXN];
bool bfs(){
	for(int i = s ; i <= t; i ++) dis[i] = inf;
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
				Q.push(v);
				now[v] = head[v];
				if(v == t) return 1;	
			}
		}
	}
	return 0;
}
int dfs(int u,int sum){
	if(u == t) return sum;
	int k , res = 0;
	for(int &i = now[u] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[u] + 1 && val[i]){
			k = dfs(v,min(val[i],sum));
			if(!k) dis[v] = inf;
			val[i] -= k;
			val[i ^ 1] += k;
			sum -= k;
			res += k;
		}
	}
	return res;
}
#undef int
int main(){
	#define int long long
	n = Read() , m = Read() , s = 1 , t = n;
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v * k + 1);
		add(y,x,0);
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	cout << ans / k << " " << ans % k << endl;
	return 0;
}

