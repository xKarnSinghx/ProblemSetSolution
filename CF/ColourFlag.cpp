/*
A. Colour the Flag
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Today we will be playing a red and white colouring game (no, this is not the Russian Civil War; these are just the colours of the Canadian flag).

You are given an n×m grid of "R", "W", and "." characters. "R" is red, "W" is white and "." is blank. The neighbours of a cell are those that share an edge with it (those that only share a corner do not count).

Your job is to colour the blank cells red or white so that every red cell only has white neighbours (and no red ones) and every white cell only has red neighbours (and no white ones). You are not allowed to recolour already coloured cells.

Input
The first line contains t (1≤t≤100), the number of test cases.

In each test case, the first line will contain n (1≤n≤50) and m (1≤m≤50), the height and width of the grid respectively.

The next n lines will contain the grid. Each character of the grid is either 'R', 'W', or '.'.

Output
For each test case, output "YES" if there is a valid grid or "NO" if there is not.

If there is, output the grid on the next n lines. If there are multiple answers, print any.

In the output, the "YES"s and "NO"s are case-insensitive, meaning that outputs such as "yEs" and "nO" are valid. However, the grid is case-sensitive.

Example
inputCopy
3
4 6
.R....
......
......
.W....
4 4
.R.W
....
....
....
5 1
R
W
R
W
R
outputCopy
YES
WRWRWR
RWRWRW
WRWRWR
RWRWRW
NO
YES
R
W
R
W
R
Note
The answer for the first example case is given in the example output, and it can be proven that no grid exists that satisfies the requirements of the second example case. In the third example all cells are initially coloured, and the colouring is valid.


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
vll fact(400002, 1);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	for (ll i = 1; i < 400002; i++) {
		fact[i] = (fact[i - 1] * 2) % MOD;
	}
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
void tra(ll x, graph &g, vll & visited) {
	visited[x] = 1;
	for (auto it : g[x]) {
		if (visited[it] == 0) {
			tra(it, g, visited);
		}
	}
}
queue<pll> pqe;
void solve() {
	ll n, m;
	cin >> n >> m;
	ll a[n][m], f = 0, b[n][m] = {};
	foi(n) {
		foj(m) {
			char c;
			cin >> c;
			if (c == '.')
				a[i][j] = 0;
			else if (c == 'R')
				a[i][j] = 1, f = 1, pqe.push(mp(i, j));
			else
				a[i][j] = 2, f = 1, pqe.push(mp(i, j));
		}
	}
	if (f == 0) {
		cout << "Yes" << "\n";
		foi(n) {
			foj(m) {
				if ((i + j) % 2)
					cout << "R";
				else
					cout << "W";
			}
			cout <<  "\n";
		}
		return;
	}
	while (!pqe.empty()) {
		auto it = pqe.front();
		pqe.pop();
		ll x = it.ff, y = it.ss;
		if (b[x][y])
			continue;
		b[x][y] = 1;
		for (ll i = -1; i <= 1; i++) {
			for (ll j = -1; j <= 1; j++) {
				if (abs(i) == abs(j))
					continue;
				ll x1 = x + i, y1 = y + j;
				if (x1 < n and x1 >= 0 and y1 < m and y1 >= 0 and b[x1][y1] == 0 and a[x1][y1] == 0) {
					ll t;
					if (a[x][y] == 1) {
						t = 2;
					}
					else {
						t = 1;
					}
					a[x1][y1] = t;
					pqe.push(mp(x1, y1));
				}
			}
		}
	}
	foi(n) {
		foj(m) {
			if (i) {
				if (a[i - 1][j] == a[i][j]) {
					cout << "No";
					return;
				}
			}
			if (i < n - 1) {
				if (a[i + 1][j] == a[i][j]) {
					cout << "No";
					return;
				}
			}
			if (j) {
				if (a[i][j - 1] == a[i][j]) {
					cout << "No";
					return;
				}
			}
			if (j < m - 1) {
				if (a[i][j + 1] == a[i][j]) {
					cout << "No";
					return;
				}
			}
		}
	}
	cout << "Yes" <<  "\n";
	foi(n) {
		foj(m) {
			if (a[i][j] == 2) {
				cout << "W";
			}
			else {
				cout << "R";
			}
		}
		cout <<  "\n";
	}

}
 
