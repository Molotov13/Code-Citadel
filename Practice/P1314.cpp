#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2e5 + 50;
int n,m,y;
int sum[MAXN],pre[MAXN],l[MAXN],r[MAXN],v[MAXN],w[MAXN];
int check(int s){
	memset(sum,0,sizeof(sum));
	memset(pre,0,sizeof(pre));
	for(int i = 1 ; i <= n ; i ++){
		if(w[i] >= s){
			sum[i] = v[i] + sum[i - 1];	
			pre[i] = pre[i - 1] + 1;
		}
		else{
			pre[i] = pre[i - 1];
			sum[i] = sum[i - 1];
		}
	}
	int res = 0;
	for(int i = 1 ; i <= m ; i++){
		res += (sum[r[i]] - sum[l[i] - 1]) * (pre[r[i]] - pre[l[i] - 1]);
	}
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read() , y = Read();
	for(int i = 1 ; i <= n ; i++){
		w[i] = Read() , v[i] = Read();
	}
	for(int i = 1 ; i <= m ; i++){
		l[i] = Read() , r[i] = Read();
	}
	int l = 0 , r = 1e15 + 50 , mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(mid) > y){
			l = mid;
		}
		else if(check(mid) < y){
			r = mid;
		}
		else{
			break;
		}
	}
	if(abs(check(mid) - y) > abs(check(l) - y)) mid = l;
	if(abs(check(mid) - y) > abs(check(r) - y)) mid = r;
	cout << abs(check(mid) - y)<< endl;
	return 0;
}
