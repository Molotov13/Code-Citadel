#include<bits/stdc++.h>
using namespace std;
const int MAXM = 1300000 + 50;
const int MAXN = 110000 + 50;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s<<3) + (s<<1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int n,m,k,s,t,head[MAXN],nxt[MAXM<<1],to[MAXM<<1],val[MAXM<<1],tot,d[MAXN];
bool vis[MAXN];
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
void Dijkstra(){
	memset(d,-1,sizeof(d));
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,s));
	d[s] = 0;
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i] , cst = val[i];
			if(d[v] == -1 || d[v] > d[now] + val[i]){
				d[v] = d[now] + val[i];
				Q.push(make_pair(-d[v],v));
			}
			//cout << now << "-->" << v << ":" << d[v] << endl;
		}
	}
}
int main(){
	n = Read() , m = Read() , k = Read();
	s = Read() , t = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read() , c = Read();
		add(x,y,c);
		add(y,x,c);
		for(int j = 1 ; j <= k ; j++){
			add(x + (j-1) * n,y + j * n,0);
			add(y + (j-1) * n,x + j * n,0);
			add(y + j * n,x + j * n,c);
			add(x + j * n,y + j * n,c);
		}
	}
	for(int j = 1 ; j <= k ; j++){
		add(t + (j-1) * n,t + j * n,0);
	}
	Dijkstra();
	cout << d[t+k*n] << endl;
	return 0;
}
