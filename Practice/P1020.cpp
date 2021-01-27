#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 50;
int a[MAXN],f[MAXN],ans,n;
int s[MAXN];
int lowbit(int x){
	return x&(-x);
}
void add(int pos,int v){
	while(pos <= MAXN){
		s[pos] = max(s[pos],v);
		pos += lowbit(pos);
	}
}
int query(int pos){
	int res = 0;
	while(pos > 0){
		res = max(res,s[pos]);
		pos -= lowbit(pos);
	}
	return res;
}
int main(){
	while(scanf("%d",&a[++n]) != EOF);
	n --;
	int ans = 0;
	for(int i = n ; i >= 1 ; i --){
		int tmp = query(a[i]) + 1;
		add(a[i],tmp);
		ans = max(tmp,ans);
	}
	cout << ans << endl;
	memset(s,0,sizeof(s));
	ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int tmp = query(a[i] - 1) + 1;
		add(a[i],tmp);
		ans = max(tmp,ans);
	}
	cout << ans << endl;
	return 0;
	
	/*
	for(int i = n ; i >= 1 ; i --){
		f[i] = 1;
		for(int j = i + 1 ; j <= n ; j ++){
			if(a[j] <= a[i]){
				f[i] = max(f[i],f[j] + 1);
			}
		}
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	ans = 0;
	memset(f,0,sizeof(f));
	for(int i = 1 ; i <= n ; i ++){
		f[i] = 1;
		for(int j = i - 1 ; j >= 1 ; j --){
			if(a[j] < a[i]){
				f[i] = max(f[i],f[j] + 1);
			}
		}
		ans = max(ans,f[i]);
	}
	cout << ans << endl;*/
	return 0;
}
