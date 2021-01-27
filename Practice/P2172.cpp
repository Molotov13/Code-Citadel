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
const int MAXN = 1e4 + 50;
const int inf = 1e9 + 50;
int n,m,s,t,r,c;
int head[MAXN * MAXN],to[MAXN * MAXN],nxt[MAXN * MAXN],val[MAXN * MAXN],tot = 1;
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
			if((dis[v] == inf) && val[i]){
//			cout << u << "->" << v << endl;
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
	int k , res = 0;
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
int id(int x,int y,bool t){
	return (x - 1) * m + y + (t ? m * n : 0);
}
int cnt;
bool mp[MAXN][MAXN];
int my[4],mx[4];
int main(){
	n = Read() , m = Read() , r = Read() , c = Read();
	s = 0 , t = n * m * 2 + 10;
	mx[0] = mx[1] = my[2] = r;
	my[3] = -r;
	mx[2] = mx[3] = my[0] = c;
	my[1] = -c;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			char ch = getchar();
			while(ch != '.' && ch != 'x') ch = getchar();
			if(ch == 'x') mp[i][j] = 1;
			cnt += mp[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(mp[i][j]) continue;
			for(int k = 0 ; k < 4 ; k ++){
				if(mp[i + mx[k]][j + my[k]]) continue;
				if(i + mx[k] > n || i + mx[k] <= 0 || j + my[k] > m || j + my[k] <= 0) continue;
				add(id(i,j,0),id(i + mx[k],j + my[k],1),1);
				add(id(i + mx[k],j + my[k],1),id(i,j,0),0);
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			add(s,id(i,j,0),1);
			add(id(i,j,0),s,0);
			add(id(i,j,1),t,1);
			add(t,id(i,j,1),0);
		}
	}
//	cout << s << " " << t << endl;
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
//		cout << ans << endl;
	}
	cout << n * m - cnt - ans << endl;
	return 0;
}

