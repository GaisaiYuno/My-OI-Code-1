#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int a,b,c,d;
int main(){
	while(cin>>a>>b>>c>>d){
		int ans=0;
		if(a>0&&b>0&&c>0&&d>0){
			cout<<0<<endl;
			continue;
		}
		if(a<0&&b<0&&c<0&&d<0){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				int s1=a*i*i+b*j*j;
				if(s1>0&&c>0&&d>0||s1<0&&c<0&&d<0)continue;
				for(int k=1;k<=100;k++){
					if(d>0&&(s1+c*k*k)%d!=0) continue;
					if(d<0&&(s1+c*k*k)%(-d)!=0) continue;
					for(int t=1;t<=100;t++){
						if(a*i*i+b*j*j+c*k*k+d*t*t==0)ans++;
					}
				} 
			}
		}
		cout<<ans*16<<endl;
	}
}
