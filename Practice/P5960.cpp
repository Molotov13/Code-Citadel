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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2323;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int n,k,ans;
int d[MAXN],cnt[MAXN];
bool InQ[MAXN];
bool SPFA(){
	memset(d,128,sizeof(d));
	d[0] = 0;
	queue<int>Q;
	Q.push(0);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] < d[u] + val[i]){
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = 1;
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
	n = Read() , k = Read();
	for(int i = 1 ; i <= k ; i++){
		int opt = Read() , x = Read() , y = Read();
		if(opt == 1){
			add(x,y,0);
			add(y,x,0); // add(x1,x2,v) --> x2 <= x1 + v 
		}
		else if(opt == 2){
			add(x,y,1); // x2 - 1 >= x1
		}
		else if(opt == 3){
			add(y,x,0); // x1 >= x2
		}
		else if(opt == 4){
			add(y,x,1); // x1 >= x2 + 1 
		}
		else if(opt == 5){
			add(x,y,0);//x1 <= x2
		}
	}
	for(int i = 1 ; i <= n ; i++){
		add(0,i,0);
	}
	if(SPFA()){
		cout << -1 << endl;
		return 0;
	}
	bool flg = false;
	for(int i = 1 ; i <= n ; i++){
		if(d[i] == 0) flg = true;
		ans += d[i];	
	}
	cout << ans + n*flg << endl;
	return 0;
}
