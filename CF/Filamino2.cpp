/*
C. Fillomino 2
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fillomino is a classic logic puzzle. (You do not need to know Fillomino in order to solve this problem.) In one classroom in Yunqi town, some volunteers are playing a board game variant of it:

Consider an n by n chessboard. Its rows are numbered from 1 to n from the top to the bottom. Its columns are numbered from 1 to n from the left to the right. A cell on an intersection of x-th row and y-th column is denoted (x,y). The main diagonal of the chessboard is cells (x,x) for all 1≤x≤n.

A permutation of {1,2,3,…,n} is written on the main diagonal of the chessboard. There is exactly one number written on each of the cells. The problem is to partition the cells under and on the main diagonal (there are exactly 1+2+…+n such cells) into n connected regions satisfying the following constraints:

Every region should be connected. That means that we can move from any cell of a region to any other cell of the same region visiting only cells of the same region and moving from a cell to an adjacent cell.
The x-th region should contain cell on the main diagonal with number x for all 1≤x≤n.
The number of cells that belong to the x-th region should be equal to x for all 1≤x≤n.
Each cell under and on the main diagonal should belong to exactly one region.
Input
The first line contains a single integer n (1≤n≤500) denoting the size of the chessboard.

The second line contains n integers p1, p2, ..., pn. pi is the number written on cell (i,i). It is guaranteed that each integer from {1,…,n} appears exactly once in p1, ..., pn.

Output
If no solution exists, output −1.

Otherwise, output n lines. The i-th line should contain i numbers. The j-th number on the i-th line should be x if cell (i,j) belongs to the the region with x cells.

Examples
inputCopy
3
2 3 1
outputCopy
2
2 3
3 3 1
inputCopy
5
1 2 3 4 5
outputCopy
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
Note
The solutions to the examples are illustrated in the following pictures:

*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

//	ll t ; cin >> t;
	//while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;

}
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll ans[n][n] = {};
	foi(n) {
		ll x = i, y = i, z = a[i];
		while (a[i]--) {
			ans[x][y] = z;
			if (y > 0 and ans[x][y - 1] == 0)
				y--;
			else
				x ++;
		}
	}
	foi(n) {
		foj(i + 1)
		cout << ans[i][j] << " ";
		cout << endl;
	}
}


