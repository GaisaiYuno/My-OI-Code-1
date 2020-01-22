//robot 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a;
long long maxt;
long long x,y,t;
int len;
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	//getline(cin,a);
	cin>>a;//getline千万不能用！！！！！ 
	cin>>maxt;
	len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]=='E') x+=1;
		if(a[i]=='W') x-=1;
		if(a[i]=='N') y+=1;
		if(a[i]=='S') y-=1;
		//t++;		
	}
	int len2=maxt%len;
	x=x*(maxt/len);
	y=y*(maxt/len);
	for(int i=0;i<len2;i++){
		if(a[i]=='E') x+=1;
		if(a[i]=='W') x-=1;
		if(a[i]=='N') y+=1;
		if(a[i]=='S') y-=1;
		//t++;		
	}
	cout<<x<<' '<<y;
	return 0;
}
