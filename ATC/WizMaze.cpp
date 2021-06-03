/*
D - Wizard in Maze  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
A maze is composed of a grid of 
H
×
W
 squares - 
H
 vertical, 
W
 horizontal.

The square at the 
i
-th row from the top and the 
j
-th column from the left - 
(
i
,
j
)
 - is a wall if 
S
i
j
 is # and a road if 
S
i
j
 is ..

There is a magician in 
(
C
h
,
C
w
)
. He can do the following two kinds of moves:

Move A: Walk to a road square that is vertically or horizontally adjacent to the square he is currently in.
Move B: Use magic to warp himself to a road square in the 
5
×
5
 area centered at the square he is currently in.
In either case, he cannot go out of the maze.

At least how many times does he need to use the magic to reach 
(
D
h
,
D
w
)
?

Constraints
1
≤
H
,
W
≤
10
3
1
≤
C
h
,
D
h
≤
H
1
≤
C
w
,
D
w
≤
W
S
i
j
 is # or ..
S
C
h
C
w
 and 
S
D
h
D
w
 are ..
(
C
h
,
C
w
)
≠
(
D
h
,
D
w
)

*/
