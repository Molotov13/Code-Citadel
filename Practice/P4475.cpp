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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 5e5 + 50;
struct Pnt{
	int x[2],v;
}s[MAXN];
int n,m;
int pivot[MAXN],mx[MAXN][2],mn[MAXN][2],ls[MAXN],rs[MAXN],sum[MAXN];
int cnt;
void pushup(int k){
	for(int i = 0 ; i < 2 ; i ++) mx[k][i] = mn[k][i] = s[pivot[k]].x[i];
	sum[k] = s[pivot[k]].v;
	if(ls[k]){
		for(int i = 0 ; i < 2 ; i ++){
			mx[k][i] = max(mx[k][i],mx[ls[k]][i]);
			mn[k][i] = min(mn[k][i],mn[ls[k]][i]);
		}
		sum[k] += sum[ls[k]];
	}
	if(rs[k]){
		for(int i = 0 ; i < 2 ; i ++){
			mx[k][i] = max(mx[k][i],mx[rs[k]][i]);
			mn[k][i] = min(mn[k][i],mn[rs[k]][i]);
		}
		sum[k] += sum[rs[k]];
	}
}
bool opt;
bool cmp(Pnt a,Pnt b){
	return a.x[opt] < b.x[opt];
}
void build(int &k,int l,int r){
	if(l > r) return;
	int mid = (l + r) >> 1;
	k = ++ cnt;
	opt = rand() % 2;
	nth_element(s + l,s + mid,s + r + 1,cmp);
	pivot[k] = mid;
	build(ls[k],l,mid - 1);
	build(rs[k],mid + 1,r);
	pushup(k);
}
bool check(int a,int b,int x,int y,int c){
	return a * x + b * y < c;
}
int query(int k,int a,int b,int c){
	int tmp = 0;
	tmp += check(a,b,mx[k][0],mx[k][1],c);
	tmp += check(a,b,mn[k][0],mx[k][1],c);
	tmp += check(a,b,mx[k][0],mn[k][1],c);
	tmp += check(a,b,mn[k][0],mn[k][1],c);
	if(tmp == 4) return sum[k];
	if(tmp == 0) return 0;
	int res = 0;
	if(check(a,b,s[pivot[k]].x[0],s[pivot[k]].x[1],c)) res += s[pivot[k]].v;
	if(ls[k]) res += query(ls[k],a,b,c);
	if(rs[k]) res += query(rs[k],a,b,c);
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].x[0] = Read() , s[i].x[1] = Read() , s[i].v = Read();
	}
	build(ls[0],1,n);
	for(int i = 1 ; i <= m ; i ++){
		int a = Read() , b = Read() , c = Read();
		printf("%lld\n",query(1,a,b,c));
	}
	return 0;
}

