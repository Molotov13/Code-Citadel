/*memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));
memset(head,0,sizeof(head));*/
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
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	val[tot] = v;
	nxt[tot] = head[x];
	head[x] = tot;
}
int n,m,w;
int d[MAXN],cnt[MAXN];
bool InQ[MAXN];
bool SPFA(){
	memset(d,127,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	memset(InQ,false,sizeof(InQ));
	d[n+1] = 0;
	queue<int>Q;
	Q.push(n+1);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] > d[u] + val[i]){
				//cout << v << "<--" << u << " " << d[v] << " " << val[i] << " " << d[u] << endl;
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					Q.push(v);
					cnt[v]++;
					if(cnt[v] >= n) return true;
				}
			}
		}
	}
	return false;
}
int main(){
	w = Read();
	while(w --){
		memset(head,0,sizeof(head));
		tot = 0;
		n = Read() , m = Read();
		for(int i = 1 ; i <= m ; i++){
			int x = Read() , y = Read() , v = Read(); // d[x-1] + v = d[y]
			add(x - 1,y,v); // v >= d[y] - d[x-1] ---> d[x-1] + v >= d[y]
			add(y,x - 1,-v); // v <= d[y] - d[x-1] ---> d[y] - v >= d[x-1] 
		}
		for(int i = 1 ; i <= n ; i++){
			add(n+1,i,0);
		}
		if(SPFA()) cout << "false" << endl;
		else cout << "true" << endl;
	}
	return 0;
}
/*
2
3 3
1 2 10
1 3 -5
3 3 -15
5 3
1 5 100
3 5 50
1 2 51
*/
