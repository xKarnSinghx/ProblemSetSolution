/*
C. Manhattan Subarrays
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Suppose you have two points p=(xp,yp) and q=(xq,yq). Let's denote the Manhattan distance between them as d(p,q)=|xp−xq|+|yp−yq|.

Let's say that three points p, q, r form a bad triple if d(p,r)=d(p,q)+d(q,r).

Let's say that an array b1,b2,…,bm is good if it is impossible to choose three distinct indices i, j, k such that the points (bi,i), (bj,j) and (bk,k) form a bad triple.

You are given an array a1,a2,…,an. Calculate the number of good subarrays of a. A subarray of the array a is the array al,al+1,…,ar for some 1≤l≤r≤n.

Note that, according to the definition, subarrays of length 1 and 2 are good.

Input
The first line contains one integer t (1≤t≤5000) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤2⋅105) — the length of array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

It's guaranteed that the sum of n doesn't exceed 2⋅105.

Output
For each test case, print the number of good subarrays of array a.

Example
inputCopy
3
4
2 4 1 3
5
6 9 1 9 6
2
13 37
outputCopy
10
12
3
Note
In the first test case, it can be proven that any subarray of a is good. For example, subarray [a2,a3,a4] is good since it contains only three elements and:

d((a2,2),(a4,4))=|4−3|+|2−4|=3 < d((a2,2),(a3,3))+d((a3,3),(a4,4))=3+1+2+1=7;
d((a2,2),(a3,3)) < d((a2,2),(a4,4))+d((a4,4),(a3,3));
d((a3,3),(a4,4)) < d((a3,3),(a2,2))+d((a2,2),(a4,4));
In the second test case, for example, subarray [a1,a2,a3,a4] is not good, since it contains a bad triple (a1,1), (a2,2), (a4,4):

d((a1,1),(a4,4))=|6−9|+|1−4|=6;
d((a1,1),(a2,2))=|6−9|+|1−2|=4;
d((a2,2),(a4,4))=|9−9|+|2−4|=2;
So, d((a1,1),(a4,4))=d((a1,1),(a2,2))+d((a2,2),(a4,4)).


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
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll ans = 0, f = 1;
	foi(n) {
		f = 1;
		for (ll j = i; j < n; j++) {
			for (ll x = i; x < j; x++) {
				for (ll y  = i; y < x; y++) {
					if ((a[y] <= a[x] and a[x] <= a[j]) or (a[y] >= a[x] and a[x] >= a[j]))
						f = 0;
				}
			}
			if (f)
				ans++;
			else
				break;
		}
	}
	cout << ans;
}
 
