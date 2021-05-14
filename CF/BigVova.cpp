/*
B. Big Vova
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alexander is a well-known programmer. Today he decided to finally go out and play football, but with the first hit he left a dent on the new Rolls-Royce of the wealthy businessman Big Vova. Vladimir has recently opened a store on the popular online marketplace "Zmey-Gorynych", and offers Alex a job: if he shows his programming skills by solving a task, he'll work as a cybersecurity specialist. Otherwise, he'll be delivering some doubtful products for the next two years.

You're given n positive integers a1,a2,…,an. Using each of them exactly at once, you're to make such sequence b1,b2,…,bn that sequence c1,c2,…,cn is lexicographically maximal, where ci=GCD(b1,…,bi) - the greatest common divisor of the first i elements of b.

Alexander is really afraid of the conditions of this simple task, so he asks you to solve it.

A sequence a is lexicographically smaller than a sequence b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the sequence a has a smaller element than the corresponding element in b.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤103). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤103)  — the length of the sequence a.

The second line of each test case contains n integers a1,…,an (1≤ai≤103)  — the sequence a.

It is guaranteed that the sum of n over all test cases does not exceed 103.

Output
For each test case output the answer in a single line  — the desired sequence b. If there are multiple answers, print any.

Example
inputCopy
7
2
2 5
4
1 8 2 3
3
3 8 9
5
64 25 75 100 50
1
42
6
96 128 88 80 52 7
5
2 4 8 16 17
outputCopy
5 2 
8 2 1 3 
9 3 8 
100 50 25 75 64 
42 
128 96 80 88 52 7 
17 2 4 8 16 
Note
In the first test case of the example, there are only two possible permutations b  — [2,5] and [5,2]: for the first one c=[2,1], for the second one c=[5,1].

In the third test case of the example, number 9 should be the first in b, and GCD(9,3)=3, GCD(9,8)=1, so the second number of b should be 3.

In the seventh test case of the example, first four numbers pairwise have a common divisor (a power of two), but none of them can be the first in the optimal permutation b.

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
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	sort(a, a + n, greater<ll>());
	ll c = a[0];
	for (ll i = 1; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			if (gcd(a[i], c) < gcd(a[j], c))
			{
				swap(a[i], a[j]);
			}
		}
		c = gcd(c, a[i]);
	}
	foi(n) {
		cout << a[i] << ' ';
	}
}
