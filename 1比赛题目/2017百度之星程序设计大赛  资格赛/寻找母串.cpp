#include<iostream>
//#include<stdlib.h>
#include"malloc.h"
#include<string.h>
using namespace std;
char tar[100000];
char *p;
//int a1[1000000],result[1000000],sum,y;
int a1[1000000],y;
 int sum;

int substring(char *str,char *str1) {
	long long x=0;
	do {
		p=strstr(str,str1);
		if(p!=NULL) {
			str=p+1;
			x=x+1;
		}
	} while(p!=NULL);
	return x;
}
void Tostring(int array[],int size) {
	char *f;
	int i;
	f=(char*)malloc(size+1);
	for(i=0; i<size; i++) {
		*(f+i)='0'+array[i];
	} *(f+i)='\0';
	
	
	sum+=substring(f,tar);
}



int main() {
	//	std::ios::sync_with_stdio(false); 
	int a[10];
	long long n,i,j,k,ch0=0,ch1=0,avi=1,total,s=0;
	long long m;
	cin>>total;
	while(s<total) {
			scanf("%lld",&m);
	//	cin>>m;
		scanf("%s",tar);
		sum=0;
		y=0;
		for(i=0,n=0; i<m; i++) {
			n<<=1;
			n|=1;
		}
		n++;
		for(i=0; i<n; i++) {
			for(j=m-1,k=i; j>=0; j--) {
				a[j]=k&1;
				k>>=1;
			}
			if(a[0]==0) continue;
			for(int p=0; p<=m-1; p++) {
				if(a[p]==0) ch0++;
				else ch1++;
				if(ch0>ch1) avi=0;
			}
			if(avi==1&&ch1==ch0) {
				y=1;
				Tostring(a,m);
				continue;
			}
			ch0=0;
			ch1=0;
			avi=1;
		}
	//	if(sum!=0) result[s]=sum;
		s++;
		// cout<<sum<<endl;
		   printf("%lld\n",sum);  
	}
//	for(i=0; i<s; i++) cout<<result[i]<<endl;
//	system("pause");
	return 0;
}

