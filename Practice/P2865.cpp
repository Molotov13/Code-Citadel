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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 5000 + 50 , MAXM = 1e6 + 50;
int head[MAXN],to[MAXM<<1],nxt[MAXM<<1],val[MAXN<<1],tot;
inline void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int vis[MAXN][2];
int d1[MAXN],d2[MAXN],n,m;
priority_queue<pair<pair<int,int>,int> >Q;
inline void Dijkstra(){
	Q.push(make_pair(make_pair(0,1),0));
	memset(d1,127,sizeof(d1));
	d1[1] = 0;
	memset(d2,127,sizeof(d2));
	while(!Q.empty()){
		//cout << "K";
		int dd = -Q.top().first.first;
		int now = Q.top().first.second;
		int opt = Q.top().second;
		Q.pop();
		if(vis[now][opt]) continue;
		vis[now][opt] = true;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i];
			if(dd + val[i] < d1[v]){
				d2[v] = d1[v];
				d1[v] = dd + val[i];
				Q.push(make_pair(make_pair(-d1[v],v),0));
				Q.push(make_pair(make_pair(-d2[v],v),1));
			}
			else if(dd + val[i] < d2[v]){
				d2[v] = dd + val[i];
				Q.push(make_pair(make_pair(-d2[v],v),1));
			}
		}
	}
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v);
		add(y,x,v);
	}
	Dijkstra();
	cout << d2[n] << endl;
	return 0;
}
