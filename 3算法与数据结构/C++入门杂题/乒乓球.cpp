//NOIP 2003 [�ռ�]ƹ���� 
#include<iostream>
using namespace std;
const int mxn=1000000;   //=10000ʱ���� Runtime Error,��Ϊ1000000����10000000 �ͽ�����⣬Ϊ�Σ� 
char s[mxn];
int n,sco1,sco2;
int main()
{
    int i;
    n=0;  sco1=sco2=0;
    
    while(1)
    {
        cin>> s[n];
        if( s[n]=='E') break; 
        n++;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]=='W') sco1++;
        else sco2++;
        if((sco1>=11 && sco1-sco2>=2) ||(sco2>=11 && sco2-sco1>=2))
        	{
			  cout<<sco1<<':'<<sco2<<'\n';
   			  sco1=sco2=0;
		}
    }
     cout<<sco1<<':'<<sco2<<'\n'<<'\n';
     sco1=sco2=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='W') sco1++;
        else sco2++;
        if((sco1>=21 && sco1-sco2>=2) ||(sco2>=21 && sco2-sco1>=2))
		{
			  cout<<sco1<<':'<<sco2<<'\n';
   			  sco1=sco2=0;
		}
    }
      cout<<sco1<<':'<<sco2<<'\n';
 
    return 0;
}
