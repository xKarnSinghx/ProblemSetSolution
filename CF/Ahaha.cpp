/*
A. Ahahahahahahahaha
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alexandra has an even-length array a, consisting of 0s and 1s. The elements of the array are enumerated from 1 to n. She wants to remove at most n2 elements (where n — length of array) in the way that alternating sum of the array will be equal 0 (i.e. a1−a2+a3−a4+…=0). In other words, Alexandra wants sum of all elements at the odd positions and sum of all elements at the even positions to become equal. The elements that you remove don't have to be consecutive.

For example, if she has a=[1,0,1,0,0,0] and she removes 2nd and 4th elements, a will become equal [1,1,0,0] and its alternating sum is 1−1+0−0=0.

Help her!

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤103). Description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤103, n is even)  — length of the array.

The second line contains n integers a1,a2,…,an (0≤ai≤1)  — elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 103.

Output
For each test case, firstly, print k (n2≤k≤n) — number of elements that will remain after removing in the order they appear in a. Then, print this k numbers. Note that you should print the numbers themselves, not their indices.

We can show that an answer always exists. If there are several answers, you can output any of them.

Example
inputCopy
4
2
1 0
2
0 0
4
0 1 1 1
4
1 1 0 0
outputCopy
1
0
1
0
2
1 1
4
1 1 0 0
Note
In the first and second cases, alternating sum of the array, obviously, equals 0.

In the third case, alternating sum of the array equals 1−1=0.

In the fourth case, alternating sum already equals 1−1+0−0=0, so we don't have to remove anything.

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
	ll a[n], s = 0, z = 0, f = 0, res = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (x == 1)
			s++;
		else
			z++;
		if (x == 1 and f == 0) {
			f = 1;
			res = i;
		}
	}
	if (s <= n / 2) {
		cout << n - s << endl;
		foi(n - s)
		cout << 0 << " ";
		return;
	}
	else {
		if (z % 2 == 0 and n % 2 == 0) {
			cout << n - z << endl;
			foi(n - z)
			cout << 1 << " ";
			return;
		}
		if (z % 2 == 0 and n % 2 == 1) {
			cout << n - z - 1 << endl;
			foi(n - z - 1)
			cout << 1 << " ";
			return;
		}
		if (z % 2 == 1 and n % 2 == 1) {
			cout << n - z << endl;
			foi(n - z)
			cout << 1 << " ";
			return;
		}
		if (z % 2 == 1 and n % 2 == 0) {
			cout << n - z - 1 << endl;
			foi(n) {
				if (a[i] == 0)
					continue;
				else if (i == res)
					continue;
				else
					cout << a[i] << " ";
			}
			return;
		}


	}
}
