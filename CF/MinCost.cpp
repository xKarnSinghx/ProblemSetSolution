/*
B. Minimal Cost
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a graph of n rows and 106+2 columns, where rows are numbered from 1 to n and columns from 0 to 106+1:


Let's denote the node in the row i and column j by (i,j).

Initially for each i the i-th row has exactly one obstacle — at node (i,ai). You want to move some obstacles so that you can reach node (n,106+1) from node (1,0) by moving through edges of this graph (you can't pass through obstacles). Moving one obstacle to an adjacent by edge free node costs u or v coins, as below:

If there is an obstacle in the node (i,j), you can use u coins to move it to (i−1,j) or (i+1,j), if such node exists and if there is no obstacle in that node currently.
If there is an obstacle in the node (i,j), you can use v coins to move it to (i,j−1) or (i,j+1), if such node exists and if there is no obstacle in that node currently.
Note that you can't move obstacles outside the grid. For example, you can't move an obstacle from (1,1) to (0,1).
Refer to the picture above for a better understanding.

Now you need to calculate the minimal number of coins you need to spend to be able to reach node (n,106+1) from node (1,0) by moving through edges of this graph without passing through obstacles.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains three integers n, u and v (2≤n≤100, 1≤u,v≤109) — the number of rows in the graph and the numbers of coins needed to move vertically and horizontally respectively.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — where ai represents that the obstacle in the i-th row is in node (i,ai).

It's guaranteed that the sum of n over all test cases doesn't exceed 2⋅104.

Output
For each test case, output a single integer — the minimal number of coins you need to spend to be able to reach node (n,106+1) from node (1,0) by moving through edges of this graph without passing through obstacles.

It can be shown that under the constraints of the problem there is always a way to make such a trip possible.

Example
inputCopy
3
2 3 4
2 2
2 3 4
3 2
2 4 3
3 2
outputCopy
7
3
3
Note
In the first sample, two obstacles are at (1,2) and (2,2). You can move the obstacle on (2,2) to (2,3), then to (1,3). The total cost is u+v=7 coins.


In the second sample, two obstacles are at (1,3) and (2,2). You can move the obstacle on (1,3) to (2,3). The cost is u=3 coins.

*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve()

{

	ll n, u, v;
	cin >> n >> u >> v;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll s1 = 0, f = 0;
	foi(n - 1) {
		if ( a[i] == a[i + 1])
			s1++;
		if (abs(a[i + 1] - a[i]) > 1)
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
		cout << 0;
	else if (s1 == n - 1) {
		cout <<  v + min(u, v);
	}
	else if (a)
		cout << min(u, v);
}


 
