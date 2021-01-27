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
const int MAXN = 1e6 + 50;
int val[MAXN],l[MAXN],r[MAXN],sz[MAXN],ans,n;
bool same(int u,int v){
	if(u == -1 && v == -1) return true;
	if(u == -1 || v == -1) return false;
	if(val[u] != val[v]) return false;
	return (same(l[u],r[v]) && same(r[u],l[v]));
}
int count(int i){
	if(i == -1) return 0;
	if(sz[i]) return sz[i];
	return (sz[i] = 1 + (count(l[i]) + count(r[i])));
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++) val[i] = Read();
	for(int i = 1 ; i <= n ; i++){
		l[i] = Read() , r[i] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		if(same(i,i)){
			ans = max(ans,count(i));
		}
	}
	cout << ans << endl;
	return 0;
}
