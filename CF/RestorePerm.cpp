/*
B. Restore the Permutation by Merger
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation of length n is a sequence of integers from 1 to n of length n containing each number exactly once. For example, [1], [4,3,5,1,2], [3,2,1] are permutations, and [1,1], [0,1], [2,2,1,4] are not.

There was a permutation p[1…n]. It was merged with itself. In other words, let's take two instances of p and insert elements of the second p into the first maintaining relative order of elements. The result is a sequence of the length 2n.

For example, if p=[3,1,2] some possible results are: [3,1,2,3,1,2], [3,3,1,1,2,2], [3,1,3,1,2,2]. The following sequences are not possible results of a merging: [1,3,2,1,2,3], [3,1,2,3,2,1], [3,3,1,2,2,1].

For example, if p=[2,1] the possible results are: [2,2,1,1], [2,1,2,1]. The following sequences are not possible results of a merging: [1,1,2,2], [2,1,1,2], [1,2,2,1].

Your task is to restore the permutation p by the given resulting sequence a. It is guaranteed that the answer exists and is unique.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤400) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the length of permutation. The second line of the test case contains 2n integers a1,a2,…,a2n (1≤ai≤n), where ai is the i-th element of a. It is guaranteed that the array a represents the result of merging of some permutation p with the same permutation p.

Output
For each test case, print the answer: n integers p1,p2,…,pn (1≤pi≤n), representing the initial permutation. It is guaranteed that the answer exists and is unique.

Example
inputCopy
5
2
1 1 2 2
4
1 3 1 4 3 4 2 2
5
1 2 1 2 3 4 3 5 4 5
3
1 2 3 1 2 3
4
2 3 2 4 1 3 4 1
outputCopy
1 2 
1 3 4 2 
1 2 3 4 5 
1 2 3 
2 3 4 1 

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
	ll a[2 * n];
	foi(2 * n) {
		cin >> a[i];
	}
	ll b[n] = {};
	vll c;
	foi(2 * n) {
		if (b[a[i] - 1] == 0) {
			c.pb(a[i]);
			b[a[i] - 1]++;
		}
	}
	foi(c.size()) {
		cout << c[i] << " ";
	}

}

