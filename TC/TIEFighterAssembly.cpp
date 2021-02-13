/*
Problem Statement
 
    |-O-|    |-O-|    |-O-|    |-O-|    |-O-|

Above you see a tiny fraction of our glorious imperial fleet, the Twin Ion Engine starfighters (known as "TIE fighters" for short).

Each TIE fighter consists of two solar array wings ('|'), two wing braces ('-') and one central cabin ('O').
Even though our TIE fighters are clearly superior to the X-wing fighters flown by those pesky rebels, occasionally some TIE fighter will receive some accidental combat damage. Whenever a damaged TIE fighter is recovered, we disasemble it and salvage the parts that are still in working condition. It is now up to you to use these salvaged parts to assemble as many complete TIE fighters as possible.


You are given the salvagedParts. Each character of salvagedParts represents one piece of machinery that has been salvaged. As mentioned above, the characters '|', '-', and 'O' (uppercase oh) represent the parts you need to build a TIE fighter.

There may also be other characters in salvagedParts. These represent machinery that isn't used in a TIE fighter.
Calculate and return the maximum number of TIE fighters you can assemble from the given parts.

Definition
Class: TIEFighterAssembly
Method: assemble
Parameters: string
Returns: int
Method signature: int assemble(string salvagedParts)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Constraints
- salvagedParts will contain between 1 and 50 characters, inclusive.
- Each character of salvagedParts will be one of "|-O=+()*" (quotes for clarity).
Examples
0)
"|-O-|"
Returns: 1
One fully functional TIE fighter.
1)
"||--O"
Returns: 1
The same parts as in the previous example. Again, we can use them to build one TIE fighter.
2)
"|||||-----OOO"
Returns: 2
These parts are enough to build two TIE fighters. We will have one '|', one '-' and one 'O' left over.
3)
"=+()*=+()*=+()*"
Returns: 0
Useless debris that cannot be used in a TIE fighter.
4)
"||+||-||+||-||+||-||+||-"
Returns: 0
We have a lot of solar panels and a lot of wing pylons (and also some '+' that we have no use for). However, we have no central cabins and so we cannot assemble any complete TIE fighters.
5)
"===O|O-O|O-O|O==="
Returns: 1
In this example we have the opposite problem: too many cabins but not enough wing parts to use all of them. We can put together just one single TIE fighter. A lot of material will remain unused.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
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
typedef pair<int, pii>      piii;
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
class TIEFighterAssembly {
public:
int assemble(string salvagedParts){
int c=0,c1=0,c2=0,mn=111111;
    foi(salvagedParts.size()){
    if(salvagedParts[i]=='|')
   { c++;}
    if(salvagedParts[i]=='-')
    {c1++;}
    if(salvagedParts[i]=='O')
    {c2++;}
    }
      c=c/2;
    c1=c1/2;
    mn=min(mn,c);
     mn=min(mn,c1);
     mn=min(mn,c2);
     mn=min(mn,c);
     mn=min(mn,c1);
     mn=min(mn,c2);

	return mn;
}
};
