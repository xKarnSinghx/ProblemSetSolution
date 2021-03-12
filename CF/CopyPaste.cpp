/*A. Copy-paste
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
— Hey folks, how do you like this problem?
— That'll do it.

BThero is a powerful magician. He has got n piles of candies, the i-th pile initially contains ai candies. BThero can cast a copy-paste spell as follows:

He chooses two piles (i,j) such that 1≤i,j≤n and i≠j.
All candies from pile i are copied into pile j. Formally, the operation aj:=aj+ai is performed.
BThero can cast this spell any number of times he wants to — but unfortunately, if some pile contains strictly more than k candies, he loses his magic power. What is the maximum number of times BThero can cast the spell without losing his power?

Input
The first line contains one integer T (1≤T≤500) — the number of test cases.

Each test case consists of two lines:

the first line contains two integers n and k (2≤n≤1000, 2≤k≤104);
the second line contains n integers a1, a2, ..., an (1≤ai≤k).
It is guaranteed that the sum of n over all test cases does not exceed 1000, and the sum of k over all test cases does not exceed 104.

Output
For each test case, print one integer — the maximum number of times BThero can cast the spell without losing his magic power.

Example
inputCopy
3
2 2
1 1
3 5
1 2 3
3 7
3 2 2
outputCopy
1
5
4
Note
In the first test case we get either a=[1,2] or a=[2,1] after casting the spell for the first time, and it is impossible to cast it again.

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
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
vector<int> G[100005];
ll b[100005], f;
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

void solve()
{

	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		while (a[i] + a[0] <= k) {
			a[i] += a[0];
			ans++;
		}
	}
	cout << ans;

}

