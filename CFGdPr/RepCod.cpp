/*
D. Repetitions Decoding
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Olya has an array of integers a1,a2,…,an. She wants to split it into tandem repeats. Since it's rarely possible, before that she wants to perform the following operation several (possibly, zero) number of times: insert a pair of equal numbers into an arbitrary position. Help her!

More formally:

A tandem repeat is a sequence x of even length 2k such that for each 1≤i≤k the condition xi=xi+k is satisfied.
An array a could be split into tandem repeats if you can split it into several parts, each being a subsegment of the array, such that each part is a tandem repeat.
In one operation you can choose an arbitrary letter c and insert [c,c] to any position in the array (at the beginning, between any two integers, or at the end).
You are to perform several operations and split the array into tandem repeats or determine that it is impossible. Please note that you do not have to minimize the number of operations.
Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤30000) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤500).

The second line contains n integers a1,a2,…,an (1≤ai≤109)  — the initial array.

It is guaranteed that the sum of n2 over all test cases does not exceed 250000.

Output
For each test case print answer in the following format.

If you cannot turn the array into a concatenation of tandem repeats, print a single integer −1.

Otherwise print the number of operations q (0≤q≤2⋅n2) that you want to do. Then print the descriptions of operations.

In each of the following q lines print two integers p and c (1≤c≤109), which mean that you insert the integer c twice after p elements of the array. If the length of the array is m before the operation, then the condition 0≤p≤m should be satisfied.

Then you should print any way to split the resulting array into tandem repeats. First, print a single integer d, and then print a sequence t1,t2,…,td of even integers of size d (d,ti≥1). These numbers are the lengths of the subsegments from left to right.

Note that the size of the resulting array a is m=n+2⋅q. The following statements must hold:

m=∑i=1dti.
For all integer i such that 1≤i≤d, the sequence al,al+1,…,ar is a tandem repeat, where l=∑j=1i−1tj+1, r=l+ti−1.
It can be shown that if the array can be turned into a concatenation of tandem repeats, then there exists a solution satisfying all constraints. If there are multiple answers, you can print any.

Example
inputCopy
4
2
5 7
2
5 5
6
1 3 1 2 2 3
6
3 2 1 1 2 3
outputCopy
-1
0
1
2
4
1 3
5 3
5 3
10 3
2
8 6 
5
0 3
8 3
5 3 
6 2 
7 1
4
2 6 6 2
Note
In the first test case, you cannot apply operations to the array to make it possible to split it into tandem repeats.

In the second test case the array is already a tandem repeat [5,5]=([5]+[5])t1=2, thus we can do no operations at all.

In the third test case, initially, we have the following array:
[1,3,1,2,2,3].
After the first insertion with p=1,c=3:
[1,3, 3,3,1,2,2,3].
After the second insertion with p=5,c=3:
[1,3,3,3,1,3, 3,2,2,3].
After the third insertion with p=5,c=3:
[1,3,3,3,1,3, 3,3,3,2,2,3].
After the fourth insertion with p=10,c=3:
[1,3,3,3,1,3,3,3,3,2,3, 3,2,3].
The resulting array can be represented as a concatenation of tandem repeats:
([1,3,3,3]+[1,3,3,3])t1=8+([3,2,3]+[3,2,3])t2=6.
In the fourth test case, initially, we have the following array:
[3,2,1,1,2,3].
After the first insertion with p=0,c=3:
[3, 3,3,2,1,1,2,3].
After the second insertion with p=8,c=3:
[3,3,3,2,1,1,2,3,3, 3].
After the third insertion with p=5,c=3
[3,3,3,2,1,3, 3,1,2,3,3,3].
After the fourth insertion with p=6,c=2:
[3,3,3,2,1,3,2, 2,3,1,2,3,3,3].
After the fifth insertion with p=7,c=1:
[3,3,3,2,1,3,2,1, 1,2,3,1,2,3,3,3].
The resulting array can be represented as a concatenation of tandem repeats:
([3]+[3])t1=2+([3,2,1]+[3,2,1])t2=6+([1,2,3]+[1,2,3])t3=6+([3]+[3])t4=2.

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
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	mll m;
	foi(n) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (auto x : m) {
		if (x.ss % 2) {
			cout << -1;
			return;
		}
	}
	vector<array<ll, 2>>oper;
	vll t;
	ll s = n, idx = 0;
	while (idx < s) {
		ll i = idx, j = -1;
		for (ll k = i + 1; k < s; k++) {
			if (a[k] == a[i]) {
				j = k;
				break;
			}
		}
		idx = j + 1;
		ll put = idx;
		for (ll k = i + 1; k < j; k++) {
			oper.pb({put, a[k]});
			a.insert(a.begin() + put, a[k]);
			a.insert(a.begin() + put, a[k]);
			put++, s += 2, idx++;
		}
		t.pb(2 * (j - i));
	}
	cout << oper.size() << endl;
	foi(oper.size()) {
		cout << oper[i][0] << " " << oper[i][1] << endl;
	}
	foi(t.size()) {
		cout << t[i] << " ";
	}

}
