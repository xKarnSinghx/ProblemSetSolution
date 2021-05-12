/*
C1. Pokémon Army (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the easy version of the problem. The difference between the versions is that the easy version has no swap operations. You can make hacks only if all versions of the problem are solved.

Pikachu is a cute and friendly pokémon living in the wild pikachu herd.

But it has become known recently that infamous team R wanted to steal all these pokémon! Pokémon trainer Andrew decided to help Pikachu to build a pokémon army to resist.

First, Andrew counted all the pokémon — there were exactly n pikachu. The strength of the i-th pokémon is equal to ai, and all these numbers are distinct.

As an army, Andrew can choose any non-empty subsequence of pokemons. In other words, Andrew chooses some array b from k indices such that 1≤b1<b2<⋯<bk≤n, and his army will consist of pokémons with forces ab1,ab2,…,abk.

The strength of the army is equal to the alternating sum of elements of the subsequence; that is, ab1−ab2+ab3−ab4+….

Andrew is experimenting with pokémon order. He performs q operations. In i-th operation Andrew swaps li-th and ri-th pokémon.

Note: q=0 in this version of the task.

Andrew wants to know the maximal stregth of the army he can achieve with the initial pokémon placement. He also needs to know the maximal strength after each operation.

Help Andrew and the pokémon, or team R will realize their tricky plan!

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤103) denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers n and q (1≤n≤3⋅105,q=0) denoting the number of pokémon and number of operations respectively.

The second line contains n distinct positive integers a1,a2,…,an (1≤ai≤n) denoting the strengths of the pokémon.

i-th of the last q lines contains two positive integers li and ri (1≤li≤ri≤n) denoting the indices of pokémon that were swapped in the i-th operation.

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105, and the sum of q over all test cases does not exceed 3⋅105.

Output
For each test case, print q+1 integers: the maximal strength of army before the swaps and after each swap.

Example
inputCopy
3
3 0
1 3 2
2 0
1 2
7 0
1 2 5 4 3 6 7
outputCopy
3
2
9
Note
In third test case we can build an army in such way: [1 2 5 4 3 6 7], its strength will be 5−3+7=9.


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
	ll n, q;
	cin >> n >> q;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll s = a[0];
	for (ll i = 1; i < n; i++) {
		s += max(0LL, a[i] - a[i - 1]);
	}
	cout << s;

}
