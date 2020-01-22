#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
long sum,n,d,x,point,s[10000001],s11,a[500001];
long max(long a,long b){
	if(a<b)return b;
	else return a;
}
long dfs(long i,long s1,long mon){
	
	if(s1>=point){
		sum=min(mon,sum);
		return 0;
	}if(i>=s11)return 0;
	//cout<<i<<' '<<s1<<' '<<mon<<':'<<endl;
	long j=i+d,l=0;
	while((j-l>i||j+l<=s11)&&(a[s[abs(j-l)]]<0||a[s[j+l]]<0)){
		if(s[abs(j-l)]!=0&&j-l>i)dfs(j-l,s1+a[s[j-l]],max(l,mon));
		if(s[j+l]!=0&&j+l<=s11)dfs(j+l,s1+a[s[j+l]],max(l,mon));l++;//cout<<j<<' '<<l<<' '<<s[j+l]<<endl;
	}
	
	if(a[s[j-l]]>0&&j-l>i)dfs(j-l,s1+a[s[j-l]],max(l,mon));
	if(a[s[j+l]]>0&&j+l<=s11)dfs(j+l,s1+a[s[j+l]],max(l,mon));
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>point;
	for(int i=1;i<=n;i++){
		cin>>x>>a[i];
		s[x]=i;
		if(a[i]>0)sum+=a[i];
		s11=x;
	}
	//cout<<s11<<endl;
	//for(int i=0;i<=20;i++)cout<<s[i]<<' ';
	//cout<<endl;
	if(sum<point){
		cout<<-1;return 0;
	}
	sum=200000000;
	s[0]=0;a[0]=-1;
	dfs(0,0,0);
	if(sum==200000000)cout<<-1;
	else cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
