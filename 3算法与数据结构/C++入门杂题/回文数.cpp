#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500
using namespace std;
int n,len,step=0;
string s;
int a[401];
int judge(){//1为回文数，0为非回文数 
    int flag=1;
    int i=0,j=len-1;
    while(i<j){
    	if(a[i]!=a[j]) flag=0;
    	i++;
    	j--;
	}
	return flag;
}
void add(){
	int temp1[maxn];
	int temp2[maxn];
	int x=0;
	for(int i=0;i<len;i++) temp1[len-i-1]=a[i];
	for(int i=0;i<len;i++){
		temp2[i]=a[i]+temp1[i]+x;
		x=temp2[i]/n;
		temp2[i]%=n;
	}
	temp2[len]=x;
	if(temp2[len]) len++;
	for(int i=0;i<len;i++) a[len-i-1]=temp2[i];
}
int main(){
	cin>>n;
    cin>>s;
	len=s.length();
	for (int i=0;i<len;i++) {  
        if (s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
        else a[i]=s[i]-55;   //16进制
    } 
    while(judge()==0) {
    	if(step>30){
    		cout<<"Impossible!";
    		return 0;
		}
		add();
		step++;
	}
	printf("STEP=%d",step);
	return 0;
}
