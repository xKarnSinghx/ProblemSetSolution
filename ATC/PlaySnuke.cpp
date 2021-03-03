/*
B - Play Snuke  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Takahashi wants to buy the popular video game console called Play Snuke.
There are 
N
 shops that sell Play Snuke: Shop 
1
,
2
,
…
,
N
. Shop 
i
 is 
A
i
 minutes' walk from where Takahashi is now, sells Play Snuke for 
P
i
 yen (Japanese currency), and currently has 
X
i
 Play Snukes in stock.
Now, Takahashi will go to one of those shops on foot and buy Play Snuke if it is still in stock when he gets there.
However, Play Snuke is so popular that the number of consoles in stock (if any) in every shop will decrease by 
1
 at the following moments: 
0.5
,
1.5
,
2.5
,
…
 minutes from now.
Determine whether Takahashi can buy Play Snuke. If he can, find the minimum amount of money needed to buy one.

Constraints
All values in input are integers.
1
≤
N
≤
10
5
1
≤
A
i
,
P
i
,
X
i
≤
10
9
Input
Input is given from Standard Input in the following format:

N

A
1
 
P
1
 
X
1

⋮

A
N
 
P
N
 
X
N

Output
If Takahashi can buy Play Snuke, print the minimum amount of money needed to buy one, as an integer.
If he cannot buy one, print -1.

Sample Input 1 
Copy
3
3 9 5
4 8 5
5 7 5
Sample Output 1 
Copy
8
If he goes to Shop 
1
, it will still have 
2
 Play Snukes when he gets there, and he can buy one for 
9
 yen.
If he goes to Shop 
2
, it will still have 
1
 Play Snuke when he gets there, and he can buy one for 
8
 yen.
If he goes to Shop 
3
, Play Snuke will be out of stock when he gets there; he cannot buy one.

Sample Input 2 
Copy
3
5 9 5
6 8 5
7 7 5
Sample Output 2 
Copy
-1
Sample Input 3 
Copy
10
158260522 877914575 602436426
24979445 861648772 623690081
433933447 476190629 262703497
211047202 971407775 628894325
731963982 822804784 450968417
430302156 982631932 161735902
880895728 923078537 707723857
189330739 910286918 802329211
404539679 303238506 317063340
492686568 773361868 125660016
Sample Output 3 
Copy
861648772
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


void solve()
{

	ll n;
	cin >> n;
	ll a[n], p[n], y[n];
	foi(n) {
		cin >> a[i] >> p[i] >> y[i];
	}
	ll mn = 111111111111111111;
	foi(n) {
		y[i] -= a[i];
		if (y[i] > 0)
			mn = min(mn, p[i]);
	}
	if (mn > 0 && mn < 111111111111111111)
		cout << mn;
	else
		cout << -1;
}



