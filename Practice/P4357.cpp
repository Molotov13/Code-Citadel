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
const int MAXN = 1e6 + 50;
struct Pnt{
	int x[2];
}s[MAXN];
int opt;
bool cmp(Pnt a,Pnt b){
	return a.x[opt] < b.x[opt];
}
int pivot[MAXN << 1],cnt;
int mn[MAXN << 1][2],mx[MAXN << 1][2],ls[MAXN << 1],rs[MAXN << 1];
int sqr(int x){return x * x;}
int pntd(Pnt a,Pnt b){return sqr(a.x[0] - b.x[0]) + sqr(a.x[1] - b.x[1]);}
int setd(Pnt a,int b){
	return max(sqr(a.x[0] - mx[b][0]),sqr(a.x[0] - mn[b][0])) + max(sqr(a.x[1] - mx[b][1]),sqr(a.x[1] - mn[b][1]));
}
priority_queue<int>Q;
void pushup(int k){
	for(int i = 0 ; i < 2 ; i ++) mx[k][i] = mn[k][i] = s[pivot[k]].x[i];
	if(ls[k]){
		for(int i = 0 ; i < 2 ; i ++){
			mx[k][i] = max(mx[k][i],mx[ls[k]][i]);
			mn[k][i] = min(mn[k][i],mn[ls[k]][i]);
		}
	}
	if(rs[k]){
		for(int i = 0 ; i < 2 ; i ++){
			mx[k][i] = max(mx[k][i],mx[rs[k]][i]);
			mn[k][i] = min(mn[k][i],mn[rs[k]][i]);
		}
	}
}
void build(int &k,int l,int r){
	if(l > r) return ;
	int mid = (l + r) >> 1;
	k = ++ cnt;
	opt = rand() % 2;
	nth_element(s + l,s + mid,s + r + 1,cmp);
	pivot[k] = mid;
	build(ls[k],l,mid - 1);
	build(rs[k],mid + 1,r);
	pushup(k);
}
int query(int k,Pnt p){
	int dl = -0x3f3f3f3f3f3f , dr = -0x3f3f3f3f3f3f3f;
	if(ls[k]) dl = setd(p,ls[k]);
	if(rs[k]) dr = setd(p,rs[k]);
	int di = pntd(s[pivot[k]],p);
	if(-Q.top() < di){
		Q.pop();
		Q.push(-di);
	}
	if(dl > dr){
		if(dl > -Q.top()) query(ls[k],p);
		if(dr > -Q.top()) query(rs[k],p);
	}
	else{
		if(dr > -Q.top()) query(rs[k],p);
		if(dl > -Q.top()) query(ls[k],p);
	}
}
int n,m;
#undef int 
int main(){
	#define int long long
	srand(19260817);
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].x[0] = Read() , s[i].x[1] = Read();
	}
	for(int i = 1 ; i <= m * 2 ; i ++) Q.push(0);
	build(ls[0],1,n);
	for(int i = 1 ; i <= n ; i ++) query(1,s[i]);
	cout << - Q.top() << endl;
	return 0;
}

