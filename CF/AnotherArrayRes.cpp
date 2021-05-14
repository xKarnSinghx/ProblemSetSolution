/*
C. Yet Another Array Restoration
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
We have a secret array. You don't know this array and you have to restore it. However, you know some facts about this array:

The array consists of n distinct positive (greater than 0) integers.
The array contains two elements x and y (these elements are known for you) such that x<y.
If you sort the array in increasing order (such that a1<a2<…<an), differences between all adjacent (consecutive) elements are equal (i.e. a2−a1=a3−a2=…=an−an−1).
It can be proven that such an array always exists under the constraints given below.

Among all possible arrays that satisfy the given conditions, we ask you to restore one which has the minimum possible maximum element. In other words, you have to minimize max(a1,a2,…,an).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

The only line of the test case contains three integers n, x and y (2≤n≤50; 1≤x<y≤50) — the length of the array and two elements that are present in the array, respectively.

Output
For each test case, print the answer: n integers a1,a2,…,an (1≤ai≤109), where ai is the i-th element of the required array. If there are several answers, you can print any (it also means that the order of elements doesn't matter).

It can be proven that such an array always exists under the given constraints.

Example
inputCopy
5
2 1 49
5 20 50
6 20 50
5 3 8
9 13 22
outputCopy
1 49 
20 40 30 50 10
26 32 20 38 44 50 
8 23 18 13 3 
1 10 13 4 19 22 25 16 7 

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

	ll n, x, y;
	cin >> n >> x >> y;
	ll dif = y - x, nxt;
	for (nxt = n - 1; nxt > 0; nxt--) {
		if (dif % nxt == 0) {
			nxt = dif / nxt;
			break;
		}
	}
	for (ll i = 1; y - nxt > 0 && i < n; i++)
		y -= nxt;
	foi(n)
	{
		cout << y << " ";
		y += nxt;
	}
}

