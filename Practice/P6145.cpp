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
const int MAXN = 1e5 + 50;
int head[MAXN],Inde[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	val[tot] = v;
	nxt[tot] = head[x];
	head[x] = tot;
	Inde[y] ++;
}
int n,m,c;
int d[MAXN];
queue<int>Q;
void bfs(){
	Q.push(0);
	while(!Q.empty()){
		int now = Q.front();Q.pop();
		for(int i = head[now] ; i ; i = nxt[i]){
			int v = to[i];
			d[v] = max(d[v],d[now] + val[i]);
			Inde[v]--;
			if(!Inde[v]) Q.push(v);
		}
	}
}
int main(){
	n = Read() , m = Read() , c = Read();
	for(int i = 1 ; i <= n ; i++){
		int x = Read();
		add(0,i,x);
	}
	for(int i = 1 ; i <= c ; i++){
		int a = Read() , b = Read() , x = Read();
		add(a,b,x);
	}
	bfs();
	for(int i = 1 ; i <= n ; i++){
		cout << d[i] << endl;
	}
	return 0;
}
