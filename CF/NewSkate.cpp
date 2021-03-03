/*
B. New Skateboard
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Max wants to buy a new skateboard. He has calculated the amount of money that is needed to buy a new skateboard. He left a calculator on the floor and went to ask some money from his parents. Meanwhile his little brother Yusuf came and started to press the keys randomly. Unfortunately Max has forgotten the number which he had calculated. The only thing he knows is that the number is divisible by 4.

You are given a string s consisting of digits (the number on the display of the calculator after Yusuf randomly pressed the keys). Your task is to find the number of substrings which are divisible by 4. A substring can start with a zero.

A substring of a string is a nonempty sequence of consecutive characters.

For example if string s is 124 then we have four substrings that are divisible by 4: 12, 4, 24 and 124. For the string 04 the answer is three: 0, 4, 04.

As input/output can reach huge size it is recommended to use fast input/output methods: for example, prefer to use gets/scanf/printf instead of getline/cin/cout in C++, prefer to use BufferedReader/PrintWriter instead of Scanner/System.out in Java.

Input
The only line contains string s (1 ≤ |s| ≤ 3·105). The string s contains only digits from 0 to 9.

Output
Print integer a — the number of substrings of the string s that are divisible by 4.

Note that the answer can be huge, so you should use 64-bit integer type to store it. In C++ you can use the long long integer type and in Java you can use long integer type.

Examples
inputCopy
124
outputCopy
4
inputCopy
04
outputCopy
3
inputCopy
5810438174
outputCopy
9

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


		solve();


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
	string str;
	cin >> str;
	ll ans = 0;
	for (ll i = 0; i < str.size(); i++) {
		ll a = int(str[i] - '0');
		if (a % 4 == 0)
			ans++;
		if (i) {
			ll b = int(str[i - 1] - '0');
			if ((b * 10 + a) % 4 == 0)
				ans += i;
		}
	}
	cout << ans ;

}



