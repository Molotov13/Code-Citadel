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
const int MAXN = 10000 + 50;
vector<pair<int,int> >e[MAXN];
int m,cnt,road[MAXN];
bool vis[MAXN];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;
}
void dfs(int u){
	for(int i = 0 ; i < e[u].size() ; i ++){
		int v = e[u][i].first , edge = e[u][i].second;
		if(vis[edge]) continue;
		vis[edge] = vis[edge^1] = 1;
		dfs(v);
	}
	road[++cnt] = u;
}
int n,tot = 1,deg[MAXN];
int main(){
	m = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read() , y = Read();
		deg[x] ++ , deg[y] ++;
		e[x].push_back(make_pair(y,++tot));
		e[y].push_back(make_pair(x,++tot));
		n = max(n,max(x,y));
	}
	int s = -1 , t = -1;
	for(int i = 1 ; i <= n ; i ++){
		sort(e[i].begin(),e[i].end(),cmp);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(deg[i] % 2){
			if(s == -1) s = i;
			else if (t == -1) t = i;
			else{
				cout << "No Solution" << endl;
				return 0;
			}
		}
	}
	if(s == -1) s = 1;
	dfs(s);
	for(int i = m + 1 ; i >= 1 ; i --){
		printf("%d\n",road[i]);
	}
	return 0;
}
/*
9
1 2
2 3
3 4
4 2
4 5
2 5
5 6
5 7
4 6
*/
