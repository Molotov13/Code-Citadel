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
const int MAXN = 7e3 + 50;
int head[MAXN],to[MAXN],nxt[MAXN],val[MAXN],cst[MAXN],tot;
void add(int x,int y,int v,int c){
	 to[++tot] = y;
	 cst[tot] = c;
	 val[tot] = v;
	 nxt[tot] = head[x];
	 head[x] = tot;
}
bool vis[MAXN];
double d[MAXN];
inline bool SPFA(double ans,int u){
	vis[u] = true;
	for(int i = head[u];i;i = nxt[i]){
		int v = to[i];
		double x = ans * cst[i] - val[i];
		if(d[v] > d[u] + x){
			if(vis[v]) return false;
			else{
				d[v] = d[u] + x;
				if(!SPFA(ans,v)) return false;
			}
		}
	}
	vis[u] = false;
	return true;
}
int n,m;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , v = Read() , p = Read();
		add(x,y,v,p);
	}
	for(int i = 1 ; i <= n ; i++){
		add(0,i,0,0);
	}
	double l = 0 , r = 1000001;
	while(r - l > 1e-5){
		double mid = (l+r) / 2 ;
		memset(d,127,sizeof(d));
		memset(vis,false,sizeof(vis));
		d[0] = 0 , vis[0] = true;
		if(SPFA(mid,0)){
			r = mid;	
		}
		else{
			l = mid;
		}
	}
	if(!l){
		cout << -1 << endl;
		return 0;
	}
	printf("%.1lf\n",l);
	return 0;
}
