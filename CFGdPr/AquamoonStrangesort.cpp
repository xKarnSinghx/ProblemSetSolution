/*
C. AquaMoon and Strange Sort
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
AquaMoon has n friends. They stand in a row from left to right, and the i-th friend from the left wears a T-shirt with a number ai written on it. Each friend has a direction (left or right). In the beginning, the direction of each friend is right.

AquaMoon can make some operations on friends. On each operation, AquaMoon can choose two adjacent friends and swap their positions. After each operation, the direction of both chosen friends will also be flipped: left to right and vice versa.

AquaMoon hopes that after some operations, the numbers written on the T-shirt of n friends in the row, read from left to right, become non-decreasing. Also she wants, that all friends will have a direction of right at the end. Please find if it is possible.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤50) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤105) — the number of Aquamoon's friends.

The second line contains n integers a1,a2,…,an (1≤ai≤105) — the numbers, written on the T-shirts.

It is guaranteed that the sum of n for all test cases does not exceed 105.

Output
For each test case, if there exists a possible sequence of operations, print "YES" (without quotes); otherwise, print "NO" (without quotes).

You can print each letter in any case (upper or lower).

Example
inputCopy
3
4
4 3 2 5
4
3 3 2 2
5
1 2 3 5 4
outputCopy
YES
YES
NO
Note
The possible list of operations in the first test case:

Swap a1 and a2. The resulting sequence is 3,4,2,5. The directions are: left, left, right, right.
Swap a2 and a3. The resulting sequence is 3,2,4,5. The directions are: left, left, right, right.
Swap a1 and a2. The resulting sequence is 2,3,4,5. The directions are: right, right, right, right.

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
typedef  unordered_map< ll, ld>           umld;
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

void solve() {
	ll n;
	cin >> n;
	vll o, e;
	foi(n)
	{
		ll x;
		cin >> x;
		if (i % 2 )
			o.pb(x);
		else
			e.pb(x);
	}
	sort(all(o)), sort(all(e));
	vll ans(n, 0);
	foi(o.size()) {
		ans[2 * i + 1] = o[i];
	}
	foi(e.size()) {
		ans[2 * i] = e[i];
	}
	vll ans1 = ans;
	sort(all(ans1));
	if (ans == ans1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

