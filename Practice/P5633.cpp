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
struct Edge{
	int u,v,val;
	bool typ;
}s[MAXN],p[MAXN];
int n,m,t,k,e;
int fa[MAXN];
int sum,tmp,ans = -1;
int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
bool cmp(Edge a,Edge b){
	if(a.typ && !b.typ) return 1;
	if(!a.typ && b.typ) return 0;
	return a.val < b.val;
}
int Kruskal(){
	int cnt = 0 , res = 0;
	sort(s + 1, s + 1 + e , cmp);
	//for(int i = 1 ; i <= m ; i++) cout << "E:" << s[i].u << " " << s[i].v << " " << s[i].val << endl;
	int pos = 0;
	int p1 = 1 , p2 = e + 1;
	while(p2 != m + 1 || p1 != e + 1){
		pos ++;
		if(p2 == m + 1){
			p[pos] = s[p1];
			p1 ++;
			continue;
		}
		if(p1 == e + 1){
			p[pos] = s[p2];
			p2 ++;
			continue;
		}
		if(s[p1].val <= s[p2].val){
			p[pos] = s[p1];
			p1 ++; 	
		}
		else{
			p[pos] = s[p2];
			p2 ++;
		}
	}
	/*cout << "K:" << endl;
	for(int i = 1 ; i <= m ; i++){
		cout << p[i].u << " " << p[i].v << " " << p[i].val << endl;
	}*/
	for(int i = 1 ; cnt != n - 1 ; i ++){
		int f1 = find(p[i].u) , f2 = find(p[i].v);
		if(f1 != f2){
			cnt ++;
			fa[f1] = f2;
			if(p[i].u == t || p[i].v == t) tmp ++;
			res += p[i].val;
		}
	}
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read() , t = Read() , k = Read();
	for(int i = 1 ; i <= m ; i++){
		s[i].u = Read() , s[i].v = Read() , s[i].val = Read();
		if(s[i].u == t || s[i].v == t){
			s[i].typ = true;
			e++;
			
		}
	}
	int l = -1e9 ,r = 1e9 ,mid;
	sort(s + 1, s + 1 + m , cmp);
	
	while(r >= l){
		mid = (l + r) >> 1;
		for(int i = 1 ; i <= m ; i ++){
			if(s[i].typ){
				s[i].val += mid;
			}
		}
		for(int i = 1 ; i <= n ; i ++) fa[i] = i;
		tmp = 0;
		sum = Kruskal();
		if(tmp >= k){
			l = mid + 1;
			if(tmp == k){
				ans = sum - mid * k;
				break;	
			}
		}
		else{
			r = mid - 1;
		}
		for(int i = 1 ; i <= m ; i ++){
			if(s[i].u == t || s[i].v == t){
				s[i].val -= mid;
			}
		}
	}
	if(ans == -1){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
