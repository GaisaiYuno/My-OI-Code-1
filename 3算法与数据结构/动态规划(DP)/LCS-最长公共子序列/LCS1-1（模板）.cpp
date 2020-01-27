#include<iostream>
#include<cstring>
#define maxn 1000
using namespace std;
string a,b;
int f[maxn][maxn];
int main(){
	cin>>a>>b;
	memset(f,0,sizeof(f)); 
	int lena=a.length();
	int lenb=b.length();
	f[0][0]=0; 
    for(int i=1;i<=lena;i++){//С��Խ�磡 
    	for(int j=1;j<=lenb;j++){
    		if(a[i]==b[j]) f[i][j]=max(max(f[i-1][j-1]+1,f[i-1][j]),f[i][j-1]);
    		else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	} 
	cout<<f[lena][lenb]<<endl;
} 
/*״̬ת�Ʒ���
f[i][j]:iΪ��a��i��λ�ã�jΪ��b��j��λ��,
��ʾ��aǰi���봮bǰj���Ĺ��������г��� 

        {0   i=0,j=0
f[i][j]={f[i-1][j-1]+1  i>0,j>0,a[i]=b[i]
        {max(f[i-1][j],f[j][i-1]  i>0,j>0,a[i]!=b[i]
*/ 
