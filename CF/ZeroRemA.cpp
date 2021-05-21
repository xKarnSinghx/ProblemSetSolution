/*
D. Zero Remainder Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n positive integers.

Initially, you have an integer x=0. During one move, you can do one of the following two operations:

Choose exactly one i from 1 to n and increase ai by x (ai:=ai+x), then increase x by 1 (x:=x+1).
Just increase x by 1 (x:=x+1).
The first operation can be applied no more than once to each i from 1 to n.

Your task is to find the minimum number of moves required to obtain such an array that each its element is divisible by k (the value k is given).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The first line of the test case contains two integers n and k (1≤n≤2⋅105;1≤k≤109) — the length of a and the required divisior. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the i-th element of a.

It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — the minimum number of moves required to obtain such an array that each its element is divisible by k.

Example
inputCopy
5
4 3
1 2 1 3
10 6
8 7 1 8 3 7 5 10 8 9
5 10
20 100 50 20 100500
10 25
24 24 24 24 24 24 24 24 24 24
8 8
1 2 3 4 5 6 7 8
outputCopy
6
18
0
227
8
Note
Consider the first test case of the example:

x=0, a=[1,2,1,3]. Just increase x;
x=1, a=[1,2,1,3]. Add x to the second element and increase x;
x=2, a=[1,3,1,3]. Add x to the third element and increase x;
x=3, a=[1,3,3,3]. Add x to the fourth element and increase x;
x=4, a=[1,3,3,6]. Just increase x;
x=5, a=[1,3,3,6]. Add x to the first element and increase x;
x=6, a=[6,3,3,6]. We obtained the required array.
Note that you can't add x to the same element more than once.


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
void solve() {
	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n) {
		cin >> a[i];
		a[i] %= k;
	}
	mll m;
	foi(n) {
		m[a[i]]++;
	}
	ll s = 0, t = 0, tn = -1;
	foi(n) {
		if (a[i] == 0)
			s++;
	}
	if (s == n) {
		cout << 0; return;
	}
	ll f = 0;
	for (auto x : m) {
		if (x.ss > t and x.ff != 0) {
			t = x.ss;
			if (m[tn] != x.ss)
				tn = x.ff;
		}
	}

	cout << k*(t - 1) + k - tn + 1;
}

