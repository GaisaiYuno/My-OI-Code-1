#include<cstdio>  
#include<cstring>  
#include<map>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
bool a[1005];  
int opt[1005];  
int atot;  
void work(int x){  
    switch(x){  
        case 1:  
            a[atot-2]|=a[atot-1];  
            --atot;  
           break;  
        case 2:  
            a[atot-2]&=a[atot-1];  
            --atot;  
            break;  
        case 3:a[atot-1]=!a[atot-1];  
    }  
}  
int main(){  
 // freopen("bool.in","r",stdin);  
    char s[1005];  
    int len,i,j,tmp;  
    int otot=0;  
    while(gets(s)){  
       len=strlen(s);  
        for(i=0;i<len;++i)  
            if(s[i]!=' '){  
                if(s[i]=='V'||s[i]=='F')a[atot++]=s[i]=='V';  
                else  
                   if(s[i]=='(')opt[otot++]=0;  
                    else   
                        if(s[i]==')')  
                            while(otot&&opt[--otot])  
                                work(opt[otot]);  
                        else  
                            if(s[i]=='!')opt[otot++]=3;  
                           else{  
                               tmp=s[i]=='|'?1:2;  
                                while(otot&&opt[otot-1]>=tmp)work(opt[--otot]);  
                                opt[otot++]=tmp;  
                            }  
                /*printf("--------:%c\n",s[i]); 
                for(j=0;j<atot;++j)printf("%d ",a[j]); 
                puts(""); 
                for(j=0;j<otot;++j)printf("%d ",opt[j]); 
                puts("");*/  
            }  
        if(atot==0)continue;  
        while(otot)work(opt[--otot]);  
        if(a[--atot])puts("V");  
        else puts("F");  
    }  
}  

