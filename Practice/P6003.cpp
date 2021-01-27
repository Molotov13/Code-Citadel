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
int n,k,m;
bool check(int x){
	int cur = n , y , t = k;
	while(t){
		y = cur / x;
		if(y <= m){
			cur -= t * m;
			t = 0;
		}
		else{
			int a = cur / y - x + 1;
			cur -= a * y;
			t -= a;
		}
	}
	return cur <= 0;
}
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read() , m = Read();
	int l = 1 , r = 10 + n / m,mid ;
	while(r - l > 1){
		mid = (l + r) >> 1;
		//cout << mid << ":" << endl;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if(!check(mid)) mid = 0;
	if(check(l)) mid = max(mid,l);
	if(check(r)) mid = max(mid,r);
	cout << mid << endl;
	return 0;
}

