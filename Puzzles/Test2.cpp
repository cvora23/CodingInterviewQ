/*
 * Test2.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: chintan
 */
/*
 * Puzzle 37 | (Maximum run in cricket)
Question: In a one day international cricket match, considering no extras
(no wides, no ‘no’ balls, etc.) and no overthrows.
What is the maximum number of runs that a batsman can score in an ideal case ?
Note:”Here we assume ideal and little practical scenario.
We assume that batsman can not run for more than 3 runs in a ball,
as otherwise there is no limit, he can run infinite runs(theoretically)
in a ball, as far as opposite team does not catch the ball.”







Answer:
49*(6*5+3)+(6*6)= 1653
From Over 1 to 49:
1st ball:- 6 runs(hit six)
2nd ball:- 6 runs(hit six)
3rd ball:- 6 runs(hit six)
4th ball:- 6 runs(hit six)
5th ball:- 6 runs(hit six)
6th ball:- 3 runs(took 3 runs between the wickets and take back the strike)
= >49*(6*5+3)
50th Over:
Hit six sixes in a row.
= >6*6
 */



