#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char word[100],wz[1000000];
int pos,t,len1,len2;
int main(){
    gets(word);
    gets(wz);
	len1=strlen(word);
	len2=strlen(wz);
	//wz[len2+1]=' ';
	pos=-1;
	t=0;
	int i,j;
	for(i=0;i<len1;i++) {
		if(word[i]>='A'&&word[i]<='Z') word[i]=word[i]-'A'+'a';
	} 
	for(i=0;i<len2;i++) {
		if(wz[i]>='A'&&wz[i]<='Z') wz[i]=wz[i]-'A'+'a';
	} 
	for(i=0;i<len2;i++){
		if(i==0||wz[i-1]==' '){
			for(j=0;j<len1;j++){
				if(wz[i+j]!=word[j]) break;
				//else continue;
			}
		}
		else continue;
		if(j==len1&&wz[i+j]==' '||j==len1&&i+j==len2){
			t++;
			if(pos==-1) pos=i;
		}
	}
	if(pos==-1) cout<<-1;
	else printf("%d %d",t,pos);
} 
