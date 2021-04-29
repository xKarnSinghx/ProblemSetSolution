/*
A. Text Volume
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a text of single-space separated words, consisting of small and capital Latin letters.

Volume of the word is number of capital letters in the word. Volume of the text is maximum volume of all words in the text.

Calculate the volume of the given text.

Input
The first line contains one integer number n (1 ≤ n ≤ 200) — length of the text.

The second line contains text of single-space separated words s1, s2, ..., si, consisting only of small and capital Latin letters.

Output
Print one integer number — volume of text.

Examples
inputCopy
7
NonZERO
outputCopy
5
inputCopy
24
this is zero answer text
outputCopy
0
inputCopy
24
Harbour Space University
outputCopy
1
Note
In the first example there is only one word, there are 5 capital letters in it.

In the second example all of the words contain 0 capital letters.


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
ll TT = 1;
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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

void solve()
{
	ll n;
	cin >> n ;
	string s;
	ll ans = 0, an = 0;
	while(cin>>s){
		foi(s.size()){
		if (s[i] - 'a' < 0 and s[i]!=' ')
			an++;
		}
			ans = max(ans, an);
			an = 0;
	}
	ans = max(ans, an);
	cout << ans;

}

 
