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
const int MAXN = 5e6 + 50;
int n,p;
int ans[MAXN];
#undef int 
int main(){
    #define int long long
	ans[0] = 0;
	ans[1] = 1;
    n = Read() , p = Read();
    cout << 1 << endl;
    for(int i = 2 ; i <= n ; i++){
    	ans[i] = (p - p / i) * ans[p % i] % p;
    	cout << ans[i] << endl;
	}
    return 0;
}

