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
const int MAXN = 1e7 + 50;
const int inf = 1e9 + 7;
int n,m,s,t;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot = 1;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXN],now[MAXN];
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
int match[MAXN];
bool tag[MAXN];
int dfs(int x,int sum){
	if(x == t) return sum;
	int k,res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if((dis[v] == dis[x] + 1) && val[i]){
			k = dfs(v,min(sum,val[i]));
			if(k && v != t && x != s && v - n > 0){
				tag[match[x]] ^= 1;
				match[x] = v - n;
				tag[match[x]] ^= 1;
			}
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
		}
	}
	return res;
}
void outpt(int u){
	cout << u;
	if(!match[u]) return;
	cout << " ";
	outpt(match[u]);
}
int main(){
	n = Read() , m = Read();
	s = 0 , t = n * 2 + 2;
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		add(x,y + n,1);
		add(y + n,x,0);
	}
	for(int i = 1 ; i <= n ; i ++){
		add(s,i,1);
		add(i,s,0);
		add(i + n,t,1);
		add(t,i + n,0);
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(tag[i]) continue;
		outpt(i);
		cout << endl;
	}
	cout << n - ans << endl;
	return 0;
}

