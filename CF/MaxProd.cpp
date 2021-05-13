/*
B. Maximum Product
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array of integers a1,a2,…,an. Find the maximum possible value of aiajakalat among all five indices (i,j,k,l,t) (i<j<k<l<t).

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤2⋅104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (5≤n≤105) — the size of the array.

The second line of each test case contains n integers a1,a2,…,an (−3×103≤ai≤3×103) — given array.

It's guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the answer to the problem.

Example
inputCopy
4
5
-1 -2 -3 -4 -5
6
-1 -2 -3 1 2 -1
6
-1 0 0 0 -1 -1
6
-9 -7 -5 -3 -2 1
outputCopy
-120
12
0
945
Note
In the first test case, choosing a1,a2,a3,a4,a5 is a best choice: (−1)⋅(−2)⋅(−3)⋅(−4)⋅(−5)=−120.

In the second test case, choosing a1,a2,a3,a5,a6 is a best choice: (−1)⋅(−2)⋅(−3)⋅2⋅(−1)=12.

In the third test case, choosing a1,a2,a3,a4,a5 is a best choice: (−1)⋅0⋅0⋅0⋅(−1)=0.

In the fourth test case, choosing a1,a2,a3,a4,a6 is a best choice: (−9)⋅(−7)⋅(−5)⋅(−3)⋅1=945.

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
#define graph          vector<vector<int>>
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
void solve() {
	ll n;
	cin >> n;
	ll a[n] = {};
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	sort(a, a + n);
	cout << max(a[n - 1]*a[n - 2]*a[n - 3]*a[n - 4]*a[n - 5], max(a[n - 1]*a[0]*a[1]*a[2]*a[3], max(a[n - 1]*a[n - 2]*a[n - 3]*a[1]*a[0], a[0]*a[1]*a[2]*a[3]*a[4])));

}
