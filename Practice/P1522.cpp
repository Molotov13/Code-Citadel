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
const int MAXN = 200;
struct pasture{
	int odr,x,y;
}s[MAXN];
double maxd[MAXN],maxl1,maxl2,dis[MAXN][MAXN];
int n;
bool m[MAXN][MAXN];
double G(pasture a,pasture b){
	//cout << a.odr << " " << b.odr << ":" << sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2)) << endl;
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
int main(){
	n = Read();
	//cout << sqrt(pow(10-15,2)+pow(10 -15,2)) << endl;
	for(int i = 1 ; i <= n ; i++){
		s[i].x = Read() , s[i].y = Read();
		s[i].odr = i;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			char ch = getchar();
			while(ch != '0' && ch != '1') ch = getchar();
			if(ch == '1') m[i][j] = 1;
			if(i == j) m[i][j] = 1;
		}
	}
	memset(dis,127,sizeof(dis));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(m[i][j]){
				dis[i][j] = dis[j][i] = G(s[i],s[j]);
			}
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	/*for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			cout << i << "," << j << ":" << dis[i][j] << endl;
		}
	}*/
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(dis[i][j] < 19260817) maxd[i] = max(maxd[i],dis[i][j]);
			maxl1 = max(maxl1,maxd[i]);
		}
 	}
	maxl2 = 19260817;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(dis[i][j] > 19260817){
				//cout << i << "," << j << ":" << maxd[i] +maxd[j] + G(s[i],s[j]) <<endl;
				maxl2 = min(maxl2,maxd[i]+maxd[j]+G(s[i],s[j]));
			}
		}
	}
	//cout << maxl1 << " " << maxl2 << endl;
	printf("%.6lf",max(maxl1,maxl2));
	return 0;
}
