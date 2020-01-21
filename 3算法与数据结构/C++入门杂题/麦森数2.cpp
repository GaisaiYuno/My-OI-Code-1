#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
unsigned b[501];
unsigned a[501];

unsigned * cal1(unsigned a[])
{
for(int i=0;i<500;i++)
{
b[i] = a[i];
a[i] = 0;
}
int i,j;
for(i=0;i<500;i++)
{
int k =0;
for(j=i;j<500;j++)
{
a[j] += b[k]*b[i];
k++;
}
}
for(i = 0;i<500;i++)
{
a[i+1] += a[i]/10 ;
a[i] %= 10;
}
return a;
}


unsigned * cal2(unsigned a[])
{
int m=0;
for(int j=0;j<500;j++)
{
a[j]*=2;
int temp = a[j]/10;
a[j] %= 10;a[j]+= m;m = temp;
}
return a;
}


unsigned * multi(int m)
{
if(m == 1) return a;
if(m%2 == 0)
{
unsigned *temp;
return cal1(multi(m/2));
}
else
{
return cal2(cal1(multi(m/2)));
}
}


int main()
{
int p;double l;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
a[0]=2;
cin>>p;
unsigned  *ans = multi(p);
l = p * log10(2.0) +1;
cout<<(int)l<<endl;
a[0]-=1;
for(int i=10;i>=1;i--)
{
for(int j = 50*i-1;j>=50*(i-1);j--)
{
cout<<a[j];
}
cout<<endl;
}
return 0;
}
