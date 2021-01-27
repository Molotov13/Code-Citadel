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
const int MAXN = 1e5 + 50;
struct hole{
	int a,b,w;
}s[MAXN];
bool cmp(hole a,hole b){
	return a.w > b.w;
}
int n,m;
int p[MAXN],fa[MAXN];
int fid(int x){
	if(fa[x] != x){
		fa[x] = fid(fa[x]);
	}
	return fa[x];
}
bool check(int x){
	memset(fa,0,sizeof(fa));
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	for(int i = 1 ; i <= m ; i ++){
		if(s[i].w >= x){
			fa[fid(s[i].a)] = fid(s[i].b);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(fid(p[i]) != fid(i)) return false;
	}
	return true;
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		p[i] = Read();
	}
	for(int i = 1 ; i <= m ; i ++){
		s[i].a = Read() , s[i].b = Read() , s[i].w = Read();
	}
	sort(s + 1,s + 1 + m,cmp);
	if(check(0x3f3f3f3f3f3f3f)){
		cout << -1 << endl;
		return 0;
	}
	int r = 1e9 , l = 0 , mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if(!check(mid)) mid = 0;
	if(check(l)) mid = max(mid,l);
	if(check(r)) mid = max(mid,r);
	cout << mid << endl;
 	return 0;
}

