/*
D. Add to Neighbour and Remove
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp was given an array of a[1…n] of n integers. He can perform the following operation with the array a no more than n times:

Polycarp selects the index i and adds the value ai to one of his choice of its neighbors. More formally, Polycarp adds the value of ai to ai−1 or to ai+1 (if such a neighbor does not exist, then it is impossible to add to it).
After adding it, Polycarp removes the i-th element from the a array. During this step the length of a is decreased by 1.
The two items above together denote one single operation.

For example, if Polycarp has an array a=[3,1,6,6,2], then it can perform the following sequence of operations with it:

Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[4,6,6,2].
Polycarp selects i=1 and adds the value ai to (i+1)-th element: a=[10,6,2].
Polycarp selects i=3 and adds the value ai to (i−1)-th element: a=[10,8].
Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[18].
Note that Polycarp could stop performing operations at any time.

Polycarp wondered how many minimum operations he would need to perform to make all the elements of a equal (i.e., he wants all ai are equal to each other).

Input
The first line contains a single integer t (1≤t≤3000) — the number of test cases in the test. Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤3000) — the length of the array. The next line contains n integers a1,a2,…,an (1≤ai≤105) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 3000.

Output
For each test case, output a single number — the minimum number of operations that Polycarp needs to perform so that all elements of the a array are the same (equal).

Example
inputCopy
4
5
3 1 6 6 2
4
1 2 2 1
3
2 2 2
4
6 3 2 1
outputCopy
4
2
0
2
Note
In the first test case of the example, the answer can be constructed like this (just one way among many other ways):

[3,1,6,6,2] −→−−−−−−−i=4, add to left [3,1,12,2] −→−−−−−−−−i=2, add to right [3,13,2] −→−−−−−−−−i=1, add to right [16,2] −→−−−−−−−i=2, add to left [18]. All elements of the array [18] are the same.

In the second test case of the example, the answer can be constructed like this (just one way among other ways):

[1,2,2,1] −→−−−−−−−−i=1, add to right [3,2,1] −→−−−−−−−i=3, add to left [3,3]. All elements of the array [3,3] are the same.

In the third test case of the example, Polycarp doesn't need to perform any operations since [2,2,2] contains equal (same) elements only.

In the fourth test case of the example, the answer can be constructed like this (just one way among other ways):

[6,3,2,1] −→−−−−−−−−i=3, add to right [6,3,3] −→−−−−−−−i=3, add to left [6,6]. All elements of the array [6,6] are the same.


*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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

	ll n;
	cin >> n;
	ll a[n], s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}

	for (ll i = n; i >= 1; i--) {
		if (s % i == 0) {
			ll s1 = s / i;
			ll s2 = 0, f = 1;
			for (ll j = 0; j < n; j++) {
				s2 += a[j];
				if (s2 > s1) {
					f = 0;
					break;
				} else if (s1 == s2) {
					s2 = 0;
				}
			}

			if (f) {
				cout << n - i;
				return;
			}
		}
	}
}



