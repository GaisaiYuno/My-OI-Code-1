//scholar
#include<iostream>
#include<cstdio>
#include<algorithm> 
#define maxn 1000
using namespace std;
int n; 
struct stu{
	int num;//学号 
	int chn;//语文 
	int mat;//数学 
	int eng;//英语 
	int total;//总分 
}a[maxn];
int comp(stu x,stu y){
	if(x.total>y.total) return 1;
	else if(x.total<y.total) return 0;
	else{
		if(x.chn>y.chn) return 1;
		else if(x.chn<y.chn) return 0;
		else return x.num<y.num;
	}
}
int main(){
	freopen("scholar.in","r",stdin);
	freopen("scholar.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].chn>>a[i].mat>>a[i].eng;
		a[i].total=a[i].chn+a[i].mat+a[i].eng;
		a[i].num=i;
	}
	int y=0;
	sort(a+1,a+1+n,comp); 
	for(int j=1;j<=5;j++){
		printf("%d %d\n",a[j].num,a[j].total);
	}
	return 0;
} 
