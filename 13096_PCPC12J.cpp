/*
TASK: Amr Samir
ALGO: ad-hoc
Sample Input
2
5
2 2 3 3 3
7
2 2 2 2 3 3 3
Sample Output
3
2
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;


int main() {
	int T,n,u;
	int cn[110];
	cin>>T;
	while(T--) {
		cin>>n;
		CLR(cn);
		while(n--) {
			cin>>u;
			cn[u]++;
		}
		int i,r=-1,v=-1;
		for(i=0;i<=100;i++)
        {
            if(cn[i] && !(cn[i]%i) && (cn[i]>r || (cn[i]==r && i<v))) 
            {
                r=cn[i];
                v=i;
            }
        }
		cout<<v<<'\n';
	}
	return 0;
}
