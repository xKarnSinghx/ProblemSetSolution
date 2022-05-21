/*
D. Traps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n traps numbered from 1 to n. You will go through them one by one in order. The i-th trap deals ai base damage to you.

Instead of going through a trap, you can jump it over. You can jump over no more than k traps. If you jump over a trap, it does not deal any damage to you. But there is an additional rule: if you jump over a trap, all next traps damages increase by 1 (this is a bonus damage).

Note that if you jump over a trap, you don't get any damage (neither base damage nor bonus damage). Also, the bonus damage stacks so, for example, if you go through a trap i with base damage ai, and you have already jumped over 3 traps, you get (ai+3) damage.

You have to find the minimal damage that it is possible to get if you are allowed to jump over no more than k traps.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers n and k (1≤n≤2⋅105, 1≤k≤n) — the number of traps and the number of jump overs that you are allowed to make.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — base damage values of all traps.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case output a single integer — the minimal total damage that it is possible to get if you are allowed to jump over no more than k traps.

Example
inputCopy
5
4 4
8 7 1 4
4 1
5 10 11 5
7 5
8 2 5 15 11 2 8
6 3
1 2 3 4 5 6
1 1
7
outputCopy
0
21
9
6
0
Note
In the first test case it is allowed to jump over all traps and take 0 damage.

In the second test case there are 5 ways to jump over some traps:

Do not jump over any trap.
Total damage: 5+10+11+5=31.

Jump over the 1-st trap.
Total damage: 0–+(10+1)+(11+1)+(5+1)=29.

Jump over the 2-nd trap.
Total damage: 5+0–+(11+1)+(5+1)=23.

Jump over the 3-rd trap.
Total damage: 5+10+0–+(5+1)=21.

Jump over the 4-th trap.
Total damage: 5+10+11+0–=26.

To get minimal damage it is needed to jump over the 3-rd trap, so the answer is 21.

In the third test case it is optimal to jump over the traps 1, 3, 4, 5, 7:

Total damage: 0+(2+1)+0+0+0+(2+4)+0=9.


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
const ll N = 1000001;
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
void solve() {
	ll n, k;
	cin >> n >> k;
	vll a(n);
	ll s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
		a[i] = n - i - 1 - a[i];
	}
	sort(all(a));
	foi(k) {
		s += a[i];
	}
	cout << s - k*(k - 1) / 2;
}
