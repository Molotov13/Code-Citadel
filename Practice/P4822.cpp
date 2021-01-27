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
const int MAXN = 3000 ,MAXM = 5e5 + 50;
int head[MAXM],to[MAXM],nxt[MAXM],val[MAXM],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int d[MAXN];
bool vis[MAXN];
void Dijkstra(){
	memset(d,-1,sizeof(d));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,1));
	d[1] = 0;
	while(!Q.empty()){
		int u = Q.top().second;Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];
			if(d[v] == -1 || d[v] > d[u] + val[i]){
				d[v] = d[u] + val[i];
				Q.push(make_pair(-d[v],v));
			}
		}
	}
}
int n,m,k;
int main(){
	n = Read() , m = Read() , k = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , val = Read();
		for(int j = 0 ; j <= k ; j ++){
			add(x+j*n,y+j*n,val);
			add(y+j*n,x+j*n,val);
		}
		for(int j = 0 ; j < k ; j ++){
			add(x+j*n,y+(j+1)*n,val/2);
			add(y+j*n,x+(j+1)*n,val/2);
		}
	}
	/*for(int i = 1 ; i <= n*(k+1) ; i++){
		for(int j = head[i] ; j ; j = nxt[j]){
			cout << i << "-->" << to[j] << ":" << val[j] << endl;
		}
	}*/
	Dijkstra();
	int ans = 19260817;
	//for(int i = 1 ; i <= n*(k+1) ; i++) cout << i << ":" << d[i] << endl;
	for(int i = 0 ; i <= k ; i++){
		ans = min(ans,d[n*(i+1)]);
	}
	cout << ans << endl;
	return 0;
}
