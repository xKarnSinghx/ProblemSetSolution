/*
B. Find the Spruce
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Holidays are coming up really soon. Rick realized that it's time to think about buying a traditional spruce tree. But Rick doesn't want real trees to get hurt so he decided to find some in an n×m matrix consisting of "*" and ".".


To find every spruce first let's define what a spruce in the matrix is. A set of matrix cells is called a spruce of height k with origin at point (x,y) if:

All cells in the set contain an "*".
For each 1≤i≤k all cells with the row number x+i−1 and columns in range [y−i+1,y+i−1] must be a part of the set. All other cells cannot belong to the set.
Examples of correct and incorrect spruce trees:


Now Rick wants to know how many spruces his n×m matrix contains. Help Rick solve this problem.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤10).

The first line of each test case contains two integers n and m (1≤n,m≤500) — matrix size.

Next n lines of each test case contain m characters ci,j — matrix contents. It is guaranteed that ci,j is either a "." or an "*".

It is guaranteed that the sum of n⋅m over all test cases does not exceed 5002 (∑n⋅m≤5002).

Output
For each test case, print single integer — the total number of spruces in the matrix.

Example
inputCopy
4
2 3
.*.
***
2 3
.*.
**.
4 5
.***.
*****
*****
*.*.*
5 7
..*.*..
.*****.
*******
.*****.
..*.*..
outputCopy
5
3
23
34
Note
In the first test case the first spruce of height 2 has its origin at point (1,2), the second spruce of height 1 has its origin at point (1,2), the third spruce of height 1 has its origin at point (2,1), the fourth spruce of height 1 has its origin at point (2,2), the fifth spruce of height 1 has its origin at point (2,3).

In the second test case the first spruce of height 1 has its origin at point (1,2), the second spruce of height 1 has its origin at point (2,1), the third spruce of height 1 has its origin at point (2,2).*/
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
void solve() {
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	foi(n) {
		foj(m) {
			char x;
			cin >> x;
			if (x == '*')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	for (ll i = n - 1; i > 0; i--) {
		for (ll j = 1; j < m - 1; j++) {
			if (a[i - 1][j])
				a[i - 1][j] += min(a[i][j - 1], min(a[i][j], a[i][j + 1]));
		}
	}
	ll ans = 0;
	foi(n) {
		foj(m) {
			ans += a[i][j];
		}
	}
	cout << ans;
}



