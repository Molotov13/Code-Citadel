#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
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
const int MAXN = 1e6 + 50;
struct wire{
	int val,l,r;
	bool usd;
}s[MAXN << 2];
int n,k,a[MAXN],tot,ans,T;
priority_queue<pair<int,int> >Q;
#undef int 
int main(){
	#define int long long
	T = Read();
	while(T--){
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		while(!Q.empty()) Q.pop();
		tot = 0 , ans = 0;
		n = Read() , k = Read();
		a[1] = Read();
		for(int i = 2 ; i <= n ; i++){
			a[i] = Read();
			s[i].val = a[i] - a[i - 1];
			s[i].l = i - 1;
			s[i].r = i + 1;
			s[i].usd = false;
			Q.push(make_pair(-s[i].val,i));
		}
		s[1].val = s[n + 1].val = 1e9 + 7;
		
		while(tot < k){
			int u = Q.top().second ; Q.pop();
			//cout << u << ":" << s[u].val << " " << s[u].l << " " << s[u].r << endl;
			if(s[u].usd) continue;
			tot ++;
			ans += s[u].val;
			s[s[u].l].usd = s[s[u].r].usd = true;
			s[u].val = -s[u].val + s[s[u].l].val + s[s[u].r].val;
			s[u].l = s[s[u].l].l;
			s[u].r = s[s[u].r].r;
			s[s[u].l].r = u; 
			s[s[u].r].l = u;
			Q.push(make_pair(-s[u].val,u));
		}
		cout << ans << endl;	
	}
	return 0;
}
