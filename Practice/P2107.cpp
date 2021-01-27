#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2e6 + 50;
int n,m;
struct jifang{
	int x,t;
}s[MAXN];
int tot, ans, pos;
bool cmp(jifang a,jifang b){
	return a.x < b.x;
}
#undef int 
int main(){
	#define int unsigned long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		s[i].x = Read() , s[i].t = Read();
	}
	sort(s + 1 , s + 1 + n , cmp);
	priority_queue<int>Q;
	for(int i = 1 ; i <= n ; i++){
		if(tot + s[i].x - pos + s[i].t <= m){
			tot += s[i].x - pos + s[i].t;	
			pos = s[i].x;
		//cout << tot << " " << x[i] << " " << t[i] << " " << pos << endl;
			ans ++;
			Q.push(s[i].t);
		}
		else if(!Q.empty() && s[i].x - pos + s[i].t <= Q.top() && tot <= m){
			//cout << t[i] + x[i] - pos - Q.top() << endl;
			tot += s[i].x - pos + s[i].t - Q.top();
			pos = s[i].x;
			Q.pop();
			Q.push(s[i].t);
		}
	}
	cout << ans << endl;
	return 0;
}
