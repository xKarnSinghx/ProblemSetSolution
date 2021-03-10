/*
B. Max and Mex
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a multiset S initially consisting of n distinct non-negative integers. A multiset is a set, that can contain some elements multiple times.

You will perform the following operation k times:

Add the element ⌈a+b2⌉ (rounded up) into S, where a=mex(S) and b=max(S). If this number is already in the set, it is added again.
Here max of a multiset denotes the maximum integer in the multiset, and mex of a multiset denotes the smallest non-negative integer that is not present in the multiset. For example:

mex({1,4,0,2})=3;
mex({2,5,1})=0.
Your task is to calculate the number of distinct elements in S after k operations will be done.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n, k (1≤n≤105, 0≤k≤109) — the initial size of the multiset S and how many operations you need to perform.

The second line of each test case contains n distinct integers a1,a2,…,an (0≤ai≤109) — the numbers in the initial multiset.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, print the number of distinct elements in S after k operations will be done.

Example
inputCopy
5
4 1
0 1 3 4
3 1
0 1 4
3 0
0 1 4
3 2
0 1 2
3 2
1 2 3
outputCopy
4
4
3
5
3
Note
In the first test case, S={0,1,3,4}, a=mex(S)=2, b=max(S)=4, ⌈a+b2⌉=3. So 3 is added into S, and S becomes {0,1,3,3,4}. The answer is 4.

In the second test case, S={0,1,4}, a=mex(S)=2, b=max(S)=4, ⌈a+b2⌉=3. So 3 is added into S, and S becomes {0,1,3,4}. The answer is 4.


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
typedef pair<ll, pll>      plll;
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
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{
	


	ll n, k;
	cin >> n >> k;
	ll mx = 0, mn = 0;
	ll a[n];
	set<ll>xy;

	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		xy.insert(x);
		a[i] = x;
		mx = max(x, mx);
	}
	sort(a, a + n);
	foi(n) {
		if (a[i] != i)
		{	mn = i;
			break;
		}
		mn++;

	}

	if (k == 0)
		cout << xy.size();
	else if (mn == 0)
	{
	    xy.insert(ceils(mx + mn, 2));
		cout << xy.size() ;
	}
	else if (mn == n)
		cout << xy.size() + k;
	else if (mn > 0)
	{	xy.insert(ceils(mx + mn, 2));
		cout << xy.size() ;
	}



}
 
