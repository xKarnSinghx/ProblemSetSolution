/*
C. Alternating Subsequence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recall that the sequence b is a a subsequence of the sequence a if b can be derived from a by removing zero or more elements without changing the order of the remaining elements. For example, if a=[1,2,1,3,1,2,1], then possible subsequences are: [1,1,1,1], [3] and [1,2,1,3,1,2,1], but not [3,2,3] and [1,1,1,1,2].

You are given a sequence a consisting of n positive and negative elements (there is no zeros in the sequence).

Your task is to choose maximum by size (length) alternating subsequence of the given sequence (i.e. the sign of each next element is the opposite from the sign of the current element, like positive-negative-positive and so on or negative-positive-negative and so on). Among all such subsequences, you have to choose one which has the maximum sum of elements.

In other words, if the maximum length of alternating subsequence is k then your task is to find the maximum sum of elements of some alternating subsequence of length k.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤2⋅105) — the number of elements in a. The second line of the test case contains n integers a1,a2,…,an (−109≤ai≤109,ai≠0), where ai is the i-th element of a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — the maximum sum of the maximum by size (length) alternating subsequence of a.

Example
inputCopy
4
5
1 2 3 -1 -2
4
-1 -2 -1 -3
10
-2 8 3 8 -4 -15 5 -2 -3 1
6
1 -1000000000 1 -1000000000 1 -1000000000
outputCopy
2
-1
6
-2999999997
Note
In the first test case of the example, one of the possible answers is [1,2,3–,−1–––,−2].

In the second test case of the example, one of the possible answers is [−1,−2,−1–––,−3].

In the third test case of the example, one of the possible answers is [−2–––,8,3,8–,−4–––,−15,5–,−2–––,−3,1–].

In the fourth test case of the example, one of the possible answers is [1–,−1000000000–––––––––––––,1–,−1000000000–––––––––––––,1–,−1000000000–––––––––––––].


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
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll mn = a[0], ans = 0;
	foi(n) {
		if (i == 0)
			continue;
		if ((a[i] > 0 and a[i - 1] > 0) or (a[i] < 0 and a[i - 1] < 0)) {
			mn = max(mn, a[i]);
		}
		else {
			ans += mn;
			mn = a[i];
		}
	}
	cout << ans + mn;
}
 
