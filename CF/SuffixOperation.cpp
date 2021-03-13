/*
B. Suffix Operations
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Gildong has an interesting machine that has an array a with n integers. The machine supports two kinds of operations:

Increase all elements of a suffix of the array by 1.
Decrease all elements of a suffix of the array by 1.
A suffix is a subsegment (contiguous elements) of the array that contains an. In other words, for all i where ai is included in the subsegment, all aj's where i<j≤n must also be included in the subsegment.

Gildong wants to make all elements of a equal — he will always do so using the minimum number of operations necessary. To make his life even easier, before Gildong starts using the machine, you have the option of changing one of the integers in the array to any other integer. You are allowed to leave the array unchanged. You want to minimize the number of operations Gildong performs. With your help, what is the minimum number of operations Gildong will perform?

Note that even if you change one of the integers in the array, you should not count that as one of the operations because Gildong did not perform it.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤1000).

Each test case contains two lines. The first line of each test case consists of an integer n (2≤n≤2⋅105) — the number of elements of the array a.

The second line of each test case contains n integers. The i-th integer is ai (−5⋅108≤ai≤5⋅108).

It is guaranteed that the sum of n in all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the minimum number of operations Gildong has to perform in order to make all elements of the array equal.

Example
inputCopy
7
2
1 1
3
-1 0 2
4
99 96 97 95
4
-3 -5 -2 1
6
1 4 3 2 4 1
5
5 0 0 0 5
9
-367741579 319422997 -415264583 -125558838 -300860379 420848004 294512916 -383235489 425814447
outputCopy
0
1
3
4
6
5
2847372102
Note
In the first case, all elements of the array are already equal. Therefore, we do not change any integer and Gildong will perform zero operations.

In the second case, we can set a3 to be 0, so that the array becomes [−1,0,0]. Now Gildong can use the 2-nd operation once on the suffix starting at a2, which means a2 and a3 are decreased by 1, making all elements of the array −1.

In the third case, we can set a1 to 96, so that the array becomes [96,96,97,95]. Now Gildong needs to:

Use the 2-nd operation on the suffix starting at a3 once, making the array [96,96,96,94].
Use the 1-st operation on the suffix starting at a4 2 times, making the array [96,96,96,96].
In the fourth case, we can change the array into [−3,−3,−2,1]. Now Gildong needs to:

Use the 2-nd operation on the suffix starting at a4 3 times, making the array [−3,−3,−2,−2].
Use the 2-nd operation on the suffix starting at a3 once, making the array [−3,−3,−3,−3].
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
void findPairs(int arr[], int n)
{


}
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];

	ll ans = 0;
	for (ll i = 1; i < n; i++)
		ans += abs(a[i] - a[i - 1]);

	ll mx = max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
	for (ll i = 1; i < n - 1; i++)
		mx = max(mx, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));

	cout << ans - mx ;

}
