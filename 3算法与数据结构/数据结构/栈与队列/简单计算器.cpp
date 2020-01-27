//HDU 1237
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
stack<double>num;
double x,y,ans;
char sign;
int main(){
	while(cin>>x){
		//if(x==0) break;
		while(!num.empty()) num.pop();
		num.push(x);
		while(getchar()!='\n'){
			scanf("%c %lf",&sign,&x);
			switch(sign){
				case('+'):{
					num.push(x);
					break;
				}
				case('-'):{
					num.push(-x);
					break;
				}
				case('*'):{
					y=num.top();
					num.pop();
					y*=x;
					num.push(y);
					break;
				}
				case('/'):{
					y=num.top();
					num.pop();
					y/=x;
					num.push(y);
					break;
				}
				default:{
					break;
				}
			}
		}
		if(x==0&&num.size()==1) return 0;
		ans=0;
		while(!num.empty()){
			ans+=num.top();
			num.pop();
		}
		printf("%.2f\n",ans);
	}
} 
