/*
B. Numbers Box
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a rectangular grid with n rows and m columns. The cell located on the i-th row from the top and the j-th column from the left has a value aij written in it.

You can perform the following operation any number of times (possibly zero):

Choose any two adjacent cells and multiply the values in them by −1. Two cells are called adjacent if they share a side.
Note that you can use a cell more than once in different operations.

You are interested in X, the sum of all the numbers in the grid.

What is the maximum X you can achieve with these operations?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of each test case contains two integers n,m (2≤n, m≤10).

The following n lines contain m integers each, the j-th element in the i-th line is aij (−100≤aij≤100).

Output
For each testcase, print one integer X, the maximum possible sum of all the values in the grid after applying the operation as many times as you want.

Example
inputCopy
2
2 2
-1 1
1 1
3 4
0 -1 -2 -3
-1 -2 -3 -4
-2 -3 -4 -5
outputCopy
2
30
Note
In the first test case, there will always be at least one −1, so the answer is 2.

In the second test case, we can use the operation six times to elements adjacent horizontally and get all numbers to be non-negative. So the answer is: 2×1+3×2+3×3+2×4+1×5=30.


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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n][k];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < k; j++) {
			cin >> a[i][j];
		}
	}
	ll s = 0, q = 1111111, s1 = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < k; j++) {
			s += abs(a[i][j]);
			q = min(q, abs(a[i][j]));
			if (a[i][j] < 0)
				s1++;
		}
	}
	if (s1 % 2 == 0)
		cout << s;
	else
		cout << s - 2 * q;
}


