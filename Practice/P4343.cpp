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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e5 + 50;
int n,m,a[MAXN];
int check(int s){
	int res = 0 , now = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] + now <= 0) now = 0;
		else now += a[i];
		if(now >= s){
			res ++;
			now = 0;
		}
	}
	return res;
}
int Max = -1 , Min = 1e15 + 50;
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
	}
	//cout << 3 << ":" << check(3) << endl; 
	int l = 0 , r = 1e15 + 50 , mid;
	bool flg = false;
	while(r - l > 1){
		mid = (l + r) >> 1;
		int now = check(mid);
		//cout << mid << ":" << now << endl;
		if(now <= m){
			r = mid ;
			if(now == m){
				Min = min(Min,mid);
				flg = true;
			}
		} 
		else{
			l = mid;
		}
	}
	l = 0 , r = 1e15 + 50;
	while(r - l > 1){
		mid = (l + r) >> 1;
		int now = check(mid);
		if(now >= m){
			l = mid;
			if(now == m){
				Max = max(Max,mid);
				flg = true;
			}
		}
		else{
			r = mid;
		}
	}
	if(!flg){
		if(check(l) == m){
			cout << l << " " << l << endl;
			return 0;
		}
		if(check(r) == m){
			cout << r << " " << r << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	cout << Min << " " << Max << endl;
	return 0;
}
