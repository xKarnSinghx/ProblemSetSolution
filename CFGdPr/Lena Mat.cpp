/*
D. Lena and Matrix
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lena is a beautiful girl who likes logical puzzles.

As a gift for her birthday, Lena got a matrix puzzle!

The matrix consists of n rows and m columns, and each cell is either black or white. The coordinates (i,j) denote the cell which belongs to the i-th row and j-th column for every 1≤i≤n and 1≤j≤m. To solve the puzzle, Lena has to choose a cell that minimizes the Manhattan distance to the farthest black cell from the chosen cell.

More formally, let there be k≥1 black cells in the matrix with coordinates (xi,yi) for every 1≤i≤k. Lena should choose a cell (a,b) that minimizes
maxi=1k(|a−xi|+|b−yi|).
As Lena has no skill, she asked you for help. Will you tell her the optimal cell to choose?

Input
There are several test cases in the input data. The first line contains a single integer t (1≤t≤10000) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains two integers n and m (2≤n,m≤1000)  — the dimensions of the matrix.

The following n lines contain m characters each, each character is either 'W' or 'B'. The j-th character in the i-th of these lines is 'W' if the cell (i,j) is white, and 'B' if the cell (i,j) is black.

It is guaranteed that at least one black cell exists.

It is guaranteed that the sum of n⋅m does not exceed 106.

Output
For each test case, output the optimal cell (a,b) to choose. If multiple answers exist, output any.

Example
inputCopy
5
3 2
BW
WW
WB
3 3
WWB
WBW
BWW
2 3
BBB
BBB
5 5
BWBWB
WBWBW
BWBWB
WBWBW
BWBWB
9 9
WWWWWWWWW
WWWWWWWWW
BWWWWWWWW
WWWWWWWWW
WWWWBWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWB
outputCopy
2 1
2 2
1 2
3 3
6 5
Note
In the first test case the two black cells have coordinates (1,1) and (3,2). The four optimal cells are (1,2), (2,1), (2,2) and (3,1). It can be shown that no other cell minimizes the maximum Manhattan distance to every black cell.

In the second test case it is optimal to choose the black cell (2,2) with maximum Manhattan distance being 2.


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
typedef vector<ld>          vld;
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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
multiset<ll> Lis(vll a) {
	multiset<ll> S;
	multiset<ll>::iterator it;
	foi(a.size()) {
		S.insert(a[i]);
		it = S.lower_bound(a[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}
void solve() {
	ll n, m;
	cin >> n >> m;
	vpll points;
	foi(n) {
		foj(m) {
			char c;
			cin >> c;
			if (c == 'B')
				points.pb({i, j});
		}
	}
	vpll use(4);
	pll ans;
	ll distmax = 0, cur = LLONG_MAX;
	foi(4) {
		use[i].ff = use[i].ss = -1;
	}
	for (pll x : points) {
		if (use[0].ff == -1 or x.ff + x.ss > use[0].ff + use[0].ss)
			use[0] = x;
		if (use[1].ff == -1 or x.ff + x.ss < use[1].ff + use[1].ss)
			use[1] = x;
		if (use[2].ff == -1 or x.ff - x.ss > use[2].ff - use[2].ss)
			use[2] = x;
		if (use[3].ff == -1 or x.ff - x.ss < use[3].ff - use[3].ss)
			use[3] = x;
	}
	foi(n) {
		foj(m) {
			distmax = 0;
			for (pll x : use) {
				distmax = max(distmax, abs(x.ff - i) + abs(x.ss - j));
			}
			if (distmax < cur) {
				cur = distmax, ans = {i, j};
			}
		}
	}
	cout << ans.ff + 1 << " " << ans.ss + 1;
}
