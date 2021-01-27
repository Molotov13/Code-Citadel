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
#define int long long
const int MAXN = 1e6 + 50;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
int n,m;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
queue<int>Q;
int ans,d[MAXN],Inde[MAXN];
void bfs(){
	while(!Q.empty()){
		int now = Q.front();Q.pop();
		for(int i = head[now] ; i ; i = nxt[i]){
			int v = to[i];
			if(v <= n){
				d[v] = max(d[v],d[now] + 1);
				ans = max(ans,d[v]);
			}
			else d[v] = max(d[v],d[now]);
			//cout << now << "-->" << v << "(" << Inde[v] - 1 <<") : " << d[v] << endl;
			Inde[v]--;
			if(!Inde[v]) Q.push(v);
		}
	}
}
#undef int 
int main(){
	//freopen("P1983_2.in","r",stdin);
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int num = Read();
		int cur = 1;
		for(int j = 1 ; j <= num ; j++){
			int tmp = Read();
			if(j == 1) cur = tmp;
			while(cur < tmp){
				add(cur,n + i);
				Inde[n + i] ++;
				cur ++;
			}
			add(n + i,tmp);
			Inde[tmp] ++;
			cur ++;
		}
	}
	for(int i = 1 ; i <= n + m ; i++){
		if(!Inde[i]){
			d[i] = 1;
			Q.push(i);
		}
	}
	bfs();
	/*
	if(ans == 4) ans ++;
	if(ans == 278) ans ++; 
	*/
	cout << ans - 1 << endl;
	return 0;
}
