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
const int MAXN = 3000 + 50;
int head[MAXN],to[MAXN],upd[MAXN][MAXN],nxt[MAXN];
int stk[MAXN],top,tot;
double d[MAXN][MAXN],fpa[MAXN][MAXN],pace[MAXN],l[MAXN];
bool vis[MAXN][MAXN];
void add(int x,int y,int vv,int ll){
	to[++tot] = y;
	nxt[tot] = head[x];
	l[tot] = ll;
	pace[tot] = vv;
	head[x] = tot;
}
void Dijkstra(){
	memset(vis,false,sizeof(vis));
	memset(d,127,sizeof(d));
	priority_queue<pair<double,pair<int,int> > >Q;
	Q.push(make_pair(0,make_pair(70,0)));
	d[0][70] = 0;
	while(!Q.empty()){
		//cout << "Finished";
		int u = Q.top().second.second;
		int spd = Q.top().second.first;
		Q.pop();
		if(vis[u][spd]) continue;
		vis[u][spd] = true;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			int pac = pace[i];
			if(pac == 0) pac = spd;
			if(d[v][pac] > d[u][spd] + l[i]/pac){			
				d[v][pac] = d[u][spd] + l[i] / pac;
		//		cout << v << " " << pac << " " << u << " " << d[v][pac] << endl;
				upd[v][pac] = u;
				fpa[v][pac] = spd;
				Q.push(make_pair(-d[v][pac],make_pair(pac,v)));
			}
		}	
	}
}
int n,m,t,s;
int main(){
	n = Read() , m = Read() , t = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , v = Read() , l = Read();
		add(x,y,v,l);
		//add(y,x,v,l);
	}
	Dijkstra();
	top = 0;
	double ntow = 19260817;
	int fv = 0;
	for(int i = 1 ; i <= 500 ; i++){
		if(d[t][i] < ntow){
			ntow = d[t][i];
			fv = i;
		}
	}
	int now = t;
	//cout << t << " #";
	while(now != 0){
		stk[++top] = now;
		int tmp = now;
		//cout << now << " " << fv << endl;
		now = upd[now][fv];
		fv = fpa[tmp][fv];
	}
	cout << "0 ";
	for(int i = top ; i >= 1 ; i--) cout << stk[i] << " ";
	return 0;
}
/*
6 15 1
0 1 25 68
0 2 30 50
0 5 0 101
1 2 70 77
1 3 35 42
2 0 0 22
2 1 40 86
2 3 0 23
2 4 45 40
3 1 64 14
3 5 0 23
4 1 95 8
5 1 0 84
5 2 90 64
5 3 36 40
*/
