/*
C. Powered Addition
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have an array a of length n. For every positive integer x you are going to perform the following operation during the x-th second:

Select some distinct indices i1,i2,…,ik which are between 1 and n inclusive, and add 2x−1 to each corresponding position of a. Formally, aij:=aij+2x−1 for j=1,2,…,k. Note that you are allowed to not select any indices at all.
You have to make a nondecreasing as fast as possible. Find the smallest number T such that you can make the array nondecreasing after at most T seconds.

Array a is nondecreasing if and only if a1≤a2≤…≤an.

You have to answer t independent test cases.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains single integer n (1≤n≤105) — the length of array a. It is guaranteed that the sum of values of n over all test cases in the input does not exceed 105.

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109).

Output
For each test case, print the minimum number of seconds in which you can make a nondecreasing.

Example
inputCopy
3
4
1 7 6 5
5
1 2 3 4 5
2
0 -4
outputCopy
2
0
3
Note
In the first test case, if you select indices 3,4 at the 1-st second and 4 at the 2-nd second, then a will become [1,7,7,8]. There are some other possible ways to make a nondecreasing in 2 seconds, but you can't do it faster.

In the second test case, a is already nondecreasing, so answer is 0.

In the third test case, if you do nothing at first 2 seconds and select index 2 at the 3-rd second, a will become [0,0].


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
ll cal(ll a, ll b, ll c) {
	return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}
void solve() {
	ll n;
	cin >> n;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	vll b = a;
	sort(all(b));
	ll ans = 0;
	foi(n) {
		if (a[i] != b[i])
			ans++;
	}
	if (ans == 0) {
		cout << 0;
		return;
	}
	ll cnt = 0, mx = -1111111111111;
	foi(n - 1) {
		mx = max(a[i], mx);
		if (a[i + 1] >= mx)
			continue;
		else {
			cnt = max(cnt, abs(mx - a[i + 1]));
		}
	}
	ans = 1;
	while (cnt > 0) {
		cnt -= pow(2, ans - 1);
		if (cnt <= 0)
			break;
		ans++;
	}
	cout << ans;
}

