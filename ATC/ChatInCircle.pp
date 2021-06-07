/*
D - Chat in a Circle  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score: 
400
 points

Problem Statement
Quickly after finishing the tutorial of the online game ATChat, you have decided to visit a particular place with 
N
−
1
 players who happen to be there. These 
N
 players, including you, are numbered 
1
 through 
N
, and the friendliness of Player 
i
 is 
A
i
.

The 
N
 players will arrive at the place one by one in some order. To make sure nobody gets lost, you have set the following rule: players who have already arrived there should form a circle, and a player who has just arrived there should cut into the circle somewhere.

When each player, except the first one to arrive, arrives at the place, the player gets comfort equal to the smaller of the friendliness of the clockwise adjacent player and that of the counter-clockwise adjacent player. The first player to arrive there gets the comfort of 
0
.

What is the maximum total comfort the 
N
 players can get by optimally choosing the order of arrivals and the positions in the circle to cut into?

Constraints
All values in input are integers.
2
≤
N
≤
2
×
10
5
1
≤
A
i
≤
10
9
*/
