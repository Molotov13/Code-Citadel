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
struct Pnt{
	int x,y,t;
};
int n,m;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].x = i , s[i].y= Read();
	}
	return 0;
}

