/*
D. Odd-Even Subsequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashish has an array a of size n.

A subsequence of a is defined as a sequence that can be obtained from a by deleting some elements (possibly none), without changing the order of the remaining elements.

Consider a subsequence s of a. He defines the cost of s as the minimum between:

The maximum among all elements at odd indices of s.
The maximum among all elements at even indices of s.
Note that the index of an element is its index in s, rather than its index in a. The positions are numbered from 1. So, the cost of s is equal to min(max(s1,s3,s5,…),max(s2,s4,s6,…)).

For example, the cost of {7,5,6} is min(max(7,6),max(5))=min(7,5)=5.

Help him find the minimum cost of a subsequence of size k.

Input
The first line contains two integers n and k (2≤k≤n≤2⋅105)  — the size of the array a and the size of the subsequence.

The next line contains n integers a1,a2,…,an (1≤ai≤109)  — the elements of the array a.

Output
Output a single integer  — the minimum cost of a subsequence of size k.

Examples
inputCopy
4 2
1 2 3 4
outputCopy
1
inputCopy
4 3
1 2 3 4
outputCopy
2
inputCopy
5 3
5 3 4 2 6
outputCopy
2
inputCopy
6 4
5 3 50 2 4 5
outputCopy
3
Note
In the first test, consider the subsequence s = {1,3}. Here the cost is equal to min(max(1),max(3))=1.

In the second test, consider the subsequence s = {1,2,4}. Here the cost is equal to min(max(1,4),max(2))=2.

In the fourth test, consider the subsequence s = {3,50,2,4}. Here the cost is equal to min(max(3,2),max(50,4))=3.*/
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

//	ll t ; cin >> t;
//	while (t--)
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
ll n, k;
vll a;
bool debugodd(vll a, ll bound, ll k) {
	ll n = a.size();
	ll cnt = 0;
	foi(n) {
		if (cnt % 2 == 0) {
			cnt++;
		}
		else {
			if (a[i] <= bound)
				cnt++;
		}
	}
	return cnt >= k;
}
bool debugeven(vll a, ll bound, ll k) {
	ll n = a.size();
	ll cnt = 0;
	foi(n) {
		if (cnt % 2) {
			cnt++;
		}
		else {
			if (a[i] <= bound)
				cnt++;
		}
	}
	return cnt >= k;
}
void solve() {
	cin >> n >> k;
	foi(n) {
		ll x;
		cin >> x;
		a.pb(x);
	}
	ll low = 1, high = MOD;
	while (low != high) {
		ll mid = (low + high) / 2;
		if (debugeven(a, mid, k) or debugodd(a, mid, k)) {
			high = mid;
		}
		else
			low = mid + 1;
	}
	cout << low;

}

 
