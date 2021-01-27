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
#define int long long
const int MAXN = 3e4 + 50 , MAXM = 6e4 + 50;
int n,m,ans;
int head[MAXN],to[MAXM],frm[MAXM],val[MAXM],nxt[MAXM],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	frm[tot] = x;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
bool InQ[MAXN];
int cnt[MAXN],h[MAXN];
bool SPFA(int s){
	memset(cnt,0,sizeof(cnt));
	memset(InQ,false,sizeof(InQ));
	memset(h,127,sizeof(h));
	h[s] = 0;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false ;
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];
			if(h[v] > h[u] + val[i]){
				h[v] = h[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					cnt[v]++;
					Q.push(v);
				}
				if(cnt[v] > n) return true;
			}
		}
	}
	return false;
}
bool vis[MAXN];
int d[MAXN];
priority_queue<pair<int,int> >Q;
void Dijkstra(int s){
	memset(d,-1,sizeof(d));
	memset(vis,false,sizeof(vis));
	Q.push(make_pair(0,s));
	d[s] = 0;
	while(!Q.empty()){
		int u = Q.top().second;Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] == -1 || d[v] > d[u] + val[i]){
				d[v] = d[u] + val[i];
				Q.push(make_pair(-d[v],v));
			}
		}
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v);
	}
	for(int i = 1 ; i <= n ; i++){
		add(0,i,0);
	}
	if(SPFA(0)){
		cout << -1 << endl;
		return 0;	
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = head[i] ; j ; j = nxt[j]){
			val[j] += h[i] - h[to[j]];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		Dijkstra(i);
		ans = 0;
		for(int j = 1 ; j <= n ; j++){
			if(d[j] != -1) ans += j * (d[j] - h[i] + h[j]);
			else ans += j*1000000000;
			
		}
		cout << ans << endl;
	}
	return 0;
}

