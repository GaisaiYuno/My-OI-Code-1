#include<bits/stdc++.h>

using namespace std;

namespace StandardIO {

    template<typename T>inline void read (T &x) {
        x=0;T f=1;char c=getchar();
        for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
        for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
        x*=f;
    }

    template<typename T>inline void write (T x) {
        if (x<0) putchar('-'),x*=-1;
        if (x>=10) write(x/10);
        putchar(x%10+'0');
    }

}

using namespace StandardIO;

namespace Solve {
	
	/*
		Genetic Algorithm
		Time Complexity : O(ljz)
	*/
	
	const int N=252;
	const int INF=0x3f3f3f3f;
	const int COLONY=1001;
	
	int n,W;
	int w[N],t[N];
	
	struct Darwin {
		int SIZE;
		double best=0.0;
		struct gene {
			int DNA[N];
			double score;
		}mass[COLONY];
		
		inline void calc_score (gene &a) {
			a.score=0;
			int high=0,low=0,cnt=0;
			for (register int i=1; i<=n; ++i) {
				high+=a.DNA[i]*t[i];
				low+=a.DNA[i]*w[i];
			}
			if (low>=W) a.score=(double)high/(double)low;
			else a.score=-1;
		}
		
		inline void gen_colony (int size) {
			SIZE=size;
			for (register int i=1; i<=SIZE; ++i) {
				for (register int j=1; j<=n; ++j) {
					mass[i].DNA[j]=rand()%2;
				}
				calc_score(mass[i]);
			}
		}
		
		inline pair<int,int> choose () {
			double big=0,sec=0;int bigi,seci;
			for (register int i=1; i<=SIZE;++i) {
				if (mass[i].score>big) {
					sec=big,big=mass[i].score;
					seci=bigi,bigi=i;
				}
			}
			return make_pair(bigi,seci);
		}
		
		inline pair<int,int> worst () {
			double sma=INF,sec=INF;int smai,seci;
			for (register int i=1; i<=SIZE;++i) {
				if (mass[i].score<sma) {
					sec=sma,sma=mass[i].score;
					seci=smai,smai=i;
				}
			}
			return make_pair(smai,seci);
			
		}
		
		inline void breed (gene &a,gene &b) {
			int f=0,s=0;
			while (f==s) {
				f=rand()%n+1,s=rand()%n+1;
			}
			if (s<f) swap(s,f);
			for (register int i=f; i<=s; ++i) {
				swap(a.DNA[i],b.DNA[i]);
			}
			calc_score(a),calc_score(b);
		}
		
		inline void mutant (gene &a) {
			int f=rand()%n+1,s=rand()%n+1;
			a.DNA[f]^=1,a.DNA[s]^=1;
			calc_score(a);
		}
		
		inline double Evolve (int times) {
			for (register int i=1; i<=times; ++i) {
				pair<int,int>res=choose();
				pair<int,int>shit=worst();
				best=max(best,mass[res.first].score);
				mass[shit.first]=mass[res.first];
				mass[shit.second]=mass[res.second];
				int poss=rand()%100+1;
				if (poss>=90) breed(mass[res.first],mass[res.second]);
				else mutant(mass[res.first]);
			}
			return max(best,mass[choose().first].score);
		}
	};
	

    inline void solve () {
		srand((unsigned)time(NULL));
		read(n),read(W);
		for (register int i=1; i<=n; ++i) {
			read(w[i]),read(t[i]);
		}
		Darwin ljz;
		ljz.gen_colony(1000);
		write((int)(ljz.Evolve(100000)*1000));
    }
}

using namespace Solve;

int main () {
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
    solve();
}


