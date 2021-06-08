/*
G. A/B Matrix
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given four positive integers n, m, a, b (1≤b≤n≤50; 1≤a≤m≤50). Find any such rectangular matrix of size n×m that satisfies all of the following conditions:

each row of the matrix contains exactly a ones;
each column of the matrix contains exactly b ones;
all other elements are zeros.
If the desired matrix does not exist, indicate this.

For example, for n=3, m=6, a=2, b=1, there exists a matrix satisfying the conditions above:

∣∣∣∣010100001010001100∣∣∣∣
Input
The first line contains an integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case is described by four positive integers n, m, a, b (1≤b≤n≤50; 1≤a≤m≤50), where n and m are the sizes of the matrix, and a and b are the number of ones for rows and columns, respectively.

Output
For each test case print:

"YES" (without quotes) and the required matrix (if there are several answers, print any) if it exists, or
"NO" (without quotes) if it does not exist.
To print the matrix n×m, print n rows, each of which consists of m numbers 0 or 1 describing a row of the matrix. Numbers must be printed without spaces.

Example
inputCopy
5
3 6 2 1
2 2 2 1
2 2 2 2
4 4 2 2
2 1 1 2
outputCopy
YES
010001
100100
001010
NO
YES
11
11
YES
1100
1100
0011
0011
YES
1
1


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
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll ans[n][m] = {};
	if (a * n != b * m) {
		cout << "No";
		return;
	}
	cout << "Yes" << endl;
	ll x = 0;
	foi(n) {
		foj(a) {
			ans[i][x] = 1;
			x = (x + 1) % m;
		}
	}
	foi(n) {
		foj(m) {
			cout << ans[i][j];
		}
		cout << endl;
	}

}
