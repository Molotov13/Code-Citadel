#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 50;
const int mod = 100003;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int nxt[MAXN*2],head[MAXN*2],to[MAXN*2],d[MAXN],ans[MAXN],tot,n,m;
bool vis[MAXN];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dijkstra(){
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,1));
	memset(d,-1,sizeof(d));
	ans[1] = 1;
	d[1] = 0;
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i];
			if(d[v] > d[now] + 1 || d[v] == -1){
				//cout << v << "<--" << now << " " << d[v] << " " << d[now] << endl;
				ans[v] = ans[now] % mod;
				ans[v] %= mod;
				d[v] = d[now] + 1;
				Q.push(make_pair(-d[v],v));
			}
			else if(d[v] == d[now] + 1){
				//cout << v << "-->" << now << endl;
				ans[v] += ans[now] % mod;
				ans[v] %= mod;
				Q.push(make_pair(-d[v],v));
			}
		}
	}
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	dijkstra();
	for(int i = 1 ; i <= n ; i++){
		cout << ans[i] % mod << endl; 
	}
	return 0;
}
