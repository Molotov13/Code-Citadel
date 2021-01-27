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
const int MAXN = 1e5 + 10;
const int inf = 1e9 + 10; 
int n,m,s,t,d;
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
	return (x - 1) * m + y + t * (m * n);
}
int dist(int a,int b,int c,int d){
	return (a - c) * (a - c) + (b - d) * (b - d);
}
int cnt;
int main(){
	n = Read() , m = Read() , d = Read();
	s = 0 , t = id(n,m,1) + 2;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			char ch = getchar();
			while(ch < '0' || ch > '3') ch = getchar();
		//	cout << ch - '0';
			add(id(i,j,0),id(i,j,1),ch - '0');
			add(id(i,j,1),id(i,j,0),0);
		}
		//cout << endl;
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			char ch = getchar();
			while(ch != 'L' && ch != '.') ch = getchar();
			if(ch == 'L'){
				add(s,id(i,j,0),1);
				add(id(i,j,0),s,0);
				cnt ++;
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(i <= d || j <= d || (n - i + 1) <= d || (m - j + 1) <= d){
				add(id(i,j,1),t,inf);
				add(t,id(i,j,1),0);
				continue;
			}
			for(int k = 1 ; k <= n ; k ++){
				for(int l = 1 ; l <= m ; l ++){
					if(dist(i,j,k,l) <= d * d){
						add(id(i,j,1),id(k,l,0),inf);
						add(id(k,l,0),id(i,j,1),0);
					}
				}
			}
		}
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
		//cout << ans << endl;
	}
	cout << (cnt - ans) << endl;
	return 0;
}

