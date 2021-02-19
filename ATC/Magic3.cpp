/*
B - Magic 3  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Takahashi, the magician, is fighting with a monster.
He can use 
N
 spells.
The 
i
-th spell takes 
X
i
 seconds to cast and has a power 
Y
i
.
However, the monster is strong enough to avoid taking damage from spells taking 
S
 or more seconds to cast and spells with powers 
D
 or less.
Also, there is nothing other than spells that can do damage to the monster.
Can Takahashi do damage to the monster?

Constraints
All values in input are integers.
1
≤
N
≤
100
1
≤
X
i
≤
10
9
1
≤
Y
i
≤
10
9
1
≤
S
≤
10
9
1
≤
D
≤
10
9
Input
Input is given from Standard Input in the following format:

N
 
S
 
D

X
1
 
Y
1

⋮

X
N
 
Y
N

Output
If Takahashi can do damage to the monster, print Yes; otherwise, print No.

Sample Input 1 
Copy
4 9 9
5 5
15 5
5 15
15 15
Sample Output 1 
Copy
Yes
The second and fourth spells take too much time to do damage.
Also, the first and second spells do not have enough powers to do damage.
Thus, only the third spell can do damage.

Sample Input 2 
Copy
3 691 273
691 997
593 273
691 273
Sample Output 2 
Copy
No
Sample Input 3 
Copy
7 100 100
10 11
12 67
192 79
154 197
142 158
20 25
17 108
Sample Output 3 
Copy
Yes
Only the seventh spell can do damage.

*/
#include<bits/stdc++.h>
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
void solve()

{

	ll n, b, c;
	cin >> n >> b >> c;
	vpll a(n);
	foi (n)
	cin >> a[i].ff >> a[i].ss;
	ll z = 0;
	foi (n)
	{	if ( a[i].ff < b && a[i].ss > c)
		{	z++;
			break;
		}
	}
	if (z != 0)
		cout << "Yes";
	else
		cout << "No";

}




