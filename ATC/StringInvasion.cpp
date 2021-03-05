/*
C - String Invasion  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
500
 points

Problem Statement
Given is a string 
S
 of length 
N
. Let 
s
i
 denote the 
i
-th character of 
S
. Find the maximum number of times the following operation can be done.

Choose three consecutive characters in 
S
, 
s
i
,
s
i
+
1
,
s
i
+
2
(
1
≤
i
≤
|
S
|
−
2
)
, such that 
s
i
=
s
i
+
1
≠
s
i
+
2
, and replace 
s
i
+
2
 with 
s
i
.
Constraints
3
≤
|
S
|
≤
2
×
10
5
S
 consists of lowercase English letters.
Input
Input is given from Standard Input in the following format:

S

Output
Print the maximum number of times the operation can be done.

Sample Input 1 
Copy
accept
Sample Output 1 
Copy
3
We can do the operation three times, as follows:

do it with 
i
=
2
, changing the string to acccpt;
do it with 
i
=
3
, changing the string to acccct;
do it with 
i
=
4
, changing the string to accccc.
Sample Input 2 
Copy
atcoder
Sample Output 2 
Copy
0
Sample Input 3 
Copy
anerroroccurred
Sample Output 3 
Copy
16
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

	string b;
	cin >> b;
	ll ans = 0;
	ll n = b.size();
	char s[n];
	foi(n) {
		s[i] = b[i];
	}

	reverse(s, s + n);
	ll cnt[256] = {0};
	foi(n) {
		int c = (int)(s[i] - 'a');
		cnt[c]++;
		if (i > 0 && s[i] == s[i - 1]) {
			for (int x = 0; x < 26; x++) {
				if (x == c)
					continue;
				ans += cnt[x];
				cnt[c] += cnt[x];
				cnt[x] = 0;
			}
		}
	}
	cout << ans;

}



