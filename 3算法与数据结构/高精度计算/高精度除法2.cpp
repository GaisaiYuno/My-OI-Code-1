#include<iostream>
#include<cstring>

using namespace std;
#define max 500

int compare(int p[],int q[],int len) {
	for(int i=len-1; i>=0; i--) {
		if(p[i]>q[i]) return 1;
		if(p[i]<q[i]) return -1;
		}
		return 0;
}
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





int add1(int sum[],int d[],int num) {

	int i,k,x;
	k=0;
	x=0;

	while(num>k) {//加法程序
	 //  sum[k]=d[k]+b[k]+x;
	   if(k==0)
		sum[k]=d[k]+1+x;
	   else 
	      sum[k]=d[k]+x;
		x=sum[k]/10;
		sum[k]%=10;
		k++;
	}
	sum[k]=x;
	if(sum[k]==0)
		k--;
	return k;
}



int main(){
string a,c;
	int i,k,out_length;
	int b[max];
	int d[max];
	int out1[max];
	int out2[max];
	int result[max];
	cout<<"请输入被除数："<<'\n' ;
	cin>>a;
	cout<<"请输入除数："<<'\n' ;
	cin>>c;
    k=1;
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
   memset(result,0,sizeof(result));
    memset(out2,0,sizeof(out2));
    memset(out1,0,sizeof(out1));
   out_length=0;
   
	for(i=0; i<a.length(); i++) {
		b[a.length()-i-1]=a[i]-48;

	}
	for(i=0; i<c.length(); i++) {
		d[c.length()-i-1]=c[i]-48;
	}
	
	if(b[a.length()-1]>d[c.length()-1])  out2[a.length()-c.length()]=1;
	else          out2[a.length()-c.length()-1]=1;	
	out_length=a.length()-c.length();
	
    while(compare(result,b,a.length()+1)<1){
    	  	for(i=0; i<=out_length; i++) {
					out1[i]=out2[i];
			}
		   out_length=add1(out2,out1,out_length+1);
		    memset(result,0,sizeof(result));
        	multi(d,out2,c.length(),out_length+1,result);  	
	}

 
	 for(i=out_length+1; i>=0; i--) //0 不输出
		{
			if(out1[i]!=0) break;
		}

	for(; i>=0; i--) //输出
		cout<<out1[i];	
		
		
	cout<<endl<<'\n';

}
