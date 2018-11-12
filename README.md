
• The goal of this project is to find the quickest way to get n ants across the farm.

• Quickest way means the solution with the least number of lines, respecting the
output format requested below.

• Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.

• At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)

• We consider that all the ants are in the room ##start at the beginning of the game.

• At each turn you will only display the ants that moved.

• At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).

• You must to display your results on the standard output in the following format:

number_of_ants

the_rooms

the_links

Lx-y Lz-w Lr-o ...

x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

• Example 1 :

10

Elementary algorithmic project lem-in

[0]-[2]-[3]-[1]

zaz@blackjack /tmp/lem-in $ ./lem-in < subject.map

3

##start

0 1 0

##end

1 5 0

2 9 0

3 13 0

0-2

2-3

3-1

L1-2

L1-3 L2-2

L1-1 L2-3 L3-2

L2-1 L3-3

L3-1

zaz@blackjack /tmp/lem-in $

• Example 2.1 :

  [0]
  
  / \
  
[1] [2]

  | |
  
  | [3]
  
  \ /
  
  [4]
  
fbouquet@thepathfinder /tmp/lem-in $ ./lem-in < subject2-1.map

2

1 0 2

##start

0 2 0

##end

4 2 6

2 4 2

3 4 4

0-1

0-2

2-3

3-4

4-1

L1-1

L1-4 L2-1

L2-4

fbouquet@thepathfinder /tmp/lem-in $
