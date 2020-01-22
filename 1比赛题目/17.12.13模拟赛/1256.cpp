#include<iostream>
using namespace std;
int n;
char c;
int h;
int main(){
	int up_h,down_h,len,width;
	cin>>n;
	while(n--){
		cin>>c>>h;
		width=h/6+1;
		up_h=(h-3)/2;
		down_h=h-3-up_h;
		len=down_h;
		//printf("%d %d %d %d\n",up_h,down_h,len,width);
		for(int i=1;i<=width;i++) cout<<' ';
		for(int i=1;i<=len;i++) cout<<c;
		//for(int i=1;i<=width;i++) cout<<' ';
		cout<<endl;
		for(int i=1;i<=up_h;i++){
			for(int j=1;j<=width;j++) cout<<c;
			for(int j=1;j<=len;j++) cout<<' ';
			for(int j=1;j<=width;j++) cout<<c;
			cout<<endl;
		}
		for(int i=1;i<=width;i++) cout<<' ';
		for(int i=1;i<=len;i++) cout<<c;
		//for(int i=1;i<=width;i++) cout<<' ';
		cout<<endl;
		for(int i=1;i<=down_h;i++){
			for(int j=1;j<=width;j++) cout<<c;
			for(int j=1;j<=len;j++) cout<<' ';
			for(int j=1;j<=width;j++) cout<<c;
			cout<<endl;
		}
		for(int i=1;i<=width;i++) cout<<' ';
		for(int i=1;i<=len;i++) cout<<c;
		cout<<endl;
		if(n) cout<<endl;
		//for(int i=1;i<=width;i++) cout<<' ';
	}
}
