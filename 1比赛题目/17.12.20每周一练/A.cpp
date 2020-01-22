#include<iostream>
#define maxn 105
using namespace std;
struct node{
	int a;
	int b;
	int c;
}in[maxn];
int n,ans,cnt;
int num1[5],num2[5];
int judge(int x,int i){
	int y,tb,tc;
    tb=tc=0;
	num1[1]=x/1000;
	num2[1]=in[i].a/1000;
 	num1[2]=(x/100)%10;
 	num2[2]=(in[i].a/100)%10;
 	num1[3]=(x/10)%10;
 	num2[3]=(in[i].a/10)%10;
 	num1[4]=x%10;
 	num2[4]=in[i].a%10;
	tb=tc=0;
	for(int j=1;j<=4;j++) if(num1[j]==num2[j]) tc++;
	for(int j=1;j<=4;j++){
	    for(int k=1;k<=4;k++){
	    	if(num1[j]==num2[k]){
	    		num2[k]=-1;
	    		tb++;
	    		break;
			}
		}
	}
	if(tb!=in[i].b||tc!=in[i].c) return 0;
    else return 1;
}
int main(){
	int j;
	while(cin>>n&&n!=0){
		ans=cnt=0;
		for(int i=1;i<=n;i++) cin>>in[i].a>>in[i].b>>in[i].c; 
		for(int num=1000;num<=9999;num++){
			for(j=1;j<=n;j++){
				if(judge(num,j)==0) break;
			}
			if(j==n+1){
				cnt++;
				ans=num;
				//cout<<cnt<<' '<<ans<<endl; 
			}
		}
		//cout<<cnt<<endl;
		if(cnt==1) cout<<ans<<endl;
		else cout<<"Not sure"<<endl;
	}
}
