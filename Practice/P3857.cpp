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
const int MAXN = 100;
int p[MAXN],a[MAXN];
void insert(int x){
	for(int i = 62 ; i >= 0 ; i --){
		if(!(x >> i & 1)) continue;
		if(!p[i]){
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}
bool query(int x){
	for(int i = 62 ; i >= 0 ; i--){
		if((x ^ p[i]) < x){
			x ^= p[i];
		}
	}
	return (x == 0);
}
int n,m;
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= m ; i ++){
		string s;
		cin >> s;
		int cur = 0;
		for(int j = 0 ; j < n ; j ++){
			if(s[j] == 'O'){
				cur <<= 1; 	
			}
			else{
				cur = (cur << 1) + 1;
			}
		}
		if(!query(cur)) insert(cur);
	}
	int ans = 1;
	for(int i = 62 ; i >= 0 ; i --){
		if(p[i]) ans <<= 1;
		ans %= 2008;
	}
	cout << ans % 2008 << endl;
	return 0;
}

