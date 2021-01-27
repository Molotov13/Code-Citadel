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
const int MAXN = 1e5 + 50;
const int mod = 99999997;
struct num{
	int v,id;
}s1[MAXN],s2[MAXN];
bool cmp(num x,num y){
	if(x.v == y.v)
		return x.id < y.id;
	return x.v < y.v;
}
int n,s[MAXN],ans,x[MAXN];
int lowbit(int x){
	return x&(-x);
}
void add(int pos,int v){
	while(pos <= n){
		s[pos] += v;
		s[pos] %= mod;
		pos += lowbit(pos);
	}
}
int query(int pos){
	int res = 0;
	while(pos > 0){
		res += s[pos] % mod;
		res %= mod;
		pos -= lowbit(pos);
	}
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s1[i].v = Read();
		s1[i].id = i;
	} 
	for(int i = 1 ; i <= n ; i++){
		s2[i].v = Read();
		s2[i].id = i;
	}
	/*stable_sort(s1 + 1 , s1 + 1 + n , cmp1);
	stable_sort(s2 + 1 , s2 + 1 + n , cmp1);
	for(int i = 1 ; i <= n ; i++){
		s1[i].v = i;
		s2[i].v = i;
	}
	stable_sort(s1 + 1 , s1 + 1 + n , cmp2);
	stable_sort(s2 + 1 , s2 + 1 + n , cmp2);*/
	//离散化
	stable_sort(s1 + 1 , s1 + 1 + n , cmp);
	stable_sort(s2 + 1 , s2 + 1 + n , cmp);
	//以对应s1为关键字排序s2确定位置 
	for(int i = 1 ; i <= n ; i++){
		x[s1[i].id] = s2[i].id;
	}
	for(int i = 1 ; i <= n ; i++){
		add(x[i],1);
		ans += i - query(x[i]);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
