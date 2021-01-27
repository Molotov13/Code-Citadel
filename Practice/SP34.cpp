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
	return s * w;
} 
const int MAXN = 1e5 + 50;
double best,ans,bx,by,ax,ay,x[MAXN],y[MAXN];
int n,mx,my;
double get(double tx,double ty){
	double res = 19260817;
	for(int i = 1 ; i <= n ; i ++){
		res = min(sqrt((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty)),res);
	}
	return res;
}
void SA(){
	double StaT = 1000 , EndT = 1e-5 , ChangeT = 0.995;
	for(double T = StaT ; T > EndT ; T *= ChangeT){
		double nx = (double)(rand() % (mx * 10 + 1))/10 ;
		double ny = (double)(rand() % (my * 10 + 1))/10 ;
		double nans = get(nx,ny);
		if(nans > best){
			bx = nx;
			by = ny;
			best = nans;
		}
		if(nans > ans){
			ax = nx;
			ay = ny;
			ans = nans;
		}
		else{
			if(exp(ans - nans)/T <= rand()&RAND_MAX){
				continue;
			}
			ax = nx;
			ay = ny;
			ans = nans;
		}
	}
}
int main(){
	int T = Read();
	while(T--){
		srand(19260817);
		mx = Read() , my = Read() , n = Read();
		for(int i = 1 ; i <= n ; i ++){
			x[i] = Read() , y[i] = Read();
		}
		bx = ax = 0 , by = ay = 0;
		best = ans = get(0.0,0.0);
		int ctrl = 1000;
		while(ctrl--){
			SA();
		}
		printf("The safest point is (%.1f,%.1f).\n",bx,by);
	}
	return 0;
}
