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
const int MAXN =  2e4 + 50;
int head[MAXN],nxt[MAXN],to[MAXN],val[MAXN],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	val[tot] = v;
	nxt[tot] = head[x];
	head[x] = tot;
}


int d[MAXN],cnt[MAXN],n,m;
bool InQ[MAXN];
queue<int>Q;
bool SPFA(int s){
	memset(d,128,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	memset(InQ,false,sizeof(InQ));
	Q.push(s);
	d[s] = 0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] < d[u] + val[i]){
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					cnt[v] ++;
					Q.push(v);
				}
				if(cnt[v] >= n) return 1;
			}
		}
	}
	return 0;
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i++){
		int s = Read() , t = Read() , w = Read();
		add(s,t,w);
	}
	if(SPFA(1)){
		cout << "Forever love" << endl;
		return 0;
	}
	int ans = d[n];
	if(SPFA(n)){
		cout << "Forever love" << endl;
		return 0;
	}
	cout << -max(ans,d[1]) << endl;
	return 0;
}
