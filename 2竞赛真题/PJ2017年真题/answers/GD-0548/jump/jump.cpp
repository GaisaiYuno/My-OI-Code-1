#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int f[100005];
int inp[100005];
int n,d,k;
int ep;
bool judge(int g){
	memset(f,0,sizeof(f));
	for(int i=0;i<ep;i++)f[i]=inp[i];
	int lowjump=max(d-g,0);
	for(int i=0;i<=ep;i++){
		for(int u=lowjump;u<=d+g;u++){
			f[i+u]=max(f[i+u],inp[i+u]+f[i]);
		}
	}
	if(f[ep-1]>k)return true;
	return false;
}
int read(){
	int num=0;
	char ch=getchar();
	int w=1;
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		num=num*10+ch-48;
		ch=getchar();
	}
	return num*w;
}
int main(){
	cin>>n>>d>>k;
	//system("pause");
	int tot=0;
	for(int i=0;i<n;i++){
		int place=read();
		inp[place]=read();
		ep=max(ep,place);
		tot+=(inp[place]>0)?inp[place]:0;
	}
	//system("pause");
	if(tot<k){
		cout<<-1;
		return 0;
	}
	//system("pause");
	int lb=0,rb=ep;
	//system("pause");
	while(lb<rb){
		//cout<<lb<<' '<<rb<<' ';
		int mid=(lb+rb)/2;
		if(judge(mid)){
			//cout<<mid<<' '<<1<<endl;
			rb=mid;
		}
		else{
			//cout<<mid<<' '<<0<<endl;
			lb=mid+1;
		}
	}
	cout<<lb;
}
