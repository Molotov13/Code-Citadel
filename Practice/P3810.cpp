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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2e5 + 50;
struct Pnt{
	int x,y,z,cnt,ans,id;
}s1[MAXN],s2[MAXN];
bool cmpx(Pnt a,Pnt b){
	if(a.x == b.x){
		if(a.y == b.y){
			return a.z < b.z;	
		}
		return a.y < b.y;
	}
	return a.x < b.x;
}
bool cmpy(Pnt a,Pnt b){
	if(a.y == b.y){
		return a.z < b.z;
	}
	return a.y < b.y;
}
int n,m,k,s[MAXN],f[MAXN];
int lowbit(int x){
	return x & (-x);
}
void add(int pos,int v){
	while(pos <= k){
		s[pos] += v;
		pos += lowbit(pos);
	}
}
int query(int pos){
	int res = 0;
	while(pos > 0){
		res += s[pos];
		pos -= lowbit(pos);
	}
	return res;
}
void cdq(int l,int r){
	if(l == r) return ;
	int mid = (l + r) >> 1;
	cdq(l,mid);
	cdq(mid + 1,r);
	sort(s2 + l,s2 + mid + 1,cmpy);
	sort(s2 + mid + 1,s2 + r + 1,cmpy);
	int i , j = l;
	for(int i = mid + 1 ; i <= r ; i ++){
		while(s2[i].y >= s2[j].y && j <= mid){
			add(s2[j].z,s2[j].cnt);
			j ++;
		}
		s2[i].ans += query(s2[i].z);
	}
	for(i = l ; i < j ; i ++){
		add(s2[i].z,-s2[i].cnt);
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i ++){
		s1[i].x = Read() , s1[i].y = Read() , s1[i].z = Read();
	}
	sort(s1 + 1,s1 + 1 + n,cmpx);
	int top = 0;
	for(int i = 1 ; i <= n ; i ++){
		top ++;
		s1[i].id = m + 1;
		if((s1[i].x != s1[i + 1].x)||(s1[i].y != s1[i + 1].y)||(s1[i].z != s1[i + 1].z)){
			m ++;
			s2[m].x = s1[i].x;
			s2[m].y = s1[i].y;
			s2[m].z = s1[i].z;
			s2[m].cnt = top;
			top = 0;
		}
	}
	cdq(1,m);
	for(int i = 1 ; i <= m ; i ++){
		f[s2[i].ans + s2[i].cnt - 1] += s2[i].cnt;
	}
	for(int i = 0 ; i < n ; i ++){
		printf("%lld\n",f[i]);
	}
	return 0;
}

