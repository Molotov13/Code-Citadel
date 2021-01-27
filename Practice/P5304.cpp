//Partial Accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int T,n,m,k,head[MAXN],to[MAXN],nxt[MAXN],val[MAXN],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	val[tot] = v;
	head[x] = tot;
}
int ans = 19260817;
bool vis[MAXN],tag[MAXN];
int d[MAXN];
priority_queue<pair<int,int> >Q;
void Dijkstra(int s){
	while(!Q.empty()) Q.pop();
	memset(d,-1,sizeof(d));
	memset(vis,false,sizeof(vis));
	d[s] = 0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		int now = Q.top().second;Q.pop();
		if(tag[now] && now != s){
			ans = min(d[now],ans);
			return ;
		}
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i];
			if(d[v] == -1 || d[v] > d[now] + val[i]){
				d[v] = d[now] + val[i];
				Q.push(make_pair(-d[v],v));
 			}
		}
	}
	
}
int tar[MAXN];
#undef int 
int main(){
	#define int long long
	T = Read();
	while(T--){
		memset(head,0,sizeof(head));
		memset(tag,0,sizeof(tag));
		n = Read() , m = Read() , k = Read();
		for(int i = 1 ; i <= m ; i++){
			int x = Read() , y = Read() , v = Read();
			add(x,y,v);
		}
		for(int i = 1 ; i <= k ; i ++){
			int x = Read();
			tag[x] = 1;
			tar[i] = x;
		}
		ans = 19260817;
		for(int i = 1 ; i <= k ; i++){
			Dijkstra(tar[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
