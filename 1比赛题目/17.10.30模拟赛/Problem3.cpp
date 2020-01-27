//zoj 1037
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,m;
double ans;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m>>n;
		if(m*n%2==1) ans=double(m*n-1)+1.414;
		else ans=double(m*n); 
		printf("Scenario #%d:\n",i);
		printf("%.2f\n",ans);
		cout<<endl;
	}
	return 0;
}
/*n¡¢mÎªÆæÊý  mn-1+sqrt(2) 
  ·ñÔò mn
  */
