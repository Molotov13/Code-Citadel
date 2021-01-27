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
int n,p;
double a[MAXN],b[MAXN];
bool check(double t){
	double res = 0;
	for(int i = 1 ; i <= n ; i++){
		if(b[i] >= a[i] * t) continue;
		res += a[i] * t - b[i];
		if(res > p * t) return false;
	}
	return true;
}
#undef int 
int main(){
	#define int long long
	n = Read() , p = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read() , b[i] = Read();
	}
	double l = 0 , r = 1e10 + 50 , mid;
	while(r - l > 1e-5){
		mid = (l + r) / 2;
		if(check(mid)){
			l = mid; 
		}
		else{
			r = mid;
		}
	}
	if(abs(mid- (1e10 + 50)) < 1){
		cout << -1 << endl;
		return 0;
	}
	printf("%.6lf\n",mid);
	return 0;
}
