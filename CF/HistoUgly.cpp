/*
\B. Histogram Ugliness
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Dormi received a histogram with n bars of height a1,a2,…,an for Christmas. However, the more he played with his new histogram, the more he realized its imperfections, so today he wanted to modify it to his liking.

To modify the histogram, Little Dormi is able to perform the following operation an arbitrary number of times:

Select an index i (1≤i≤n) where ai>0, and assign ai:=ai−1.
Little Dormi defines the ugliness score of his histogram (after performing some number of operations) as the sum of the vertical length of its outline and the number of operations he performed on it. And to make the histogram as perfect as possible, he would like to minimize the ugliness score after modifying it with some number of operations.

However, as his histogram is very large, Little Dormi is having trouble minimizing the ugliness score, so as Little Dormi's older brother, help him find the minimal ugliness.

Consider the following example where the histogram has 4 columns of heights 4,8,9,6:


The blue region represents the histogram, and the red lines represent the vertical portion of the outline. Currently, the vertical length of the outline is 4+4+1+3+6=18, so if Little Dormi does not modify the histogram at all, the ugliness would be 18.

However, Little Dormi can apply the operation once on column 2 and twice on column 3, resulting in a histogram with heights 4,7,7,6:


Now, as the total vertical length of the outline (red lines) is 4+3+1+6=14, the ugliness is 14+3=17 dollars. It can be proven that this is optimal.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤4⋅105).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 4⋅105.

Output
For each test case output one integer, the minimal ugliness Little Dormi can achieve with the histogram in that test case.

Example
inputCopy
2
4
4 8 9 6
6
2 1 7 4 0 0
outputCopy
17
12
Note
Example 1 is the example described in the statement.

The initial histogram for example 2 is given below:


The ugliness is currently 2+1+6+3+4=16.

By applying the operation once on column 1, six times on column 3, and three times on column 4, we can end up with a histogram with heights 1,1,1,1,0,0:


The vertical length of the outline is now 1+1=2 and Little Dormi made 1+6+3=10 operations, so the final ugliness is 2+10=12, which can be proven to be optimal.


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
void solve() {
	/*	ll n, m;
		cin >> n >> m;
		ll a[n][m], f = 0;
		foi(n) {
			foj(m) {
				char c;
				cin >> c;
				if (c == '.')
					a[i][j] = 0;
				else if (c == 'R')
					a[i][j] = 1, f = 1;
				else
					a[i][j] = 2, f = 1;
			}
		}
		if (f == 0) {
			cout << "Yes" << endl;
			foi(n) {
				foj(m) {
					if ((i + j) % 2)
						cout << "R";
					else
						cout << "W";
				}
				cout << endl;
			}
		}
	*/
	ll n;
	cin >> n;
	vll a(n);
	ll ans = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (n == 1) {
			cout << x;
			return;
		}
		if (i == 0) {
			ans += a[i];
		}
		else {
			ans += abs(a[i - 1] - a[i]);
		}
	}
	ans += a[n - 1];
	foi(n) {
		if (i == 0) {
			ans -= max(a[i] - a[i + 1], 0ll);
		}
		else if (i > 0 and i < n - 1) {
			ans -= max(a[i] - max(a[i - 1], a[i + 1]), 0ll);
		}
		else {
			ans -= max(a[i] - a[i - 1], 0ll);
		}
	}
	cout << ans;
}
