/*
C. Shinju and the Lost Permutation
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Shinju loves permutations very much! Today, she has borrowed a permutation p from Juju to play with.

The i-th cyclic shift of a permutation p is a transformation on the permutation such that p=[p1,p2,…,pn] will now become p=[pn−i+1,…,pn,p1,p2,…,pn−i].

Let's define the power of permutation p as the number of distinct elements in the prefix maximums array b of the permutation. The prefix maximums array b is the array of length n such that bi=max(p1,p2,…,pi). For example, the power of [1,2,5,4,6,3] is 4 since b=[1,2,5,5,6,6] and there are 4 distinct elements in b.

Unfortunately, Shinju has lost the permutation p! The only information she remembers is an array c, where ci is the power of the (i−1)-th cyclic shift of the permutation p. She's also not confident that she remembers it correctly, so she wants to know if her memory is good enough.

Given the array c, determine if there exists a permutation p that is consistent with c. You do not have to construct the permutation p.

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤5⋅103) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤105).

The second line of each test case contains n integers c1,c2,…,cn (1≤ci≤n).

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, print "YES" if there is a permutation p exists that satisfies the array c, and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

Example
inputCopy
6
1
1
2
1 2
2
2 2
6
1 2 4 6 3 5
6
2 3 1 2 3 4
3
3 2 1
outputCopy
YES
YES
NO
NO
YES
NO
Note
In the first test case, the permutation [1] satisfies the array c.

In the second test case, the permutation [2,1] satisfies the array c.

In the fifth test case, the permutation [5,1,2,4,6,3] satisfies the array c. Let's see why this is true.

The zeroth cyclic shift of p is [5,1,2,4,6,3]. Its power is 2 since b=[5,5,5,5,6,6] and there are 2 distinct elements — 5 and 6.
The first cyclic shift of p is [3,5,1,2,4,6]. Its power is 3 since b=[3,5,5,5,5,6].
The second cyclic shift of p is [6,3,5,1,2,4]. Its power is 1 since b=[6,6,6,6,6,6].
The third cyclic shift of p is [4,6,3,5,1,2]. Its power is 2 since b=[4,6,6,6,6,6].
The fourth cyclic shift of p is [2,4,6,3,5,1]. Its power is 3 since b=[2,4,6,6,6,6].
The fifth cyclic shift of p is [1,2,4,6,3,5]. Its power is 4 since b=[1,2,4,6,6,6].
Therefore, c=[2,3,1,2,3,4].

In the third, fourth, and sixth testcases, we can show that there is no permutation that satisfies array c.


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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 100010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	ll cnt = 0, mx = 0;
	foi(n) {
		cin >> a[i];
		if (a[i] == 1) {
			cnt++;
		}
		if (i)
			mx = max(mx, a[i] - a[i - 1]);
	}
	mx = max(mx, a[0] - a[n - 1]);
	if (cnt == 1 and mx < 2) {
		cout << "YES";
		return;
	}
	cout << "NO";
}

