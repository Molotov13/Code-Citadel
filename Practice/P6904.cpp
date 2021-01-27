// modified by cjy2003 
#include<bits/stdc++.h>
using namespace std;
#define double long double
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
double s[MAXN];
int lowbit(int x){
	return x&(-x);
}
int n;
void add(int pos,double x){
	while(pos <= n){
		s[pos] = s[pos] < x ? s[pos] : x;
		pos += lowbit(pos);
	}
}
double query(int pos){
	double res = 0x3f3f3f3f3f3f;
	while(pos > 0){
		res = s[pos] < res ? s[pos] : res;
		pos -= lowbit(pos);
	}
	return res;
}
double ans = 0;
int main(){
	memset(s,0x3f3f3f3f,sizeof(s));
	double p = Read() , a = Read() , b = Read() , c = Read() , d = Read();
	n = Read();
	if(n == 1){
		double Max = 0.0;
		printf("%lf\n", Max);
		return 0;
	}
	double mi=1e18;
	for(int i = n ; i >= 1 ; i -= 1){
		double price = sin(a * ( 1.000 * i) + b) + cos(c * 1.000 * i + d);
		ans = price - query(n + 1 - i) > ans ? price - query(n + 1 - i) : ans;
		add(n + 1 - i,price);
	}
	cout.precision(18);
	cout << ans * p << endl;
	return 0;
}
// 42 1 23 4 8 10
// 100 7 615 998 801 3
