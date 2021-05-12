/*
C - To 3  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
Given is a positive integer 
N
, where none of the digits is 
0
.
Let 
k
 be the number of digits in 
N
. We want to make a multiple of 
3
 by erasing at least 
0
 and at most 
k
−
1
 digits from 
N
 and concatenating the remaining digits without changing the order.
Determine whether it is possible to make a multiple of 
3
 in this way. If it is possible, find the minimum number of digits that must be erased to make such a number.

Constraints
1
≤
N
<
10
18
None of the digits in 
N
 is 
0
.

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


//	ll t ; cin >> t;
//	while (t--)
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
	string s;
	cin >> s;
	ll t = 0;
	foi(s.size()) {
		t += s[i] - '0';
	}
	if (t % 3 == 0) {
		cout << 0;
		return;
	}
	if (t % 3 == 1) {
		if (s.size() == 1) {
			cout << -1;
			return;
		}
		if (s.size() == 2) {
			if ((s[0] - '0') % 3 == 2 and  (s[1] - '0') % 3 == 2) {
				cout << -1;
				return;
			}
		}
		foi(s.size()) {
			if ((s[i] - '0') % 3 == 1) {
				cout << 1;
				return;
			}
		}
		cout << 2;
		return;

	}
	if (t % 3 == 2) {
		if (s.size() == 1) {
			cout << -1;
			return;
		}
		if (s.size() == 2) {
			if ((s[0] - '0') % 3 == 1 and  (s[1] - '0') % 3 == 1) {
				cout << -1;
				return;
			}
		}
		foi(s.size()) {
			if ((s[i] - '0') % 3 == 2) {
				cout << 1;
				return;
			}

		}
		cout << 2;
		return;

	}
}
