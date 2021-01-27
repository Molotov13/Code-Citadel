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
const int MAXN = 5000000 + 50;
int cx[MAXN],cy[MAXN],tot;
struct Edge{
	int u,v;
	double val;
}s[MAXN];
double d(int a,int b){
//	cout << a << "," << b << ":" << sqrt((cx[a] - cx[b]) * (cx[a] - cx[b]) + (cy[a] - cy[b]) * (cy[a] - cy[b])) << endl;
	return (double)sqrt((double)(cx[a] - cx[b]) * (cx[a] - cx[b]) + (double)(cy[a] - cy[b]) * (cy[a] - cy[b]));
}
int fa[MAXN];
bool cmp(Edge a,Edge b){
	return a.val < b.val;
}
int fid(int x){
	if(fa[x] != x) fa[x] = fid(fa[x]);
	return fa[x];
}
double ans = 0.0;
int m,n,k;
void Kruskal(){
	sort(s + 1,s + 1 + tot,cmp);
	for(int i = 1 ; k < n - 1 ; i ++){
		int f1 = fid(s[i].u) , f2 = fid(s[i].v);
		if(f1 != f2){
			//cout << s[i].u << "," << s[i].v << ":" << s[i].val << endl;
			fa[f1] = f2;
			ans += s[i].val;
			k ++;
		}
	}
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		cx[i] = Read() , cy[i] = Read();
	}
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	for(int i = 1 ; i <= m ; i ++){
		int u = Read() , v = Read();
		if(fid(u) != fid(v)){
			fa[fid(u)] = fid(v);
			k ++;	
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i + 1 ; j <= n ; j ++){
			s[++ tot].u = i;
			s[tot].v = j;
			s[tot].val = d(i,j);
		}
	}
	Kruskal();
	printf("%.2lf",ans);
	return 0;
}
