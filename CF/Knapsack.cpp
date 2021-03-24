/*
C. Knapsack
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a knapsack with the capacity of W. There are also n items, the i-th one has weight wi.

You want to put some of these items into the knapsack in such a way that their total weight C is at least half of its size, but (obviously) does not exceed it. Formally, C should satisfy: ⌈W2⌉≤C≤W.

Output the list of items you will put into the knapsack or determine that fulfilling the conditions is impossible.

If there are several possible lists of items satisfying the conditions, you can output any. Note that you don't have to maximize the sum of weights of items in the knapsack.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains integers n and W (1≤n≤200000, 1≤W≤1018).

The second line of each test case contains n integers w1,w2,…,wn (1≤wi≤109) — weights of the items.

The sum of n over all test cases does not exceed 200000.

Output
For each test case, if there is no solution, print a single integer −1.

If there exists a solution consisting of m items, print m in the first line of the output and m integers j1, j2, ..., jm (1≤ji≤n, all ji are distinct) in the second line of the output  — indices of the items you would like to pack into the knapsack.

If there are several possible lists of items satisfying the conditions, you can output any. Note that you don't have to maximize the sum of weights items in the knapsack.

Example
inputCopy
3
1 3
3
6 2
19 8 19 69 9 4
7 12
1 1 1 17 1 1 1
outputCopy
1
1
-1
6
1 2 3 5 6 7
Note
In the first test case, you can take the item of weight 3 and fill the knapsack just right.

In the second test case, all the items are larger than the knapsack's capacity. Therefore, the answer is −1.

In the third test case, you fill the knapsack exactly in half.


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
	ll n, c;
	cin >> n >> c ;
	vpll a(n);
	vll b;
	foi(n) {
		cin >> a[i].ff;
		a[i].ss = i + 1;
	}
	ll f = 0, s = 0;
	foi(n) {
		if (2 * a[i].ff >= c and a[i].ff <= c) {
			cout << 1 << endl;
			cout << a[i].ss;
			return;
		}

		if (a[i].ff > c) {
			continue;
		}
		else {
			if (2 * s < c) {
				s += a[i].ff;
				b.pb(a[i].ss);
				if (2 * s >= c) {
					f = 1;
				}
			}
		}

	}
	if (f == 0)
		cout << -1;
	else {
		cout << b.size() << endl;
		foi(b.size()) {
			cout << b[i] << " ";

		}
	}
}


