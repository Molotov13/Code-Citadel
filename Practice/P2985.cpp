#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
#define int long long
const int MAXN = 5e4 + 50;
int n,d,sum,a[MAXN];
bool Check(int lmt){
	int pos = 0 , now = 0;
	for(int i = 1 ; i <= d ; i ++){
		while(now < lmt){
			pos ++;
			now += a[pos];
			//cout << pos << " ";
			if(pos > n) return false;
		}
		//cout << endl;
		now >>= 1;
	}
	return true;
}
#undef int 
int main(){
	#define int long long
	n = Read() , d = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		sum += a[i];
	}
	int l = 0 ,r = sum,mid;
	while(r - l > 1){
		mid = (l+r) >> 1;
		if(Check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if(!Check(mid)) mid = 0;
	if(Check(r)) mid = max(mid,r);
	if(Check(l)) mid = max(mid,l);
	cout << mid << endl;
	int pos = 0 , now = 0;
	for(int i = 1 ; i <= d ; i ++){
		while(now < mid){
			pos ++;
			now += a[pos];
			cout << i << endl;
		}
		now >>= 1;
	}
	while(pos < n){
		cout << d << endl;
		pos++;
	}
	return 0;
}
