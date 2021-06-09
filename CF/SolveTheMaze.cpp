/*
D. Solve The Maze
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vivek has encountered a problem. He has a maze that can be represented as an n×m grid. Each of the grid cells may represent the following:

Empty — '.'
Wall — '#'
Good person  — 'G'
Bad person — 'B'
The only escape from the maze is at cell (n,m).

A person can move to a cell only if it shares a side with their current cell and does not contain a wall. Vivek wants to block some of the empty cells by replacing them with walls in such a way, that all the good people are able to escape, while none of the bad people are able to. A cell that initially contains 'G' or 'B' cannot be blocked and can be travelled through.

Help him determine if there exists a way to replace some (zero or more) empty cells with walls to satisfy the above conditions.

It is guaranteed that the cell (n,m) is empty. Vivek can also block this cell.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n, m (1≤n,m≤50) — the number of rows and columns in the maze.

Each of the next n lines contain m characters. They describe the layout of the maze. If a character on a line equals '.', the corresponding cell is empty. If it equals '#', the cell has a wall. 'G' corresponds to a good person and 'B' corresponds to a bad person.

Output
For each test case, print "Yes" if there exists a way to replace some empty cells with walls to satisfy the given conditions. Otherwise print "No"

You may print every letter in any case (upper or lower).

Example
inputCopy
6
1 1
.
1 2
G.
2 2
#B
G.
2 3
G.#
B#.
3 3
#B.
#..
GG.
2 2
#B
B.
outputCopy
Yes
Yes
No
No
Yes
Yes
Note
For the first and second test cases, all conditions are already satisfied.

For the third test case, there is only one empty cell (2,2), and if it is replaced with a wall then the good person at (1,2) will not be able to escape.

For the fourth test case, the good person at (1,1) cannot escape.

For the fifth test case, Vivek can block the cells (2,3) and (2,2).

For the last test case, Vivek can block the destination cell (2,2).
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
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t ; cin >> t;
	while (t--)
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
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
ll n, m;
ll v[102][102] = {}, b[102][102] = {};
void dfs(ll x, ll y) {
	if (v[x][y] or b[x][y])
		return;
	v[x][y] = 1;
	if (x > 1)
	dfs(x - 1, y);
	if (x < n)
	dfs(x + 1, y);
	if (y > 1)
	dfs(x, y - 1);
	if (y < m)
	dfs(x, y + 1);
}
void solve() {
	cin >> n >> m;
	char a[n + 1][m + 1];
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	for (ll i = 0; i <= n + 1; i++) {
		for (ll j = 0; j <= m + 1; j++) {
			b[i][j] = v[i][j] = 0;
		}
	}
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= m; j++) {
			if (a[i][j] == '#')
				b[i][j] = 1;
			if (a[i][j] == 'B') {
				b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] = b[i][j + 1] = 1;
			}
		}
	dfs(n, m);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (a[i][j] == 'G' and v[i][j] == 0) {
				cout << "No";
				return;
			}
		}
	}
	cout << "Yes";
}
