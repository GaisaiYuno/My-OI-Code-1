#include<iostream>
#include<cstdlib>
using namespace std;
int cc(int x[100000],int y[100000],int a[100000],int n,int m,int x1,int y1,int b,int d,int c){
	if(x1==n&&y1==n){
		return b;
	}
	 if(x1==1&&y1==1)
	 for(int i=0;i<m;++i){
	 	if(x[i]==x1&&y[i]==y1){
	 		d=a[i];
	 		break;
	 	}
	 }
	 for(int i=0;i<m;++i){
	 	if(x[i]==x1+1&&y[i]==y1&&d==a[i]){
	 		x1+=1;
	 		int z=cc(x,y,a,n,m,x1+1,y1,b,a[i],0);
	 		if(z!=-1){
			 	return z;
			 }
	 	}
	 	else if(x[i]==x1+1&&y[i]==y1){
	 		int z=cc(x,y,a,n,m,x1+1,y1,b+1,a[i],0);
	 		if(z!=-1){
			 	return z;
			 }
	 	}
	 	else{
	 		if(c==1){
	 			return -1;
	 		}
	 		else{
			 int z=cc(x,y,a,n,m,x1+1,y1,b+2,d,c+1);
			 if(z!=-1){
			 	return z;
			 }
			}
	 	}
	 }
	 for(int i=0;i<m;++i){
	 	if(x[i]==x1&&y[i]==y1+1&&d==a[i]){
	 		y1+=1;
	 		int z=cc(x,y,a,n,m,x1,y1+1,b,a[i],0);
	 		if(z!=-1){
			 	return z;
			 }
	 	}
	 	else if(x[i]==x1&&y[i]==y1+1){
	 		int z=cc(x,y,a,n,m,x1,y1+1,b+1,a[i],0);
	 		if(z!=-1){
			 	return z;
			 }
	 	}
	 	else{
	 		if(c==1){
	 			return -1;
	 		}
	 		else{
			 int z=cc(x,y,a,n,m,x1,y1+1,b+2,d,c+1);
			 if(z!=-1){
			 	return z;
			 }
			}
	 	}
	 }
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;
	int x[100000],y[100000],a[100000];
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>x[i]>>y[i]>>a[i];
	}
	cout<<cc(x,y,a,n,m,1,1,0,3,0);
	return 0;
}
