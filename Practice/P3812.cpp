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
int n,p[101];
void insert(int x){
	for(int i = 62 ; i >= 0 ; i --){
		if(!(x >> (int)i)) continue;
		if(!p[i]){
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}
int Max(){
	int res = 0;
	for(int i = 62 ; i >= 0 ; i --){
		if((res ^ p[i]) > res){
			res ^= p[i];
		}
	}
	return res;
}
#undef int
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		insert(Read());
	}
	cout << Max() << endl;
	return 0;
}
