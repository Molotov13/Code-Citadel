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
int n,k;
int a[MAXN],tmp[MAXN];
int cdq(int l,int r){
	if(l == r) return (a[l] >= 0);
	int mid = (l + r) >> 1;
	int res = cdq(l,mid) + cdq(mid + 1,r);
	tmp[mid] = a[mid];
	tmp[mid + 1] = a[mid + 1];
	for(int i = mid - 1 ; i >= l ; i --){
		tmp[i] = a[i] + tmp[i + 1];
	}
	for(int i = mid + 2 ; i <= r ; i ++){
		tmp[i] = a[i] + tmp[i - 1];
	}
	sort(tmp + l,tmp + mid + 1);
	sort(tmp + mid + 1,tmp + r + 1);
	for(int i = l , j = r ; i <= mid ; i ++){
		while(j > mid && tmp[i] + tmp[j] >= 0) j --;
		res += r - j;
	}
	return res;
}
#undef int 
int main(){
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read() - k;
	printf("%lld",cdq(1,n));
	return 0;
}

