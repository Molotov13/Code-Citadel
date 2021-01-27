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
const int MAXN = 2e4 + 50;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],frm[MAXN],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	frm[tot] = x;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int n,m;
int d[MAXN],cnt[MAXN];
bool InQ[MAXN];
bool SPFA(){
	queue<int>Q;
	Q.push(1);
	memset(d,127,sizeof(d));
	d[1] = 0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] > d[u] + val[i]){
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					Q.push(v);
					cnt[v]++;
					if(cnt[v] > n + 1) return true;
				}
			}
		}
	}
	return false;
}
bool vis[MAXN],tag[MAXN];
bool dfs(int u){
	vis[u] = 1;
	bool res = false;
	if(u == n) return true;
	for(int i = head[u] ; i ; i = nxt[i]){
		if(i % 2 == 0 || vis[to[i]]) continue;
		res |= dfs(to[i]);
	}
	if(res) tag[u] = true;
	vis[u] = 0;
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read(); // d[u] + val[i] >= d[v] 
		add(x,y,9); // d[y] <= d[x] + 9
		add(y,x,-1); // d[x] <= d[y] - 1
	}
	for(int i = 1; i <= n ; i++) cout << tag[i] << " ";
	if(!dfs(1) || SPFA()){
		cout << -1 << endl;
		return 0;
	}
	else{
		cout << n << " " << m << endl;
		for(int i = 1 ; i <= tot ; i += 2){
			if(d[to[i]] - d[frm[i]] >= 1 && d[to[i]] - d[frm[i]] <= 9){
				cout << frm[i] << " " << to[i] << " " << d[to[i]] - d[frm[i]] << endl;
			}
			else{
				cout << frm[i] << " " << to[i] << " " << 1 << endl;
			}
		}
		return 0;
	}
}
