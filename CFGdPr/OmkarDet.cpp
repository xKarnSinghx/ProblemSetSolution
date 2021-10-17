/*
C. Omkar and Determination
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The problem statement looms below, filling you with determination.

Consider a grid in which some cells are empty and some cells are filled. Call a cell in this grid exitable if, starting at that cell, you can exit the grid by moving up and left through only empty cells. This includes the cell itself, so all filled in cells are not exitable. Note that you can exit the grid from any leftmost empty cell (cell in the first column) by going left, and from any topmost empty cell (cell in the first row) by going up.

Let's call a grid determinable if, given only which cells are exitable, we can exactly determine which cells are filled in and which aren't.

You are given a grid a of dimensions n×m , i. e. a grid with n rows and m columns. You need to answer q queries (1≤q≤2⋅105). Each query gives two integers x1,x2 (1≤x1≤x2≤m) and asks whether the subgrid of a consisting of the columns x1,x1+1,…,x2−1,x2 is determinable.

Input
The first line contains two integers n,m (1≤n,m≤106, nm≤106)  — the dimensions of the grid a.

n lines follow. The y-th line contains m characters, the x-th of which is 'X' if the cell on the intersection of the the y-th row and x-th column is filled and "." if it is empty.

The next line contains a single integer q (1≤q≤2⋅105)  — the number of queries.

q lines follow. Each line contains two integers x1 and x2 (1≤x1≤x2≤m), representing a query asking whether the subgrid of a containing the columns x1,x1+1,…,x2−1,x2 is determinable.

Output
For each query, output one line containing "YES" if the subgrid specified by the query is determinable and "NO" otherwise. The output is case insensitive (so "yEs" and "No" will also be accepted).

Example
inputCopy
4 5
..XXX
...X.
...X.
...X.
5
1 3
3 3
4 5
5 5
1 5
outputCopy
YES
YES
NO
YES
NO
Note
For each query of the example, the corresponding subgrid is displayed twice below: first in its input format, then with each cell marked as "E" if it is exitable and "N" otherwise.

For the first query:


..X EEN
... EEE
... EEE
... EEE


For the second query:


X N
. E
. E
. E
Note that you can exit the grid by going left from any leftmost cell (or up from any topmost cell); you do not need to reach the top left corner cell to exit the grid.



For the third query:


XX NN
X. NN
X. NN
X. NN
This subgrid cannot be determined only from whether each cell is exitable, because the below grid produces the above "exitability grid" as well:


XX
XX
XX
XX


For the fourth query:


X N
. E
. E
. E


For the fifth query:


..XXX EENNN
...X. EEENN
...X. EEENN
...X. EEENN
This query is simply the entire grid. It cannot be determined only from whether each cell is exitable because the below grid produces the above "exitability grid" as well:


..XXX
...XX
...XX
...XX

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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 200010;
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
//	while (t--)
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
	cin >> s;
	return s;
}
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
void solve() {
	ll n, m;
	cin >> n >> m;
	char a[n][m];
	foi(n) {
		foj(m) {
			cin >> a[i][j];
		}
	}
	vll s(m + 1, 0);
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < m; j++) {
			if (a[i - 1][j] == 'X' and a[i][j - 1] == 'X') {
				s[j + 1] = 1;
			}
		}
	}
	foi(m + 1) {
		if (i < 2)
			continue;
		s[i] += s[i - 1];
	}
	ll q;
	cin >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		if (s[x] == s[y]) {
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
}


 
