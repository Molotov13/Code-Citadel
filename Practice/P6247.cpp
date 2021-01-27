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
struct Pnt{
	double x[2];
}s[MAXN];
int n;
int cnt,ls[MAXN << 1],rs[MAXN << 1],pivot[MAXN << 1];
double mx[MAXN << 1][2],mn[MAXN << 1][2];
double Min = 9e18 , Max = 0;
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
bool opt;
bool cmp(Pnt a,Pnt b){
	return a.x[opt] < b.x[opt];
}
void build(int &k,int l,int r){
	if(l > r) return;
	k = ++ cnt;
	int mid = (l + r) >> 1;
	opt = rand() % 2;
	nth_element(s + l,s + mid,s + r + 1,cmp);
	pivot[k] = mid;
	build(ls[k],l,mid - 1);
	build(rs[k],mid + 1,r);
	pushup(k);
}
double sqr(double x){
	return x * x;
}
double maxsetd(int k,Pnt p){
	return max(sqr(p.x[0] - mx[k][0]),sqr(p.x[0] - mn[k][0])) + max(sqr(p.x[1] - mx[k][1]),sqr(p.x[1] - mn[k][1]));
}
double minsetd(int k,Pnt p){
	return min(sqr(max(0.0,p.x[0] - mx[k][0])),sqr(max(0.0,p.x[0] - mn[k][0]))) + min(sqr(max(0.0,p.x[1] - mx[k][1])),sqr(max(0.0,p.x[1] - mn[k][1])));
}
double pntd(Pnt a,Pnt b){
	return sqr(a.x[0] - b.x[0]) + sqr(a.x[1] - b.x[1]);
}
void querymax(int k,Pnt p,int id){
	double dl = 0 , dr = 0;
	if(ls[k]) dl = maxsetd(ls[k],p);
	if(rs[k]) dr = maxsetd(rs[k],p);
	if(id != pivot[k]) Max = max(Max,pntd(s[pivot[k]],p)); 
	if(dl > dr){
		if(dl > Max) querymax(ls[k],p,id);
		if(dr > Max) querymax(rs[k],p,id);
	}
	else{
		if(dr > Max) querymax(rs[k],p,id);
		if(dl > Max) querymax(ls[k],p,id);
	}
}
void querymin(int k,Pnt p,int id){
	double dl = 0x3f3f3f3f3f3f , dr = 0x3f3f3f3f3f3f3f;
	if(ls[k]) dl = minsetd(ls[k],p);
	if(rs[k]) dr = minsetd(rs[k],p);
	if(id != pivot[k]) Min = min(Min,pntd(s[pivot[k]],p)); 
	if(dl < dr){
		if(dl < Min) querymin(ls[k],p,id);
		if(dr < Min) querymin(rs[k],p,id);
	}
	else{
		if(dr < Min) querymin(rs[k],p,id);
		if(dl < Min) querymin(ls[k],p,id);
	}
}
int main(){
	srand(19270817);
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		cin >> s[i].x[0] >> s[i].x[1];
	}
	random_shuffle(s + 1,s + n + 1);
	build(ls[0],1,n);
	for(int i = 1 ; i <= n ; i ++){
		querymin(1,s[i],i);
		querymax(1,s[i],i);
	}
	printf("%.3lf %.3lf\n",sqrt(Min),sqrt(Max));
	return 0;
}

