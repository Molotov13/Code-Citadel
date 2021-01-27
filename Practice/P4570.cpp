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
const int MAXN = 1e6 + 60;
struct num{
	int id , a;
}s[MAXN];
bool cmp(num a,num b){
	return a.a > b.a;
}
int cur,p[100];
void insert(int x){
	for(int i = 62 ; i >= 0 ; i --){
		if(!(x >> i)) continue;
		if(!p[i]){
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}
int exist(int x){
	int res = x;
	for(int i = 62 ; i >= 0 ; i --){
		if((p[i] ^ res) < res){
			res ^= p[i];
		}
	}
	return (res == 0);
}
int n,ans;
#undef int
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].id = Read() ;
		s[i].a = Read();
	}
	sort(s + 1,s + 1 + n,cmp);
	for(int i = 1 ; i <= n ; i ++){
		if(exist(s[i].id)) continue;
		ans += s[i].a;
		insert(s[i].id);
	}
	cout << ans << endl;
	return 0;
}

