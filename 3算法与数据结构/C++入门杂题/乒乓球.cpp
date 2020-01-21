//NOIP 2003 [普及]乒乓球 
#include<iostream>
using namespace std;
const int mxn=1000000;   //=10000时总是 Runtime Error,改为1000000或者10000000 就解决问题，为何？ 
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
