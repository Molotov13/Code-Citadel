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
int n,a[10] = {14,1,2,4,7,8,11,13,14};
#undef int 
int main(){
	#define int long long
	n = Read();
	cout << ((n - 1) / 8 * 15 + a[n % 8]) << endl; 
	return 0;
}

