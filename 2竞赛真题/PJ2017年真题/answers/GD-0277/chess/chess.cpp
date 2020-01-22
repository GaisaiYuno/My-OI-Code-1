#include <iostream>
#include <fstream>
using namespace std;

#define cin is
#define cout os
ifstream is("chess.in");
ofstream os("chess.out");

#define MAX 105

int m, n;
int mem[MAX][MAX],book[MAX][MAX];
int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};
int mincost=99999999;
bool mf=true, fail;

typedef struct ij{
	int i, j, c;
	bool mf;
}ij;

ij list[MAX*MAX];
int h, t;

void bfs(){
	while (h<t){
		int i=list[h].i;
		int j=list[h].j;
		
		
		int x, y;
		for (int p=0; p<4; p++){
			int c=list[h].c;
			y=i+yy[p]; x=j+xx[p];
			if (!book[y][x] && y>=1 && x>=1 && y<=m && x<=m){
				if (mem[i][j]!=mem[y][x]){
					if (mem[y][x]!=0){
						c++;
						list[t].mf = true;
					}else if(list[h].mf){
						list[t].mf=false;
						mem[y][x]=mem[i][j];
						c+=2;
					}
					else continue;
				}
				list[t].i=y;
				list[t].j=x;
				list[t].c=c;
				if (y==m && x==m){
					if (c<mincost){
						mincost=c;
					}
				}
				bool flag=false;
				for (int i=0; i<t-1; i++){
					if (list[i].i==y&&list[i].j==x){
						flag=true;
						break;
					}
				}
				if (!flag)
					t++;
			}
		}
		h++;
		if (h==t && (i!=m || j!=m)){
			fail=true;
			cout<<-1<<endl;
		}
	}
	
}

int main(){
	int a, b, c;
	cin>>m>>n;
	for (int i=0; i<n; i++){
		cin>>a>>b>>c;
		mem[b][a]=c+1;//¸Ä³Éºì1 »Æ2 
	}
	
	//bfs(1,1,0);
	list[0].i=list[0].j=1;
	list[0].c=0;
	list[0].mf=true;
	t++;
	bfs();
	if (!fail)
		cout<<mincost<<endl;
	is.close();
	os.close();
	return 0;
}
