#include<iostream>
using namespace std;
#define max 500

void multi(int u[],int v[],int a_length,int b_length,int result[])
{
	int i,j,x;
	for(i=0;i<a_length;i++)
	{
		x=0;
		for(j=0;j<b_length;j++)
		{
			result[i+j]=u[i]*v[j]+x+result[i+j];
			x=result[i+j]/10;
			result[i+j]=result[i+j]%10;
		}
		result[i+b_length]=x;
	}
	return;	
}

int main() {
	string a,c;
	int i,k,out;
	int mult1[max];
	int mult2[max];
	int result[max];
input:	
	cout<<"请输入两个小于500位的正整数："<<'\n' ;
	cin>>a;
	cin>>c;

	for(i=0; i<max; i++) {
		result[i]=0;
		mult1[i]=0;
		mult2[i]=0;
	}
	for(i=0; i<a.length(); i++) {
		mult1[a.length()-1-i]=a[i]-48;

	}
	for(i=0; i<c.length(); i++) {
		mult2[c.length()-1-i]=c[i]-48;

	}
	multi(mult1,mult2,a.length(),c.length(),result);
	//cout<<"结果是：" ;
    for(i=a.length()+c.length(); i>=0; i--) 
		{
			if(result[i]!=0) break;
		}

	for(; i>=0; i--) 
		cout<<result[i];
	cout<<'\n' ;
	goto input;
	return 0; 
}

