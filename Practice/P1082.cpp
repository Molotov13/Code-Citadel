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
int a,b,x,y;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1;
		y = 0;
		return 0;
	}
	int d = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - y * (a/b);
	return d;
}
#undef int 
int main(){
	#define int long long
	a = Read() , b = Read();
	exgcd(a,b,x,y);
	cout << (x % b + b) % b << endl;
	return 0;
}

