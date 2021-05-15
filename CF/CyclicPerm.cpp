/*
C. Cyclic Permutations
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

Consider a permutation p of length n, we build a graph of size n using it as follows:

For every 1≤i≤n, find the largest j such that 1≤j<i and pj>pi, and add an undirected edge between node i and node j
For every 1≤i≤n, find the smallest j such that i<j≤n and pj>pi, and add an undirected edge between node i and node j
In cases where no such j exists, we make no edges. Also, note that we make edges between the corresponding indices, not the values at those indices.

For clarity, consider as an example n=4, and p=[3,1,4,2]; here, the edges of the graph are (1,3),(2,1),(2,3),(4,3).

A permutation p is cyclic if the graph built using p has at least one simple cycle.

Given n, find the number of cyclic permutations of length n. Since the number may be very large, output it modulo 109+7.

Please refer to the Notes section for the formal definition of a simple cycle

Input
The first and only line contains a single integer n (3≤n≤106).

Output
Output a single integer 0≤x<109+7, the number of cyclic permutations of length n modulo 109+7.

Examples
inputCopy
4
outputCopy
16
inputCopy
583291
outputCopy
135712853
Note
There are 16 cyclic permutations for n=4. [4,2,1,3] is one such permutation, having a cycle of length four: 4→3→2→1→4.

Nodes v1, v2, …, vk form a simple cycle if the following conditions hold:

k≥3.
vi≠vj for any pair of indices i and j. (1≤i<j≤k)
vi and vi+1 share an edge for all i (1≤i<k), and v1 and vk share an edge.

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
void solve() {
	ll n;
	cin >> n;
	ll t = 1, ans = 1;
	for (ll i = 1; i < n; i++) {
		t *= 2;
		t %= MOD;
		ans *= i;
		ans %= MOD;
	}
	ans *= n;
	cout << (ans - t) % MOD;

}
 
