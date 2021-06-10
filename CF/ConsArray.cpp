/*-
D. Constructing the Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n consisting of zeros. You perform n actions with this array: during the i-th action, the following sequence of operations appears:

Choose the maximum by length subarray (continuous subsegment) consisting only of zeros, among all such segments choose the leftmost one;
Let this segment be [l;r]. If r−l+1 is odd (not divisible by 2) then assign (set) a[l+r2]:=i (where i is the number of the current action), otherwise (if r−l+1 is even) assign (set) a[l+r−12]:=i.
Consider the array a of length 5 (initially a=[0,0,0,0,0]). Then it changes as follows:

Firstly, we choose the segment [1;5] and assign a[3]:=1, so a becomes [0,0,1,0,0];
then we choose the segment [1;2] and assign a[1]:=2, so a becomes [2,0,1,0,0];
then we choose the segment [4;5] and assign a[4]:=3, so a becomes [2,0,1,3,0];
then we choose the segment [2;2] and assign a[2]:=4, so a becomes [2,4,1,3,0];
and at last we choose the segment [5;5] and assign a[5]:=5, so a becomes [2,4,1,3,5].
Your task is to find the array a of length n after performing all n actions. Note that the answer exists and unique.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1≤n≤2⋅105) — the length of a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — the array a of length n after performing n actions described in the problem statement. Note that the answer exists and unique.

Example
inputCopy
6
1
2
3
4
5
6
outputCopy
1 
1 2 
2 1 3 
3 1 2 4 
2 4 1 3 5 
3 4 1 5 2 6 

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
struct cmp {
	bool operator() (const pll &a, const pll &b) const {
		ll fir = a.ss - a.ff + 1;
		ll sec = b.ss - b.ff + 1;
		if (fir == sec)
			return a.ff < b.ff;
		return fir > sec;
	}
};
void solve() {
	ll n;
	cin >> n;
	set<pll, cmp> s;
	s.insert({0, n - 1});
	vll a(n, 0);
	foi(n) {
		pll temp = *s.begin();
		s.erase(s.begin());
		ll idx = (temp.ff + temp.ss) / 2;
		a[idx] = i + 1;
		if (temp.ff < idx)
			s.insert({temp.ff, idx - 1});
		if (idx < temp.ss)
			s.insert({idx + 1, temp.ss});
	}
	foi(n) {
		cout << a[i] << " ";
	}

}
