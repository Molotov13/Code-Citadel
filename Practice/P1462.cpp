#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200000 + 50;
inline int Read(){
	int s = 0 ,w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s<<1) + (s<<3) + ch - '0';
		ch = getchar();
	}
	return s*w;
}
int n,m,b;
int val[MAXN],head[MAXN],to[MAXN<<1],nxt[MAXN<<1],tot,cst[MAXN];
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int d[MAXN];
bool vis[MAXN];
bool check(int lmt){
	memset(d,-1,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,1));
	d[1] = 0;
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = head[now];i;i = nxt[i]){
			int v = to[i] , c = cst[v];
			if(c > lmt) continue;
			if(d[v] == -1 || d[v] > d[now] + val[i]){
				d[v] = d[now] + val[i];
				Q.push(make_pair(-d[v],v));
			}
		}
	}
	if(d[n] <= b && d[n] != -1) return 1;
	return 0;
}
int M;
#undef int 
int main(){
	//freopen("P1462_2.in","r",stdin);
	n = Read() , m = Read() , b = Read();
	M = -1;
	for(int i = 1 ; i <= n ; i++){
		cst[i] = Read();
		M = max(cst[i],M);
	}
	for(int i = 1 ; i <= m ; i++){
		int x , y , val;
		x = Read() , y = Read() , val = Read();
		add(x,y,val);
		add(y,x,val);
	}
	int l = M , r = 0;
	while(1){
		int pl = l , pr = r;
		//cout << l << " " << r << endl;
		int mid = (l+r) >> 1;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
		if(pl == l && pr == r) break;
	}
	int aim = 0;
	if(check(l)) aim = max(aim,l);
	if(check(r)) aim = max(r,aim);
	if(aim == 0){
		cout << "AFK" << endl;
		return 0;
	}
	cout << aim << endl;
	return 0;
}
