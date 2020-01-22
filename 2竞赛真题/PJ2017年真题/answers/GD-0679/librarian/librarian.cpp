#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int bian(string s){
	int fanhui=0,j;
	for(int i=0;i<s.length();i++){
		j=s[i]-'0';
		for(int k=1;k<=s.length()-i-1;k++)j=j*10;
		fanhui=fanhui+j;
	}return fanhui;
}

int main(){
	string n[1003],q[1003],ma,ma1,s;
	int abc[1006],n1,w=1,x=0,q1,i,j,le,l[1003],p=0,max;
	
	ifstream fin("librarian.in");
	fin>>n1>>q1;
	for(i=1;i<=n1;i++)
	fin>>n[i];
	for(i=1;i<=q1;i++){
		x++;
		fin>>le>>ma;max=1000000;
		for(j=1;j<=n1;j++){
			 s=n[j];
			 int s1=s.length();
			 s.replace(0,s1-le,"");
			if(s==ma){
			p++;
			l[p]=bian(n[j]);
			}
			}
			
	/*	for(int x=w;x<=p;x++)cout<<l[x]*10<<" ";
		cout<<endl;*/
			for(int a=w;a<=p;a++)
			if(l[a]!=0){
				if(l[a]<max)max=l[a];
			}
		w=p+1;
		
		if(max==1000000)max=-1;
		abc[x]=max;
		

		
	}
     ofstream fout("librarian.out");
     for(i=1;i<=q1;i++)fout<<abc[i]<<endl;
   	 fin.close();
	fout.close();
}
