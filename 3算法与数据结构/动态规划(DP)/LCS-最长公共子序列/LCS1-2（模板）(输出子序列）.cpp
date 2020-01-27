#include<iostream>
#include<cstring>
#define maxn 1000
using namespace std;
string a,b;
int f[maxn][maxn];
int route[maxn][maxn];
int lena,lenb;
void debug() {
	for(int i=0; i<=lena; i++) {
		for(int j=0; j<=lena; j++) cout<<f[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<=lena; i++) {
		for(int j=0; j<=lena; j++) cout<<route[i][j]<<' ';
		cout<<endl;
	}
}
void my_print(int x,int y) {
	if(route[x][y]==0) return;
	else {
		if(route[x][y]==1) my_print(x,y-1);
		if(route[x][y]==2) my_print(x-1,y);
		if(route[x][y]==3) {
			my_print(x-1,y-1);
			cout<<b[x-1];
		}
	}
}
int main() {
	cin>>a>>b;
	memset(f,0,sizeof(f));
	lena=a.length();
	lenb=b.length();
	f[0][0]=0;
	route[0][0]=0;
	for(int i=1; i<=lenb; i++) {
		for(int j=1; j<=lena; j++) {
			if(a[i]==b[j]) {
				int x=max(max(f[i-1][j-1]+1,f[i-1][j]),f[i][j-1]);
				f[i][j]=x;
				if(x==f[i-1][j-1]+1) {
					route[i][j]=3;//�����Ͻ�ת��
				} else if(x==f[i-1][j]) {
					route[i][j]=2;//�����ת��
				} else
					route[i][j]=1;//������ת��

			} else {
				if(f[i][j-1]<f[i-1][j]) {
					route[i][j]=2;
					f[i][j]=f[i-1][j];
				} else {
					route[i][j]=1;
					f[i][j]=f[i][j-1];
				}
			}
		}
		cout<<f[lena][lenb]<<endl;
		my_print(lena,lenb);
		debug();
		return 0;
	}
}
/*״̬ת�Ʒ���
f[i][j]:iΪ��a��i��λ�ã�jΪ��b��j��λ��,
��ʾ��aǰi���봮bǰj���Ĺ��������г���

        {0   i=0,j=0
f[i][j]={f[i-1][j-1]+1  i>0,j>0,a[i]=b[J]
        {max(f[i-1][j],f[j][i-1]  i>0,j>0,a[i]!=b[J]
*/
