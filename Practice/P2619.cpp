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
const int MAXN = 1e6 + 50;
int n,m,need;
struct edge{
	int u,v,val,typ;
}s[MAXN];
int fa[MAXN],Bans,now;
bool cmp(edge a,edge b){
	if(a.val == b.val) return a.typ < b.typ;
	else return a.val < b.val;
}
int fid(int x){
	if(fa[x] != x){
		fa[x] = fid(fa[x]);
	}
	return fa[x];
}

int Kruskal(){
	int cnt = 0 , res = 0;
	sort(s + 1 , s + 1 + m , cmp);
	for(int i = 1 ; cnt != n - 1 ; i++){
		int f1 = fid(s[i].u) , f2 = fid(s[i].v);
		if(f1 != f2){
			cnt ++;
			fa[f1] = f2; 
			if(!s[i].typ) now++;
			res += s[i].val;
		}
	}
	return res;
}
int ans;
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read() , need = Read();
	for(int i = 1 ; i <= m ; i++){
		s[i].u = Read() + 1;
		s[i].v = Read() + 1;
		s[i].val = Read();
		s[i].typ = Read();
	}
	int l = -111 , r = 111 , mid;
	while(l <= r){
		mid = (l + r) >> 1;
		for(int i = 1 ; i <= m ; i++){
			if(s[i].typ == 0){
				s[i].val += mid; 
			}
		}
		for(int i = 1 ; i <= n + 1; i++) fa[i] = i;
		now = 0;
		int sum = Kruskal();
		if(now >= need){
			l = mid + 1;
			ans = sum - mid * need;
		}
		else{
			r = mid - 1;
		}
		for(int i = 1 ; i <= m ; i++){
			if(s[i].typ == 0){
				s[i].val -= mid; 
			}
		}
	}
	cout << ans << endl;
	return 0;
}
