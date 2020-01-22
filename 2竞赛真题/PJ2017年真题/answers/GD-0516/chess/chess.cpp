#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int CSH=99999999;
int m[101][101]={0},n,i,j,k=0,a,b,c,x;
bool past[101][101];
int digui(int conx,int cony,bool blank,int side)
{
	int t1=CSH,t2=CSH,t3=CSH,t4=CSH,minback=CSH;
	if((conx==x)&&(cony==x)) return -1;
	past[conx][cony]=false;
	if ((!blank)&&(!m[conx][cony])) return 99999999;
	if (!m[conx][cony]) blank=false; else blank=true;
	if ((blank==true)&&(conx>1)&&(past[conx-1][cony]==true)) t1=digui(conx-1,cony,true,1);
	if ((blank==true)&&(cony>1)&&(past[conx][cony-1]==true)) t2=digui(conx,cony-1,true,2);
	if ((blank==true)&&(conx<x)&&(past[conx+1][cony]==true)) t3=digui(conx+1,cony,true,3);
	if ((blank==true)&&(cony<x)&&(past[conx][cony+1]==true)) t4=digui(conx,cony+1,true,4);
	if ((!blank)&&(m[conx-1][cony])&&(conx>1)&&(past[conx-1][cony]))t1=digui(conx-1,cony,false,1);
	if ((!blank)&&(m[conx][cony-1])&&(cony>1)&&(past[conx][cony-1])) t2=digui(conx,cony-1,false,2);
	if ((!blank)&&(m[conx+1][cony])&&(conx<x)&&(past[conx+1][cony]))t3=digui(conx+1,cony,false,3);
	if ((!blank)&&(m[conx][cony+1])&&(cony<x)&&(past[conx][cony+1])) t4=digui(conx,cony+1,false,4);
	
	minback=min(t1,(min(t2,(min(t3,min(t4,minback))))));
	switch(minback)
	{
		case -1:{
			if ((m[x][x]==m[conx][cony])&&(m[x][x]==0)) return 99999999;
			if (m[x][x]==0 && m[conx][cony]!=0) return 2;
			if (m[x][x]!=0 && (!blank)) return 2;
			if (m[x][x]!=0 && blank && (m[x][x]==m[conx][cony])) return 0;
			return 1;
			break;
		}
		case 99999999:return 99999999;break;
		default:{
			switch(side)
			{
				case 1:{
					if (m[conx][cony]!=m[conx+1][cony]) return minback+1;
					return minback;
					break;
				}
				case 2:{
					if (m[conx][cony]!=m[conx][cony+1]) return minback+1;
					return minback;
					break;
				}
				case 3:{
					if (m[conx][cony]!=m[conx-1][cony]) return minback+1;
					return minback;
					break;
				}
				case 4:{
					if (m[conx][cony]!=m[conx][cony+1]) return minback+1;
					return minback;
					break;
				}
				case 5:return minback;break;
			}
			break;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(past,true,sizeof(past));
	cin>>x>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		m[a][b]=(c==1)?2:1;
	}
	if (m[x-1][x]==0 && m[x][x-1]==0 && m[x][x]==0) 
	{
		cout<<-1;
		return 0;
	}
	k=digui(1,1,true,5);
	if (k!=99999999) cout<<k; else cout<<-1;
	return 0;
}
