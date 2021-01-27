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
int n,m,k,s,t;
int T[MAXN],h[MAXN],f[MAXN][MAXN];
int head[MAXNN],to[MAXNN << 1],nxt[MAXNN << 1],val[MAXNN << 1],tot = 1;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXNN],now[MAXNN];
int day = 1;
int id(int num,int tt){
	return num + n * tt;
}
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
int main(){
	n = Read() + 2, m = Read() , k = Read();
	for(int i = 1 ; i <= m ; i ++){
		h[i] = Read() , T[i] = Read();
		for(int j = 0 ; j < T[i] ; j ++) f[i][j] = Read() + 2;
	}
	s = 0 ,t = 100000;
	add(s,id(2,0),inf);
	add(id(2,0),s,0);
	add(id(1,0),t,inf);
	add(t,id(1,0),0);
	while(day <= 700){
	//	cout << day << ":" << endl;
		add(s,id(2,day),inf);
		add(id(2,day),s,0);
		add(id(1,day),t,inf);
		add(t,id(1,day),0);
		//cout << s << "-->" << id(2,day) << endl;
		//cout << id(1,day) << "-->" << t << endl;
		for(int i = 3 ; i <= n ; i ++){
			add(id(i,day - 1),id(i,day),inf);
			add(id(i,day),id(i,day - 1),0);
		//	cout << id(i,day - 1) << "-->" << id(i,day) << endl;
		}
		for(int i = 1 ; i <= m ; i ++){
			add(id(f[i][(day - 1) % T[i]],day - 1),id(f[i][day % T[i]],day),h[i]);
			add(id(f[i][day % T[i]],day),id(f[i][(day - 1) % T[i]],day - 1),0);
		//	cout << id(f[i][(day - 1) % T[i]],day - 1) << "-->" << id(f[i][day % T[i]],day) << endl;
		}
		while(bfs()){
			ans += dfs(s,inf);
		//	cout << ans << endl;
		}
		if(ans >= k){
			cout << day << endl;
			return 0;
		}
		day ++;
	}
	cout << 0 << endl;
	return 0;
}

