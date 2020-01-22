#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
long n,m,x;
string s,s1,a[1001];
long kp(long x,long y){
	long i=x,j=y;
	string z=a[(x+y)/2];
	while(i<=j){
		while((a[i].size()<z.size())||(a[i].size()==z.size() && a[i]<z))i++;
		while((a[j].size()>z.size())||(a[j].size()==z.size() && a[j]>z))j--;
		if(i<=j){
			string t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;j--;
		}
	}
	if(i<y)kp(i,y);
	if(j>x)kp(x,j);
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	kp(1,n);
	//for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	for(int i=1;i<=m;i++){
		cin>>x;
		cin>>s;
		bool f=0;
		for(int j=1;j<=n;j++){
			long l=a[j].size();
			if(a[j].size()>=x){
				string s1="";
				for(int k=l-1;k>=l-x;k--)
					s1=a[j][k]+s1;
				//cout<<j<<' '<<s1<<endl;
				if(s1==s){
					cout<<a[j]<<endl;f=1;break;
				}
			}
		}
		if(f==0)cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
}
