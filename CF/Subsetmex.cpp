/*
A. Subset Mex
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Given a set of integers (it can contain equal elements).

You have to split it into two subsets A and B (both of them can contain equal elements or be empty). You have to maximize the value of mex(A)+mex(B).

Here mex of a set denotes the smallest non-negative integer that doesn't exist in the set. For example:

mex({1,4,0,2,2,1})=3
mex({3,3,2,1,3,0,0})=4
mex(∅)=0 (mex for empty set)
The set is splitted into two subsets A and B if for any integer number x the number of occurrences of x into this set is equal to the sum of the number of occurrences of x into A and the number of occurrences of x into B.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the size of the set.

The second line of each testcase contains n integers a1,a2,…an (0≤ai≤100) — the numbers in the set.

Output
For each test case, print the maximum value of mex(A)+mex(B).

Example
inputCopy
4
6
0 2 1 5 0 1
3
0 1 2
4
0 2 0 1
6
1 2 3 4 5 6
outputCopy
5
3
4
0
Note
In the first test case, A={0,1,2},B={0,1,5} is a possible choice.

In the second test case, A={0,1,2},B=∅ is a possible choice.

In the third test case, A={0,1,2},B={0} is a possible choice.

In the fourth test case, A={1,3,5},B={2,4,6} is a possible choice.


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
	ll a[101] = {};
	foi(n) {
		ll x;
		cin >> x;
		a[x]++;
	}
	ll ans = 0, sa = 0, sb = 0;
	foi(101) {
		if (a[i] == 0 and  sa == 0)
			ans += i, sa++;
		if (a[i] <= 1 and sb == 0) {
			ans += i, sb++;
		}
	}
	cout << ans;


}
