/*
C. Perform the Combo
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You want to perform the combo on your opponent in one popular fighting game. The combo is the string s consisting of n lowercase Latin letters. To perform the combo, you have to press all buttons in the order they appear in s. I.e. if s="abca" then you have to press 'a', then 'b', 'c' and 'a' again.

You know that you will spend m wrong tries to perform the combo and during the i-th try you will make a mistake right after pi-th button (1≤pi<n) (i.e. you will press first pi buttons right and start performing the combo from the beginning). It is guaranteed that during the m+1-th try you press all buttons right and finally perform the combo.

I.e. if s="abca", m=2 and p=[1,3] then the sequence of pressed buttons will be 'a' (here you're making a mistake and start performing the combo from the beginning), 'a', 'b', 'c', (here you're making a mistake and start performing the combo from the beginning), 'a' (note that at this point you will not perform the combo because of the mistake), 'b', 'c', 'a'.

Your task is to calculate for each button (letter) the number of times you'll press it.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases.

Then t test cases follow.

The first line of each test case contains two integers n and m (2≤n≤2⋅105, 1≤m≤2⋅105) — the length of s and the number of tries correspondingly.

The second line of each test case contains the string s consisting of n lowercase Latin letters.

The third line of each test case contains m integers p1,p2,…,pm (1≤pi<n) — the number of characters pressed right during the i-th try.

It is guaranteed that the sum of n and the sum of m both does not exceed 2⋅105 (∑n≤2⋅105, ∑m≤2⋅105).

It is guaranteed that the answer for each letter does not exceed 2⋅109.

Output
For each test case, print the answer — 26 integers: the number of times you press the button 'a', the number of times you press the button 'b', …, the number of times you press the button 'z'.

Example
inputCopy
3
4 2
abca
1 3
10 5
codeforces
2 8 3 2 9
26 10
qwertyuioplkjhgfdsazxcvbnm
20 10 1 2 3 5 10 5 9 4
outputCopy
4 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 9 4 5 3 0 0 0 0 0 0 0 0 9 0 0 3 1 0 0 0 0 0 0 0 
2 1 1 2 9 2 2 2 5 2 2 2 1 1 5 4 11 8 2 7 5 1 10 1 5 2 
Note
The first test case is described in the problem statement. Wrong tries are "a", "abc" and the final try is "abca". The number of times you press 'a' is 4, 'b' is 2 and 'c' is 2.

In the second test case, there are five wrong tries: "co", "codeforc", "cod", "co", "codeforce" and the final try is "codeforces". The number of times you press 'c' is 9, 'd' is 4, 'e' is 5, 'f' is 3, 'o' is 9, 'r' is 3 and 's' is 1.


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
	ll n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	ll cnt[27] = {}, a[n] = {};
	foi(m) {
		ll x;
		cin >> x;
		a[x - 1]++;
	}
	for (ll i = n - 1; i > 0; i--) {
		a[i - 1] += a[i];
	}

	foj(n) {
		cnt[s[j] - 'a'] += a[j] + 1;
	}
	foi(26)
	cout << cnt[i] << " ";

}
