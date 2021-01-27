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
int n,T;
int main(){
	T = Read();
	while(T--){
		n = Read();
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			ans ^= Read();
		}
		cout << (ans?"Yes":"No") << endl;
	}
	return 0;
}


