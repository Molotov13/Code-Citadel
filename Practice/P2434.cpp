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
const int MAXN = 1e6 + 50;
int n;
struct section{
	int l,r;
}s[MAXN];
bool cmp(section a,section b){
	return a.l < b.l; 
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].l = Read() , s[i].r = Read();
	}
	sort(s + 1,s + 1 + n,cmp);
	printf("%d",s[1].l);
	int pos = s[1].r;
	for(int i = 2 ; i <= n ; i ++){
		if(s[i].l <= pos){
			pos = max(pos,s[i].r);
		}
		else{
			printf(" %d\n%d",pos,s[i].l);
			pos = max(pos,s[i].r);
		}
	}
	printf(" %d",pos);
	return 0;
}
/*
5
1 1 
1 1
1 1
1 1
40 233
*/

