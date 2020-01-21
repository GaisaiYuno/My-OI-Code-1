/*
  Solution for DIC (Dice contest)
  Tomek Czajka

  The solution:
  - enumerate dice states; by state we mean orientation and y-position
    of the die; there are 96 states
  - generate the state graph; edges represent rolling the die; for
    each edge we have the weight and dx (change in x-position; can
    be -1,0,+1)
  - the problem is to find the shortest path length from the start
    state to one of the end states (final orientation does not matter),
    with total dx given (x2-x1); x2-x1>=0 (if x2<x1, we do mirror reflection
    of the problem)
  - first we find shortest path lengths with dx=0 and dx=1, for each
    pair of states, using Dijkstra algorithm; we don't know how far
    left or right it might be useful to go, so it is a Dijkstra on
    an infinite graph of states * x-positions;
    I don't know how long this can take; we stop as soon as we reach
    all reachable states with x=0 or x=1; only half of the states are
    reachable (the sum of dots on top, front and left side of the die
    changes parity with each move)
  - from the shortest paths for dx=k, we can calculate shortest paths
    for dx=2k and dx=2k+1 in O(n^3) time; we get the shortest paths
    for the given dx=x2-x1 in O(n^3 * log(x2-x1)) time
*/

#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const long long INF = 1LL << 60; // infinity
const int MAXY = 4; // width of the ribbon
const int NSTATES = 24 * MAXY; // number of states

struct State {
  int y; // y position
  int top,front,left; // dots on top,front,left sides
  State() {}
  State(int y,int t,int f,int l):y(y),top(t),front(f),left(l) {}
};

struct Edge {
  int s;       // new state
  int dx;      // can be -1,0,+1
  long long w; // weight
  Edge() {}
  Edge(int s,int dx,long long w):s(s),dx(dx),w(w) {}
};

/* INPUT DATA */
long long dieNumbers[7]; // numbers on the sides of the die [1..6]
int startx,starty,endx,endy; // start and end positions

/* REST OF GLOBALS */
vector<Edge> edges[NSTATES]; // state graph
long long dx01[2][NSTATES][NSTATES]; // path lengths for dx=0 or 1
long long paths[NSTATES][NSTATES]; // shortest path lengths for some given dx


void read() {
  for(int i=1;i<=6;++i)
    scanf("%lld",&dieNumbers[i]);
  scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
}

// is the die properly oriented (as in the picture) ?
bool goodOrientation(int top,int front,int left) {
      if(top)
}


// State -> 0..NSTATES-1
int encodeState(const State &s) {

}

// 0..NSTATES-1 -> State
State decodeState(int x) {
 
}

void calcGraph() {
 
}

// for calc01 Dijkstra algorithm
struct QueueElem {
  long long d; // distance
  int x;       // x position
  int s;       // state
  QueueElem() {}
  QueueElem(long long d,int x,int s):d(d),x(x),s(s) {}
};

inline bool operator<(const QueueElem &a, const QueueElem &b) {
  return a.d > b.d;
}

/* Dijkstra algorithm, start with state s, calculate dx01[...][s][...] */
void calc01(int start) {
    priority_queue<QueueElem>q;
	q.push(start,1,0);

}

// join paths given by a and b, result in paths
void joinPaths(long long a[NSTATES][NSTATES], long long b[NSTATES][NSTATES]) {
  
}

// calculate paths[][] for given dx>=0
void calcPaths(int dx) {
 
}

// assumes paths is calculated for dx=endx-startx
long long calcResult() {
 
}

int main() {
  read();
  if(startx > endx) {
    // mirror reflection
    swap(startx,endx);
    swap(dieNumbers[3],dieNumbers[4]);
  };
  calcGraph();
  for(int x=0;x<NSTATES;++x)
    calc01(x);
  calcPaths(endx-startx);
  long long res = calcResult();
  printf("%lld\n",res);
}
