#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50000
using namespace std;
int n,len,step=0,maxt;
string s;
int a[401];
int judge(){//1Ϊ��������0Ϊ�ǻ����� 
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
	printf("�����������:\n") ; 
    cin>>n;
    printf("��������Ҫת���ɻ�����������:\n") ;
    cin>>s;
    len=s.length();
    printf("���������ת������:\n"); 
    cin>>maxt;
    for (int i=0;i<len;i++) {  
        if (s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
        else a[i]=s[i]-55;   //16����
    } 
    while(judge()==0) {
    	if(step>maxt){
    		cout<<"Impossible!";
    		return 0;
        }
        add();
        step++;
    }
    printf("��Ҫ%d��ת��",step);
    return 0;
}
