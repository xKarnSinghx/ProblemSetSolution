/*
D. Max GEQ Sum
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of n integers. You are asked to find out if the inequality
max(ai,ai+1,…,aj−1,aj)≥ai+ai+1+⋯+aj−1+aj
holds for all pairs of indices (i,j), where 1≤i≤j≤n.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105)  — the size of the array.

The next line of each test case contains n integers a1,a2,…,an (−109≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, on a new line output "YES" if the condition is satisfied for the given array, and "NO" otherwise. You can print each letter in any case (upper or lower).

Example
inputCopy
3
4
-1 1 -1 2
5
-1 2 -3 2 -1
3
2 3 -1
outputCopy
YES
YES
NO
Note
In test cases 1 and 2, the given condition is satisfied for all (i,j) pairs.

In test case 3, the condition isn't satisfied for the pair (1,2) as max(2,3)<2+3.


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
const ll N = 1000001;
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
multiset<ll> Lis(vll a) {
	multiset<ll> S;
	multiset<ll>::iterator it;
	foi(a.size()) {
		S.insert(a[i]);
		it = S.lower_bound(a[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}
vll a(N);
struct segNode {
	ll l, r, segsum, totsum;
} tree[N];
void merge(segNode &node, segNode &cl, segNode &cr) {
	node.segsum = cl.segsum + cr.segsum;
	node.l = max(cl.segsum + cr.l, cl.l), node.r = max(cr.segsum + cl.r, cr.r), node.totsum = max({cl.totsum, cr.totsum, cl.r + cr.l});
}



void build(ll node, ll tl, ll tr) {
	if (tl == tr) {
		tree[node].l = tree[node].r = tree[node].segsum = tree[node].totsum = a[tl];
		return;
	}
	ll cl = node << 1, cr = cl | 1, tm = (tl + tr) >> 1;
	build(cl, tl, tm), build(cr, tm + 1, tr);
	merge(tree[node], tree[cl], tree[cr]);
}


void query(segNode &res, ll node, ll tl, ll tr, ll l, ll r) {
	if (tl == l and tr == r)
		res = tree[node];
	else {
		ll cl = node << 1, cr = cl | 1, tm = (tl + tr) >> 1;
		if (r <= tm)
			query(res, cl, tl, tm, l, r);
		else if (l > tm)
			query(res, cr, tm + 1, tr, l, r);
		else {
			segNode left, right;
			query(left, cl, tl, tm, l, tm), query(right, cr, tm + 1, tr, tm + 1, r);
			merge(res, left, right);
		}
	}
}
void solve() {
	ll n;
	cin >> n;
	foi(n) {
		cin >> a[i];
	}
	vll left(n), right(n);
	stack<ll> s;
	foi(n) {
		while (!s.empty() and a[s.top()] <= a[i])
			s.pop();
		if (!s.empty())
			left[i] = s.top();
		else
			left[i] = -1;
		s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (ll i = n - 1; i >= 0; --i) {
		while (!s.empty() and a[s.top()] <= a[i])
			s.pop();
		if (!s.empty())
			right[i] = s.top();
		else
			right[i] = n;
		s.push(i);
	}
	build(1, 0, n - 1);
	foi(n) {
		ll gol = left[i] + 1, gor = right[i] - 1;
		segNode result;
		query(result, 1, 0, n - 1, gol, gor);
		if (result.totsum > a[i]) {
			cout << "NO";
			a.clear();
			return;
		}
	}
	cout << "YES";
	a.clear();
}
