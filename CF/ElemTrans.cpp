/*
C. Element Extermination
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n, which initially is a permutation of numbers from 1 to n. In one operation, you can choose an index i (1≤i<n) such that ai<ai+1, and remove either ai or ai+1 from the array (after the removal, the remaining parts are concatenated).

For example, if you have the array [1,3,2], you can choose i=1 (since a1=1<a2=3), then either remove a1 which gives the new array [3,2], or remove a2 which gives the new array [1,2].

Is it possible to make the length of this array equal to 1 with these operations?

Input
The first line contains a single integer t (1≤t≤2⋅104)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤3⋅105)  — the length of the array.

The second line of each test case contains n integers a1, a2, ..., an (1≤ai≤n, ai are pairwise distinct) — elements of the array.

It is guaranteed that the sum of n over all test cases doesn't exceed 3⋅105.

Output
For each test case, output on a single line the word "YES" if it is possible to reduce the array to a single element using the aforementioned operation, or "NO" if it is impossible to do so.

Example
inputCopy
4
3
1 2 3
4
3 1 2 4
3
2 3 1
6
2 4 6 1 3 5
outputCopy
YES
YES
NO
YES
Note
For the first two test cases and the fourth test case, we can operate as follow (the bolded elements are the pair chosen for that operation):

[1,2,3]→[1,2]→[1]
[3,1,2,4]→[3,1,4]→[3,4]→[4]
[2,4,6,1,3,5]→[4,6,1,3,5]→[4,1,3,5]→[4,1,5]→[4,5]→[4]

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
	foi(n)
	cin >> a[i];
	if (a[0] > a[n - 1])
		cout << "No";
	else
		cout << "Yes";
}

