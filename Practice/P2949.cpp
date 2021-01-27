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
const int MAXN = 2e5 + 50;
int n,ans;
struct Tow{
	int t,val;
}s[MAXN];
bool cmp(Tow a,Tow b){
	return a.t < b.t;
}
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		s[i].t = Read() , s[i].val = Read();
	}
	int tot = 0;
	sort(s + 1 , s + 1 + n , cmp);
	priority_queue<int>Q;
	for(int i = 1 ; i <= n ; i++){
		//if(!Q.empty())cout << -Q.top() << " " << s[i].val << endl;
		if(s[i].t > tot){
			Q.push(-s[i].val);
			tot ++;
			ans += s[i].val;
		}
		else if(-Q.top() < s[i].val){
			ans += Q.top();
			ans += s[i].val;
			Q.pop();
			Q.push(-s[i].val);
		}
	}
	cout << ans << endl;
	return 0;
}
