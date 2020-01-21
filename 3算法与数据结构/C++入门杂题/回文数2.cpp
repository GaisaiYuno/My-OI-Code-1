#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50000
using namespace std;
int n,len,step=0,maxt;
string s;
int a[401];
int judge(){//1为回文数，0为非回文数 
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
	printf("请输入进制数:\n") ; 
    cin>>n;
    printf("请输入想要转换成回文数的数字:\n") ;
    cin>>s;
    len=s.length();
    printf("请输入最大转换次数:\n"); 
    cin>>maxt;
    for (int i=0;i<len;i++) {  
        if (s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
        else a[i]=s[i]-55;   //16进制
    } 
    while(judge()==0) {
    	if(step>maxt){
    		cout<<"Impossible!";
    		return 0;
        }
        add();
        step++;
    }
    printf("需要%d次转换",step);
    return 0;
}
