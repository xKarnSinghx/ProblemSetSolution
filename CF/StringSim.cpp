/*
A. String Similarity
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A binary string is a string where each character is either 0 or 1. Two binary strings a and b of equal length are similar, if they have the same character in some position (there exists an integer i such that ai=bi). For example:

10010 and 01111 are similar (they have the same character in position 4);
10010 and 11111 are similar;
111 and 111 are similar;
0110 and 1001 are not similar.
You are given an integer n and a binary string s consisting of 2n−1 characters. Let's denote s[l..r] as the contiguous substring of s starting with l-th character and ending with r-th character (in other words, s[l..r]=slsl+1sl+2…sr).

You have to construct a binary string w of length n which is similar to all of the following strings: s[1..n], s[2..n+1], s[3..n+2], ..., s[n..2n−1].

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤50).

The second line of each test case contains the binary string s of length 2n−1. Each character si is either 0 or 1.

Output
For each test case, print the corresponding binary string w of length n. If there are multiple such strings — print any of them. It can be shown that at least one string w meeting the constraints always exists.

Example
inputCopy
4
1
1
3
00000
4
1110000
2
101
outputCopy
1
000
1010
00
Note
The explanation of the sample case (equal characters in equal positions are bold):

The first test case:

1 is similar to s[1..1]=1.
The second test case:

000 is similar to s[1..3]=000;
000 is similar to s[2..4]=000;
000 is similar to s[3..5]=000.
The third test case:

1010 is similar to s[1..4]=1110;
1010 is similar to s[2..5]=1100;
1010 is similar to s[3..6]=1000;
1010 is similar to s[4..7]=0000.
The fourth test case:

00 is similar to s[1..2]=10;
00 is similar to s[2..3]=01.

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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	ll n;
	cin >> n;
	ll s = 0;
	string t;
	cin >> t;
	foi(2 * n - 1) {
		if (t[i] == '1')
			s++;
	}
	if (s == 2 * n - 1) {
		foi(n)
		cout << 1;
		return;
	}
	if (s == 0) {
		foi(n)
		cout << 0;
		return;
	}
	foi(2 * n - 1) {
		if (i % 2 == 0)
			cout << t[i];
	}




}

