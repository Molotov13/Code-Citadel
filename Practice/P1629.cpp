#include <bits/stdc++.h>
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
const int MAXN = 1e3 + 10,MAXM = 1e5 + 50;
int head1[MAXN],to1[MAXM<<1],val1[MAXM<<1],nxt1[MAXM<<1],tot1;
int head2[MAXN],to2[MAXM<<1],val2[MAXM<<1],nxt2[MAXM<<1],tot2;
void add(int x,int y,int v){
	to1[++tot1] = y;
	nxt1[tot1] = head1[x];
	head1[x] = tot1;
	val1[tot1] = v;
	
	to2[++tot2] = x;
	nxt2[tot2] = head2[y];
	head2[y] = tot2;
	val2[tot2] = v;
}
int n,m,ans,d1[MAXN],d2[MAXN];
priority_queue<pair<int,int> >Q;
void Dijkstra1(){
	memset(d1,-1,sizeof(d1));
	d1[1] = 0;
	Q.push(make_pair(0,1));
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		for(int i = head1[now];i;i = nxt1[i]){
			int v = to1[i];
			if(d1[v] == -1 || d1[v] > d1[now] + val1[i]){
				d1[v] = d1[now] + val1[i];
				Q.push(make_pair(-d1[v],v));
			}	
		}
	}
}
void Dijkstra2(){
	memset(d2,-1,sizeof(d2));
	d2[1] = 0;
	Q.push(make_pair(0,1));
	while(!Q.empty()){
		int now = Q.top().second;
		Q.pop();
		for(int i = head2[now];i;i = nxt2[i]){
			int v = to2[i];
			if(d2[v] == -1 || d2[v] > d2[now] + val2[i]){
				d2[v] = d2[now] + val2[i];
				Q.push(make_pair(-d2[v],v));
			}	
		}
	}
}

int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v);
	}
	Dijkstra1();
	Dijkstra2();
	for(int i = 1 ; i <= n ; i++){
		ans += d1[i] + d2[i];
	}
	cout << ans << endl;
	return 0;
}
