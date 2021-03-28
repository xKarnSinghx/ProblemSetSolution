/*
B - Products of Min-Max  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
Given is a sequence 
A
 of 
N
 integers. There are 
2
N
−
1
 non-empty subsequences 
B
 of 
A
. Find the sum of 
max
(
B
)
×
min
(
B
)
 over all of them.

Since the answer can be enormous, report it modulo 
998244353
.

Constraints
All values in input are integers.
1
≤
N
≤
2
×
10
5
0
≤
A
i
≤
998244352
Input
Input is given from Standard Input in the following format:

N

A
1
 
A
2
 
⋯
 
A
N

Output
Print the answer.

Sample Input 1 
Copy
3
2 4 3
Sample Output 1 
Copy
63
There are 
7
 subsequences 
B
, as follows:

B
=
(
2
)
 : 
max
(
B
)
×
min
(
B
)
=
4
B
=
(
4
)
 : 
max
(
B
)
×
min
(
B
)
=
16
B
=
(
3
)
 : 
max
(
B
)
×
min
(
B
)
=
9
B
=
(
2
,
4
)
 : 
max
(
B
)
×
min
(
B
)
=
8
B
=
(
2
,
3
)
 : 
max
(
B
)
×
min
(
B
)
=
6
B
=
(
4
,
3
)
 : 
max
(
B
)
×
min
(
B
)
=
12
B
=
(
2
,
4
,
3
)
 : 
max
(
B
)
×
min
(
B
)
=
8
The answer is the sum of them: 
63
.
*/
