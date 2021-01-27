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
	return s*w;
}
#define inf 2147483647
const int MAXN = 3000 + 50;
struct Tree{
	int ls,rs,f,sz,dep;
}p[MAXN],c[MAXN];
string s;
int st,ans = inf/2;
int build(int fa,int pos){
	p[pos].f = fa , p[pos].sz = 1 , p[pos].dep = p[fa].dep + 1;
	if(s[pos] == '3'){
		p[pos].ls = build(pos,pos+1);
		p[pos].sz += p[p[pos].ls].sz;
		p[pos].rs = build(pos,pos+p[pos].sz);
		p[pos].sz += p[p[pos].rs].sz;
	}
	if(s[pos] == '2'){
		p[pos].rs = build(pos,pos+1);
		p[pos].sz += p[p[pos].rs].sz;
	}
	if(s[pos] == '1'){
		p[pos].ls = build(pos,pos+1);
		p[pos].sz += p[p[pos].ls].sz;
	}
	return pos;	
}
int GoDown(int now,string cmd){
	int l = cmd.size();
	for(int i = 0 ; i < l ; i++){
		now = (cmd[i] == 'L'?p[now].ls:p[now].rs);
	}
	return now;
}
int merge(int now,int cs,int sp){
	if(!now) return cs;
	if(!cs){
		cs = ++st;
}
	c[cs].sz = 1;
	if(now == sp) return cs;
	c[cs].ls = merge(p[now].ls,c[cs].ls,sp);
	c[cs].sz += c[c[cs].ls].sz;
	c[cs].rs = merge(p[now].rs,c[cs].rs,sp);
	c[cs].sz += c[c[cs].rs].sz;
	return cs;
}
int find(string rep){
	int now = 1 , last = 0;
	while(now){
		last = now;
		now = GoDown(now,rep);
		merge(last,1,now);
	}
	return c[1].sz;
}
void search(int now ,string rep){
	int cnt = 0;
	if(now == 0) return ;
	if(now != 1){
		memset(c,0,sizeof(c));
		st = 1;
		cnt = find(rep);
		ans = min(ans , 2 * (cnt - 1) - p[now].dep + 1);
	}
	search(p[now].ls,rep+'L');
	search(p[now].rs,rep+'R');
}
int main(){
	cin >> s;
	s = '.' + s;
	build(0,1);
	search(1,"");
	cout << ans << endl;
	return 0;
}
