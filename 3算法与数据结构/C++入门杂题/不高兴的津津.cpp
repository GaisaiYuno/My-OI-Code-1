//洛谷 不高兴的津津
#include<iostream>
#include<algorithm>
using namespace std;
struct day{
	int daynum;
	int x;
	int y;
}a[1000];
int comp(day p,day q){
	return p.x+p.y>q.x+q.y;
	return p.daynum>q.daynum;
}
int main(){
	bool flag=false;
	for(int i=1;i<=7;i++){
		cin>>a[i].x>>a[i].y;
		a[i].daynum=i;
		if(a[i].x+a[i].y>8) flag=true;
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	sort(a+1,a+8,comp);
	cout<<a[1].daynum;
	return 0;
} 
