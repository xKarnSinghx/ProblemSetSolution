/*
C. Make It Good
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n integers. You have to find the length of the smallest (shortest) prefix of elements you need to erase from a to make it a good array. Recall that the prefix of the array a=[a1,a2,…,an] is a subarray consisting several first elements: the prefix of the array a of length k is the array [a1,a2,…,ak] (0≤k≤n).

The array b of length m is called good, if you can obtain a non-decreasing array c (c1≤c2≤⋯≤cm) from it, repeating the following operation m times (initially, c is empty):

select either the first or the last element of b, remove it from b, and append it to the end of the array c.
For example, if we do 4 operations: take b1, then bm, then bm−1 and at last b2, then b becomes [b3,b4,…,bm−3] and c=[b1,bm,bm−1,b2].

Consider the following example: b=[1,2,3,4,4,2,1]. This array is good because we can obtain non-decreasing array c from it by the following sequence of operations:

take the first element of b, so b=[2,3,4,4,2,1], c=[1];
take the last element of b, so b=[2,3,4,4,2], c=[1,1];
take the last element of b, so b=[2,3,4,4], c=[1,1,2];
take the first element of b, so b=[3,4,4], c=[1,1,2,2];
take the first element of b, so b=[4,4], c=[1,1,2,2,3];
take the last element of b, so b=[4], c=[1,1,2,2,3,4];
take the only element of b, so b=[], c=[1,1,2,2,3,4,4] — c is non-decreasing.
Note that the array consisting of one element is good.

Print the length of the shortest prefix of a to delete (erase), to make a to be a good array. Note that the required length can be 0.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤2⋅105) — the length of a. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤2⋅105), where ai is the i-th element of a.

It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer: the length of the shortest prefix of elements you need to erase from a to make it a good array.

Example
inputCopy
5
4
1 2 3 4
7
4 3 3 8 4 5 2
3
1 1 1
7
1 3 1 4 5 3 2
5
5 4 3 2 3
outputCopy
0
4
0
2
3
Note
In the first test case of the example, the array a is already good, so we don't need to erase any prefix.

In the second test case of the example, the initial array a is not good. Let's erase first 4 elements of a, the result is [4,5,2]. The resulting array is good. You can prove that if you erase fewer number of first elements, the result will not be good.

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
	ll x = n - 1;
	while (x > -1 and a[x - 1] >= a[x])
		x--;
	while (x > -1 and a[x - 1] <= a[x])
		x--;
	if (x == -1)
		x = 0;
	cout << x;

}

