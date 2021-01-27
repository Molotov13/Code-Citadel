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
const int MAXN = 1000 + 50,MAXM = 7000005;
int d[MAXM],head[MAXM],nxt[MAXM],to[MAXM],vall[MAXM],tot;
bool vis[MAXM];

void add(int x,int y,int v){
	to[++tot] = y;
	vall[tot] = v;
	nxt[tot] = head[x];
	head[x] = tot;
}
void Dijkstra(){
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,0));
	memset(d,-1,sizeof(d));
	memset(vis,false,sizeof(vis));
	d[0] = 0;
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i];
			if(d[v] == -1 || d[v] > d[now] + vall[i]){
				d[v] = d[now] + vall[i];
				Q.push(make_pair(-d[v],v));
			}
		}
	}
}
int n,m,s,value,num;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m-1 ; j++){
			int val = Read();
			if(i == 1){
				add(m+2*j,2*m*(n-1)+2*(m-1)+1,val);
				continue;
			}
			if(i == n){
				int sta = m-1 + 2*m*(n-1);
				add(0,sta-2*(m-j),val);
				continue;
			}
			int sta = 2*m*(i-2)+m+1;
			add(sta+2*(j-1),sta+(j-1)*2+2*m+1,val);
			add(sta+(j-1)*2+2*m+1,sta+(j-1)*2,val);
			
		}
	}
	for(int i = 1 ; i <= n-1 ; i++){
		for(int j = 1 ; j <= m ; j++){
			int val = Read();
			if(j == 1){
				add(0,m+(i-1)*m*2+1,val);
				continue;
			}
			if(j == m){
				int sta = (i-1) * 2 * m + m + 2 * (m-1);
				add(sta,2*m*(n-1)+2*(m-1)+1,val);
				continue;
			}
			int sta = 2*m*(i-1)+m;
			add(sta+(j-1)*2,sta+(j-1)*2+1,val);
			add(sta+(j-1)*2+1,sta+(j-1)*2,val);
		}
	}
	for(int i = 1 ; i <= n-1 ; i++){
		for(int j = 1 ; j <= m-1 ; j++){
			int val = Read();
			int sta = 2*m*(i-1)+m;
			add(sta+(j-1)*2+1,sta+j*2,val);
			add(sta+j*2,sta+(j-1)*2+1,val);
		}
	}
	Dijkstra();
	cout << d[2*m*(n-1)+2*(m-1)+1] << endl;
}

