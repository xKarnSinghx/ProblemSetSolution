/*
E. Singers' Tour
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
n towns are arranged in a circle sequentially. The towns are numbered from 1 to n in clockwise order. In the i-th town, there lives a singer with a repertoire of ai minutes for each i∈[1,n].

Each singer visited all n towns in clockwise order, starting with the town he lives in, and gave exactly one concert in each town. In addition, in each town, the i-th singer got inspired and came up with a song that lasts ai minutes. The song was added to his repertoire so that he could perform it in the rest of the cities.

Hence, for the i-th singer, the concert in the i-th town will last ai minutes, in the (i+1)-th town the concert will last 2⋅ai minutes, ..., in the ((i+k)modn+1)-th town the duration of the concert will be (k+2)⋅ai, ..., in the town ((i+n−2)modn+1) — n⋅ai minutes.

You are given an array of b integer numbers, where bi is the total duration of concerts in the i-th town. Reconstruct any correct sequence of positive integers a or say that it is impossible.

Input
The first line contains one integer t (1≤t≤103) — the number of test cases. Then the test cases follow.

Each test case consists of two lines. The first line contains a single integer n (1≤n≤4⋅104) — the number of cities. The second line contains n integers b1,b2,…,bn (1≤bi≤109) — the total duration of concerts in i-th city.

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print the answer as follows:

If there is no suitable sequence a, print NO. Otherwise, on the first line print YES, on the next line print the sequence a1,a2,…,an of n integers, where ai (1≤ai≤109) is the initial duration of repertoire of the i-th singer. If there are multiple answers, print any of them.

Example
inputCopy
4
3
12 16 14
1
1
3
1 2 3
6
81 75 75 93 93 87
outputCopy
YES
3 1 3 
YES
1 
NO
YES
5 5 4 1 4 5 
Note
Let's consider the 1-st test case of the example:

the 1-st singer in the 1-st city will give a concert for 3 minutes, in the 2-nd — for 6 minutes, in the 3-rd — for 9 minutes;
the 2-nd singer in the 1-st city will give a concert for 3 minutes, in the 2-nd — for 1 minute, in the 3-rd - for 2 minutes;
the 3-rd singer in the 1-st city will give a concert for 6 minutes, in the 2-nd — for 9 minutes, in the 3-rd — for 3 minutes.
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
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000100;
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
ll ask(ll x, ll y) {
	cout << "?" << " ";
	cout << x << " " << y << endl;
	ll s;
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
ll power(ll n, ll x) {
	ll ans = 1;
	foi(n) {
		ans *= x;
	}
	return ans;
}
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	ll s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	if (s % (n * (n + 1) / 2)) {
		cout << "NO";
		return;
	}
	s /= (n * (n + 1) / 2);
	vll ans(n);
	foi(n) {
		if ((a[i] - a[(i + 1) % n] + s) % n or (a[i] - a[(i + 1) % n] + s) <= 0) {
			cout << "NO";
			return;
		}
		ans[(i + 1) % n] = (a[i] - a[(i + 1) % n] + s) / n;
	}
	cout << "YES" << endl;
	foi(n) {
		cout << ans[i] << " ";
	}

}
