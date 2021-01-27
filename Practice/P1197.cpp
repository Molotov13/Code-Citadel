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
const int MAXN = 2e5 + 50;
int n,m,k;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int fa[MAXN];
int fid(int x){
	if(fa[x] != x){
		fa[x] = fid(fa[x]);
	}
	return fa[x];
}
bool nct[MAXN];
int des[MAXN];
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() + 1 , y = Read() + 1;
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	k = Read();
	int scc = n;
	for(int i = 1 ; i <= k ; i ++){
		int x = Read() + 1;
		des[i] = x;
		nct[x] = true;
		scc --;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!nct[i]){
		//	cout << "S" << i << endl;
			for(int j = head[i] ; j ; j = nxt[j]){
				int v = to[j];
				if(nct[v]) continue;
				int f1 = fid(i) , f2 = fid(v);
				if(f1 != f2){
					fa[f1] = f2;
					scc --;
				}
			}
		}
	}
	stack<int>ans;
	ans.push(scc);
	for(int i = k ; i >= 1 ; i --){
		int u = des[i];
		nct[u] = false;
		scc ++;
		for(int j = head[u] ; j ; j = nxt[j]){
			int v = to[j];
			if(nct[v]) continue;
			int f1 = fid(v) , f2 = fid(u);
			if(f1 != f2){
				fa[f1] = f2;
				scc--;
			}
		}
		/*for(int i = 1 ; i <= n ; i ++){
			cout << i << ":" << fid(i) << endl;
		}*/
		ans.push(scc);
	}
	while(!ans.empty()){
		printf("%d\n",ans.top());
		ans.pop();	
	}
	return 0;
}

