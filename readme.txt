Type make to build.
The tic tac toe board is represented as a string of decimal points. The points are the empty spaces and the 'X' will be your move, 'O' will be the computers move.

So  the state  X..   will be represented as X...O....
               .O.
               ...

Pass X...O.... to like so:

./ttt X...O....

the computer will return it's move as 'O'. Most likely for the last call:

XO..O....

Use that string with your move as 'X' for the next funcion call.
