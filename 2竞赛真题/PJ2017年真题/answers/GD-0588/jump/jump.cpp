#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
struct data{int x,y;};
data a[500010];
int n,d,k,ans,_max,z,tt,j=0,j1=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1; i<=n; i++) 
	  {
	   scanf("%d %d",&a[i].x,&a[i].y);
	   if (a[i].y>0) ans+=a[i].y; 
      }
    if (ans<k) cout<<-1<<endl;
      else 
        {

          for (int i=1; i<=n-d; i++)
		    {
		      ans=0; j=0; 
		      while (j<=n)
			    {
			      _max=-2147483647;	
			      while (j1<=n)
				    {
				       j1++; 
				      if (i<d)
				      {
				       if (a[j1].x-a[j].x>d+i) break;
				       if (a[j1].x-a[j].x>=d-i && a[j1].x-a[j].x<=d+i) {if (_max<a[j1].y) {_max=a[j1].y; tt=a[j1].x; z=j1;}}
				      }
			          
			          else 
			           {
			            if (a[j1].x-a[j].x<=d+i) {if (_max<a[j1].y) {_max=a[j1].y; tt=a[j1].x; z=j1;}}
			              else break;
			           }
			        }
			      j1=z+1;
		        if (_max==-2147483647) break;
		        j=tt;
		        //cout<<j1<<endl;
		        //cout<<_max<<' '<<endl;
			    ans+=_max;
			    //cout<<0<<' '<<i<<' '<<j<<endl;
			     //cout<<j<<endl; 
			     if (ans>=k) {cout<<i<<endl; return 0;}
			    } 
		     }
		}  	
        
    return 0;  
   
}
