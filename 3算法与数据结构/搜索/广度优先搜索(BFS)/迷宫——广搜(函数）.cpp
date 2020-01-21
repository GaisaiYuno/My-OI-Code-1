bool flag;
void bfs(){ 
do {//此为模板 
        int head=0;
		int tail=0;
		flag=false;
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		p[0]=1;
		q[0]=1;
		int x=1,y=1;
		f[1][1]=1;
		for(int a=0; a<4; a++) {
			 x=p[head]+xx[a];
			 y=q[head]+yy[a];
			if(x>0&&x<=m&&y>0&&y<=n&&f[x][y]==0) {
					tail++;//进队
					p[tail]=x;
					q[tail]=y;
					f[x][y]=1;
				if(x==x2&&y==y2) {
					flag=true;
					return;
				}
			}
		}
		head++;//出队
	} while(head<=tail);
	return;
} 
