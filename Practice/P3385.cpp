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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
#define int long long
const int MAXN = 5e4 + 50;
int n,m,s;
int head[MAXN],val[MAXN],d[MAXN],nxt[MAXN],to[MAXN],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
bool InQ[MAXN];
int cnt[MAXN];
queue<int>Q;
bool SPFA(){
	memset(d,127,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	memset(InQ,false,sizeof(InQ));
	d[1] = 0;
	while(!Q.empty()) Q.pop();	
	Q.push(1);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];
			if(d[v] > d[u] + val[i]){
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					Q.push(v);
					cnt[v] ++;
				}
				if(cnt[v] >= n) return true;
			}
		}
	}
	return false;
}
#undef int 
int main(){
	#define int long long
	int T = Read();
	while(T--){
		tot = 0;
		memset(head,0,sizeof(head));
		n = Read() , m = Read();
		for(int i = 1 ; i <= m ; i++){
			int x = Read() , y = Read() , v = Read();
			add(x,y,v);
			if(v >= 0) add(y,x,v);
		}
		cout << (SPFA()?"YES":"NO") << endl;	
	}
	return 0;
}
