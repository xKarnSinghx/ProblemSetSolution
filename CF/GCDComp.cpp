/*
B. GCD Compression
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashish has an array a of consisting of 2n positive integers. He wants to compress a into an array b of size n−1. To do this, he first discards exactly 2 (any two) elements from a. He then performs the following operation until there are no elements left in a:

Remove any two elements from a and append their sum to b.
The compressed array b has to have a special property. The greatest common divisor (gcd) of all its elements should be greater than 1.

Recall that the gcd of an array of positive integers is the biggest integer that is a divisor of all integers in the array.

It can be proven that it is always possible to compress array a into an array b of size n−1 such that gcd(b1,b2...,bn−1)>1.

Help Ashish find a way to do so.

Input
The first line contains a single integer t (1≤t≤10) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤1000).

The second line of each test case contains 2n integers a1,a2,…,a2n (1≤ai≤1000) — the elements of the array a.

Output
For each test case, output n−1 lines — the operations performed to compress the array a to the array b. The initial discard of the two elements is not an operation, you don't need to output anything about it.

The i-th line should contain two integers, the indices (1 —based) of the two elements from the array a that are used in the i-th operation. All 2n−2 indices should be distinct integers from 1 to 2n.

You don't need to output two initially discarded elements from a.

If there are multiple answers, you can find any.

Example
inputCopy
3
3
1 2 3 4 5 6
2
5 7 9 10
5
1 3 3 4 5 90 100 101 2 3
outputCopy
3 6
4 5
3 4
1 9
2 3
4 5
6 10
Note
In the first test case, b={3+6,4+5}={9,9} and gcd(9,9)=9.

In the second test case, b={9+10}={19} and gcd(19)=19.

In the third test case, b={1+2,3+3,4+5,90+3}={3,6,9,93} and gcd(3,6,9,93)=3.*/
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
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
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
void solve() {
	ll n;
	cin >> n;
	vpll odd, even;;
	foi(n * 2) {
		ll x;
		cin >> x;
		if (x % 2)
			odd.pb(mp(x, i + 1));
		else
			even.pb(mp(x, i + 1));
	}
	ll s = 0;
	if (odd.size() >= 2) {
		for (ll i = 1; i < odd.size(); i += 2) {
			cout << odd[i].ss << " " << odd[i - 1].ss << endl;
			s++;
			if (s == n - 1)
				return;
		}
	}
	if (even.size() >= 2) {
		for (ll i = 1; i < even.size(); i += 2) {
			cout << even[i].ss << " " << even[i - 1].ss << endl;
			s++;
			if (s == n - 1)
				return;
		}
	}

}

 
