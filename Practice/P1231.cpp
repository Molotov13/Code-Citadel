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
const int MAXN = 5e6 + 50;
const int MAXM = 1e6 + 50;
const int inf = 1e9 + 7;
int n,m,p,s,t;
int head[MAXN],to[MAXM],nxt[MAXM],val[MAXM],tot = 1;
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
		//	cout << u << "-->" << v << endl;
			if((dis[v] == inf) && val[i]){
				Q.push(v);
				dis[v] = dis[u] + 1;
				now[v] = head[v];
				if(v == t) return 1;
			}
		}
	}
//	cout << "over" << endl;
 	return 0;
}
int dfs(int u,int sum){
	if(u == t) return sum;
	int k , res = 0;
	for(int &i = now[u] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if((dis[v] == dis[u] + 1) && val[i]){
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
int a(int x){return x;}
int b(int x){return x + m;}
int c(int x){return x + m + n;}
int d(int x){return x + m + n + n;}
int main(){
	n = Read() , m = Read() , p = Read();
	s = 0 , t = n * 2 + m + p + 50;
	int f = Read();
	for(int i = 1 ; i <= f ; i ++){
		int x = Read() , y = Read();
		add(a(y),b(x),1);
		add(b(x),a(y),0);
	}
	f = Read();
	for(int i = 1 ; i <= f ; i ++){
		int x = Read() , y = Read();
		add(c(x),d(y),1);
		add(d(y),c(x),0);
	}
	for(int i = 1 ; i <= m ; i ++){
		add(s,a(i),1);
		add(a(i),s,0);
//		cout << a(i) << endl;
	}
//	for(int i = head[s] ; i ; i = nxt[i]) cout << to[i] << "l";
	for(int i = 1 ; i <= n ; i ++){
		add(b(i),c(i),1);
		add(c(i),b(i),0);
	}
	for(int i = 1 ; i <= p ; i ++){
		add(d(i),t,1);
		add(t,d(i),0);
	}
	int res = 0;
	while(bfs()){
		res += dfs(s,inf);
	//	cout << res << endl;
	}
	cout << res << endl;
	return 0;
}

