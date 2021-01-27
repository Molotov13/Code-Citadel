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
int id(int x,int y){
	return (x - 1) * m + y;
}
bool check(int x,int y){
	return (x <= n) && (x > 0) && (y <= m) && (y > 0);
}
int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};
int sum;
int mp[200][200];
int main(){
	n = Read() , m = Read();
	s = 0 , t = id(n,m) + 1;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			mp[i][j] = Read();
			sum += mp[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if((i + j) % 2){
				add(s,id(i,j),mp[i][j]);
				add(id(i,j),s,0);
				for(int k = 0 ; k < 4 ; k ++){
					if(!check(i + mx[k],j + my[k])) continue;
					add(id(i,j),id(i + mx[k],j + my[k]),inf);
					add(id(i + mx[k],j + my[k]),id(i,j),0);
				}
			}
			else{
				add(id(i,j),t,mp[i][j]);
				add(t,id(i,j),0);
			}
		}
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	cout << sum - ans << endl;
	return 0;
}

