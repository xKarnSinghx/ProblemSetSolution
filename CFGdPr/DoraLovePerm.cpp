/*
B. Dreamoon Likes Permutations
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The sequence of m integers is called the permutation if it contains all integers from 1 to m exactly once. The number m is called the length of the permutation.

Dreamoon has two permutations p1 and p2 of non-zero lengths l1 and l2.

Now Dreamoon concatenates these two permutations into another sequence a of length l1+l2. First l1 elements of a is the permutation p1 and next l2 elements of a is the permutation p2.

You are given the sequence a, and you need to find two permutations p1 and p2. If there are several possible ways to restore them, you should find all of them. (Note that it is also possible that there will be no ways.)

Input
The first line contains an integer t (1≤t≤10000) denoting the number of test cases in the input.

Each test case contains two lines. The first line contains one integer n (2≤n≤200000): the length of a. The second line contains n integers a1,a2,…,an (1≤ai≤n−1).

The total sum of n is less than 200000.

Output
For each test case, the first line of output should contain one integer k: the number of ways to divide a into permutations p1 and p2.

Each of the next k lines should contain two integers l1 and l2 (1≤l1,l2≤n,l1+l2=n), denoting, that it is possible to divide a into two permutations of length l1 and l2 (p1 is the first l1 elements of a, and p2 is the last l2 elements of a). You can print solutions in any order.

Example
inputCopy
6
5
1 4 3 2 1
6
2 4 1 3 2 1
4
2 1 1 3
4
1 3 3 1
12
2 1 3 4 5 6 7 8 9 1 10 2
3
1 1 1
outputCopy
2
1 4
4 1
1
4 2
0
0
1
2 10
0
Note
In the first example, two possible ways to divide a into permutations are {1}+{4,3,2,1} and {1,4,3,2}+{1}.

In the second example, the only way to divide a into permutations is {2,4,1,3}+{2,1}.

In the third example, there are no possible ways.
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
void solve() {
	ll n;
	cin >> n;
	vll a(n, 0);
	ll cnt[200001] = {};
	foi(n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	foi(n) {
		if (cnt[a[i]] > 2) {
			cout << 0;
			return;
		}
	}
	ll mx = *max_element(all(a)), mn = *min_element(all(a));
	if (mn != 1 or cnt[1] != 2) {
		cout << 0;
		return;
	}
	for (ll i = mn; i <= mx; i++) {
		if (cnt[i] == 0) {
			cout << 0;
			return;
		}
	}
	ll f = 0;
	for (ll i = mn; i <= mx; i++) {
		if (cnt[i] == 1 and f == 0) {
			f = 1;
		}
		if (cnt[i] == 2 and f == 1) {
			cout << 0;
			return;
		}
	}
	mll m, m1;
	ll ans = 0, s1 = 0, s2 = 0;
	foi(n) {
		if (m[a[i]] == 1)
			s1 = 1;
		if (s1 == 0)
			m[a[i]]++;
		if (s1)
			m1[a[i]]++;
	}
	ll ai = 1, bi = 1, f1 = 0, f2 = 0;
	for (auto x : m) {
		if (m[x.ff] == 0) {
			f1 = 1;
			break;
		}
		ai++;
	}
	for (auto x : m1) {
		if (m1[x.ff] == 0) {
			f2 = 1;
			break;
		}
		bi++;
	}
	ll a1 = 0, b1 = 0;
	if (f1 == 1 or f2 == 1)
		ans = 0;
	else {
		a1 = ai, b1 = bi;
		ans++;
	}
	m.clear(), m1.clear(), ai = 1, bi = 1, f1 = 0, f2 = 0, s1 = 0;
	for (ll i = n - 1; i > -1; i--) {
		if (m[a[i]] == 1)
			s1 = 1;
		if (s1 == 0)
			m[a[i]]++;
		else
			m1[a[i]]++;
	}
	for (auto x : m) {
		if (m[x.ff] == 0) {
			f1 = 1;
			break;
		}
		ai++;
	}
	for (auto x : m1) {
		if (m1[x.ff] == 0) {
			f2 = 1;
			break;
		}
		bi++;
	}
	if (f1 == 1 or f2 == 1)
		ans = ans;
	else {
		a1 = bi, b1 = ai;
		ans++;
	}
	if (ans == 1) {
		cout << ans << endl;
		cout << a1 - 1 << " " << b1 - 1;
		return;
	}
	if (ans == 2) {
		if (a1 != b1) {
			cout << ans << endl;

			cout << a1 - 1 << " " << b1 - 1 << endl;
			cout << b1 - 1 << " " << a1 - 1;
			return;
		}
		cout << 1 << endl;
		cout << a1 - 1 << " " << a1 - 1;
		return;
	}
	cout << ans;
	m.clear(), m1.clear(), ai = 1, bi = 1, f1 = 0, f2 = 0;
}
 
