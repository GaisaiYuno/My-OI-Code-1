#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int a[26][26],b[26];
int bj[26],js=2147483,ko=1,n,m;
char s[100],l[100];
int pd() { 
    for(int i=1; i<=n; i++)
        if(bj[i]<b[i])//�ж��ǲ���ά���ش���ţ�������͵�ά���� 
            return 0;//������Ƿ���0 
    return 1;//����Ƿ���1 
}
void dfs(int k,int ans) {
    if(pd()==1) {//��� ά���ش���ţ�������͵�ά���� 
        if(js>ans) {//�����ǰ��Сֵ���ڱ��ε�ֵ 
            for(int i=1; i<=m; i++)
                l[i]=s[i];//��s�����ֵ����l���� 
        }
        js=min(js,ans);//ȡjs��ans�е���Сֵ 
        return ;//���� 
    }
    for(int i=k+1; i<=m; i++) {
        for(int j=1; j<=n; j++)
            bj[j]+=a[i][j];
        s[i]='1';//���i˵��i���ѡ�� 
        dfs(i,ans+1);//���� 
        for(int j=1; j<=n; j++)
            bj[j]=bj[j]-a[i][j];
        s[i]='0';//��i�ı����� 
    }
}
int main() {
    cin>>n;//���� 
    for(int i=1; i<=n; i++)
        cin>>b[i];
    cin>>m;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];
    for(int ii=1; ii<=m; ii++) {
        memset(s,0,sizeof(s));//��s�����ֵ��� 
        s[ii]='1';//���ii 
        memset(bj,0,sizeof(bj));//��bj������� 
        for(int j=1; j<=n; j++)
            bj[j]=a[ii][j]; 
        dfs(ii,1);//���� 
    }
    cout<<js<<" ";
    for(int i=1; i<=m; i++) {
        if(l[i]=='1')//�����i����ǹ� 
            cout<<i<<" ";//��� 
    }
    return 0;
}
