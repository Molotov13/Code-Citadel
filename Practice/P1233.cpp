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
const int MAXN = 5e3 + 50;
int n;
struct stick{
	int w,l;
}p[MAXN];
int s[MAXN * 10];
int lowbit(int x){
	return x&(-x);
}
void modify(int pos,int x){
	while(pos > 0){
		s[pos] = max(s[pos],x);
		pos -= lowbit(pos);
	}	
}
int query(int pos){
	int res = 0;
	while(pos <= MAXN * 10){
		res = max(res,s[pos]);
		pos += lowbit(pos);
	}
	return res;
}
bool cmp(stick a,stick b){
	if(a.l == b.l) return a.w < b.w;
	return a.l < b.l; 
}
int f[MAXN];
int main(){
//	freopen("P1233_2.in.txt","r",stdin);
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		p[i].l = Read() , p[i].w = Read();
	}
	sort(p + 1,p + 1 + n,cmp);
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++){
		f[i] = 1 + query(p[i].w + 1);
		modify(p[i].w,f[i]);
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}

