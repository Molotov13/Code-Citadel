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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2000 + 20;
pair<int,int> s[MAXN];
bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.first + aa.second < bb.first + bb.second;
}
int n,h,ans,tot;
bool out[MAXN];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		s[i].first = Read() , s[i].second = Read();
		tot += s[i].first;
	}
	h = Read();
	sort(s + 1 , s + 1 + n , cmp);
	priority_queue<pair<int,int> >Q;
	for(int i = 1 ; i <= n ; i ++){
		if(tot + s[i].second >= h){
			tot -= s[i].first;
			Q.push(make_pair(s[i].first,s[i].second));
		}
		else if(!Q.empty() && Q.top().first + tot + s[i].second >= h && Q.top() > s[i] ){
			tot += Q.top().first - s[i].first;
			Q.pop();
			Q.push(make_pair(s[i].first,s[i].second));
		}
	}
	cout << Q.size() << endl;
	return 0;
}
