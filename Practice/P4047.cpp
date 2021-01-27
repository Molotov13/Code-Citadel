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
const int MAXN = 1e6 + 50;
struct Edge{
	int u,v;
	double val;
}s[MAXN];
double x[MAXN],y[MAXN],ans;
double d(int a,int b){
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
bool cmp(Edge a,Edge b){
	return a.val < b.val;
}
int n,k,tot,fa[MAXN];
int fid(int x){
	if(fa[x] != x){
		fa[x] = fid(fa[x]);
	}
	return fa[x];
}
void Kruskal(){
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	int now = 0;
	for(int i = 1 ; now <= n - k ; i++){
		int f1 = fid(s[i].u) , f2 = fid(s[i].v);
		if(f1 != f2){
			if(now == n - k){
				ans = s[i].val;
				return;
			}
			fa[f1] = f2;
			now ++;
		}
	}
}
int main(){
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i ++){
		x[i] = Read() , y[i] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j ++){
			s[++ tot].u = i;
			s[tot].v = j;
			s[tot].val = d(i,j);	
			//cout << s[tot].u << "--" << s[tot].v << ":" << s[tot].val << endl;
		}
	}
	sort(s + 1,s + 1 + tot,cmp);
	Kruskal();
	printf("%.2f",ans);
	return 0;
}
