/*
A. Reorder
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For a given array a consisting of n integers and a given integer m find if it is possible to reorder elements of the array a in such a way that ∑ni=1∑nj=iajj equals m? It is forbidden to delete elements as well as insert new elements. Please note that no rounding occurs during division, for example, 52=2.5.

Input
The first line contains a single integer t — the number of test cases (1≤t≤100). The test cases follow, each in two lines.

The first line of a test case contains two integers n and m (1≤n≤100, 0≤m≤106). The second line contains integers a1,a2,…,an (0≤ai≤106) — the elements of the array.

Output
For each test case print "YES", if it is possible to reorder the elements of the array in such a way that the given formula gives the given value, and "NO" otherwise.

Example
inputCopy
2
3 8
2 5 1
4 4
0 1 2 3
outputCopy
YES
NO
Note
In the first test case one of the reorders could be [1,2,5]. The sum is equal to (11+22+53)+(22+53)+(53)=8. The brackets denote the inner sum ∑nj=iajj, while the summation of brackets corresponds to the sum over i.


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
	ll n, m;
	cin >> n >> m;
	ll s = 0;
	foi(n) {
		ll x;
		cin >> x;
		s += x;
	}
	if (s == m)
		cout << "YES";
	else
		cout << "NO";

}
