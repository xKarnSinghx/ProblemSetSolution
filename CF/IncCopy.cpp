/*
C. Increase and Copy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Initially, you have the array a consisting of one element 1 (a=[1]).

In one move, you can do one of the following things:

Increase some (single) element of a by 1 (choose some i from 1 to the current length of a and increase ai by one);
Append the copy of some (single) element of a to the end of the array (choose some i from 1 to the current length of a and append ai to the end of the array).
For example, consider the sequence of five moves:

You take the first element a1, append its copy to the end of the array and get a=[1,1].
You take the first element a1, increase it by 1 and get a=[2,1].
You take the second element a2, append its copy to the end of the array and get a=[2,1,1].
You take the first element a1, append its copy to the end of the array and get a=[2,1,1,2].
You take the fourth element a4, increase it by 1 and get a=[2,1,1,3].
Your task is to find the minimum number of moves required to obtain the array with the sum at least n.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1≤n≤109) — the lower bound on the sum of the array.

Output
For each test case, print the answer: the minimum number of moves required to obtain the array with the sum at least n.

Example
inputCopy
5
1
5
42
1337
1000000000
outputCopy
0
3
11
72
63244

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
	ll mn = 11111111111;
	for (ll i = 1; i * i <= n; i++)
		mn = min(mn, i - 1 + (n - 1) / i);
	cout << mn;

}
