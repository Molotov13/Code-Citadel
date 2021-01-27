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
const int MAXN = 1e5 + 50;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int c[MAXN],u[MAXN],Inde[MAXN],Outde[MAXN],n,p;
queue<int>Q;
void bfs(){
	while(!Q.empty()){
		int now = Q.front();Q.pop();
		c[now] -= u[now];
		for(int i = head[now] ; i ; i = nxt[i]){
			int v = to[i];
			if(c[now] > 0) c[v] += val[i] * c[now];
			Inde[v]--;
			if(!Inde[v]) Q.push(v);
		}
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , p = Read();
	for(int i = 1 ; i <= n ; i++){
		c[i] = Read() , u[i] = Read();
	}
	for(int i = 1 ; i <= p ; i++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v);
		Inde[y] ++;
		Outde[x] ++;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!Inde[i]){
			Q.push(i);
			u[i] = 0;	
		}
	}
	bfs();
	bool flg = true;
	for(int i = 1 ; i <= n ; i++){ 
		if(Outde[i] == 0 && c[i] != 0) flg = false;
	}
	if(flg){
		cout << "NULL" << endl;
		return 0; 
	}
	for(int i = 1 ; i <= n ; i++){
		if(!Outde[i] && c[i] > 0){
			printf("%ld %ld\n",i,c[i]);
		}
	}
	return 0;
}
