/*
C. Random Events
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ron is a happy owner of a permutation a of length n.

A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).


Ron's permutation is subjected to m experiments of the following type: (ri, pi). This means that elements in range [1,ri] (in other words, the prefix of length ri) have to be sorted in ascending order with the probability of pi. All experiments are performed in the same order in which they are specified in the input data.

As an example, let's take a look at a permutation [4,2,1,5,3] and an experiment (3,0.6). After such an experiment with the probability of 60% the permutation will assume the form [1,2,4,5,3] and with a 40% probability it will remain unchanged.

You have to determine the probability of the permutation becoming completely sorted in ascending order after m experiments.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤100).

The first line of each test case contains two integers n and m (1≤n,m≤105) — the length of the permutation and the number of experiments, respectively.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — contents of the permutation.

The following m lines of each test case each contain an integer ri and a real number pi (1≤ri≤n,0≤pi≤1) — the length of the prefix and the probability of it being sorted. All probabilities are given with at most 6 decimal places.

It is guaranteed that the sum of n and the sum of m does not exceed 105 (∑n,∑m≤105).

Output
For each test case, print a single number — the probability that after all experiments the permutation becomes sorted in ascending order. Your answer will be considered correct if its absolute or relative error does not exceed 10−6.

Formally, let your answer be a, and the jury's answer be b. Your answer is accepted if and only if |a−b|max(1,|b|)≤10−6.

Example
inputCopy
4
4 3
4 3 2 1
1 0.3
3 1
4 0.6
5 3
4 2 1 3 5
3 0.8
4 0.6
5 0.3
6 5
1 3 2 4 5 6
4 0.9
5 0.3
2 0.4
6 0.7
3 0.5
4 2
1 2 3 4
2 0.5
4 0.1
outputCopy
0.600000
0.720000
0.989500
1.000000
Note
Explanation of the first test case: It can be demonstrated that whether the final permutation is sorted or not depends solely on sorting being performed in the (4,0.6) experiment.

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
void solve() {
	ll n, m;
	cin >> n >> m;
	ll a[n];
	foi(n)
	cin >> a[i];
	ld ans = 1;
	ll s = n - 1;
	while (a[s] == s + 1)
		s--;
	foi(m) {
		ll x;
		ld f;
		cin >> x >> f;
		if (x > s)
			ans *= (1 - f);
	}
	cout << fixed << setprecision(10);
	if (s < 0)
		cout << 1;
	else
		cout << 1 - ans;

}


