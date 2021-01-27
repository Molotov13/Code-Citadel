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
const int MAXN = 500;
const int MAXNN = 1e6 + 50;
const int inf = 1e9 + 7;
int n,m,s,t;
int head[MAXNN],to[MAXNN << 1],nxt[MAXNN << 1],val[MAXNN << 1],tot = 1;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXNN],now[MAXNN];
bool bfs(){
	for(int i = s ; i <= t ; i++) dis[i] = inf;
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
		//		cout << u << "--> " << v << endl;
				Q.push(v);
				now[v] = head[v];
				dis[v] = dis[u] + 1;
				if(v == t) return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int sum){
	if(x == t) return sum;
	int k,res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if((dis[v] == dis[x] + 1) && val[i]){
			k = dfs(v,min(sum,val[i]));
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
		}
	}
	return res;
}
int ans;
int k;
int main(){
	m = Read() , n = Read();
	s = 0 , t = n + m + 2;
	for(int i = 1 ; i <= m ; i ++){
		int x = Read();
		k += x;
		add(i + n,t,x);
		add(t,i + n,0);
	}
	for(int i = 1 ; i <= n ; i ++){
		int x = Read();
		for(int j = 1 ; j <= x ; j ++){
			int v = Read();
			add(i,v + n,1);
			add(v + n,i,0);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		add(s,i,1);
		add(i,s,0);
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	if(ans != k) cout << "No Solution!";
	else{
		for(int u = n + 1 ; u <= n + m ; u ++){
			cout << u - n << ":";
			for(int i = head[u] ; i ; i = nxt[i]){
				if(to[i] == t) continue;
				if(val[i]) cout << to[i] << " "; 
			}
			cout << endl;
		}
	}
	return 0;
}

