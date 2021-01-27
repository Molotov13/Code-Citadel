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
const int MAXN = 5000000 + 50;
struct cow{
	int p,c;
}s[MAXN];
bool cmp1(cow a,cow b){
	return a.c < b.c;
}
bool cmp2(cow a,cow b){
	return a.p < b.p;
}
int n,k,m,ans;
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		s[i].p = Read() , s[i].c = Read();
	}
	priority_queue<pair<int,int> >Q;
	sort(s + 1, s + 1 + n , cmp1);
	for(int i = 1 ; i <= k ; i ++){
		if(m >= s[i].c){
			m -= s[i].c;
			ans ++;
			Q.push(make_pair(- (s[i].p - s[i].c),i));
		}
		else{
			cout << ans << endl;
			return 0;
		}
	}
	sort(s + k + 1 , s + 1 + n , cmp2);
	for(int i = k + 1 ; i <= n ; i ++){
		if(m >= s[i].p){
			ans ++;
			m -= s[i].p;
		}
		else{
			int d = Q.top().first , u = Q.top().second;
			if(m + d >= s[i].c){
				Q.push(make_pair(-(s[i].p - s[i].c),i));
				ans ++;
				m -= s[i].c - d;
			}
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}
