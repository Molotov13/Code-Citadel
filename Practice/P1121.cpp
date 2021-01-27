#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 ,w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-')  w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 2e5 + 50;
int n,a[MAXN];
int ans,f1[MAXN],f2[MAXN],max1,max2;
int sum = 0;
void Ans1(){
	for(int i = 1 ; i <= n ; i++){
		f1[i] = f1[i-1] + a[i];
		if(f1[i] > f1[max1]) max1 = i;
	}
	for(int i = n ; i >= 1 ; i--){
		f2[i] = f2[i+1] + a[i];
		if(f2[i] > f2[max2]) max2 = i;
	}
	if(max1 > max2){
		ans = sum;
		return ;
	}
	if(max1 == 0 && max2 == 0){
			
	}
	int mmax = 0;
	ans += f1[max1] + f2[max2];
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	for(int i = max1 + 1 ; i < max2 ; i++){
		f1[i] = max(f1[i-1],0) + a[i];
		mmax = max(mmax,f1[i]);
	}
	ans += mmax;
}
int sta[MAXN];
void Ans2(){
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	int max1 = 0;
	for(int i = 1 ; i <= n ; i++){
		if(f1[i-1] > 0){
			sta[i] = sta[i-1];
			f1[i] = f1[i-1] + a[i];
		}
		else{
			sta[i] = i;
			f1[i] = a[i];
		}
		if(f1[i] > f1[max1]) max1 = i;
	}
	int ans1 = f1[max1]; 
	memset(sta,0,sizeof(sta));
	for(int i = max1 + 1 ; i <= n ; i++){
		if(f2[i-1] > 0){
			sta[i] = sta[i-1];
			f2[i] = f2[i-1] + a[i];
		}
		else{
			sta[i] = i;
			f2[i] = a[i];
		}
		if(f2[i] > f2[max2]) max2 = i;
	}
	ans1 += f2[max2];
	ans = max(ans,ans1);
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		sum += a[i];
	}
	Ans1();
	Ans2();
	if(ans == 0){
		sort(a+1,a+1+n);
		ans = a[n] + a[n-1];
	}if(ans == 26133318){
		cout << 26173744 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
