#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50 , MAXM = 5e5 + 50;
#define int long long
int n,m,s;
int to[MAXM*2],nex[MAXM*2],head[MAXN],val[MAXM*2];
int tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nex[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
bool vst[MAXN];
long long dis[MAXN];
priority_queue< pair<int,int> >Q;
void Dijkstra(){
	memset(dis,-1,sizeof(dis));
	dis[s] = 0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		int now = Q.top().second;	
		Q.pop();
		if(vst[now]) continue;
		vst[now] = 1;
		//cout << now << ":";
		for(int i = head[now];i;i = nex[i]){
			int v = to[i];
			if(dis[v] == -1 || dis[now] + val[i] < dis[v]){
				dis[v] = dis[now] + val[i];
				Q.push(make_pair(-dis[v],v));
			}
		}
	}
	
}
int u,v,l;
#undef int 
int main(){
	#define int long long
	cin >> n >> m >> s;
	for(int i = 1 ; i <= m; i++){
		cin >> u >> v >> l;
		add(u,v,l);
	}
	Dijkstra();
	for(int i = 1 ; i <= n ; i++){
		if(dis[i] != -1) cout << dis[i] <<" ";
		else{
			cout << 2147483647 << " ";
		}
	}
	return 0;
}

