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
int ans,x,y,m,n,l;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1;
		y = 0;
		return a;
	}
	ans = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - y * (a / b);
	return ans;
}
#undef int 
int main(){
	#define int long long
	x = Read() , y = Read() , m = Read() , n = Read() , l = Read();
	int b = n - m , a = x - y;
	if(b < 0){
		b = -b , a = -a;
	}
	exgcd(b,l,x,y);
	//cout << ans;
	if(a % ans != 0){
		cout << "Impossible" << endl;
	}
	else cout<<((x*(a/ans))%(l/ans)+(l/ans))%(l/ans);
	return 0;
}

