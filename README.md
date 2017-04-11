To build:
<code>make</code>
The tic tac toe board is represented as a string of decimal points. The points are the empty spaces and the 'X' will be your move, 'O' will be the computers move.

So  the state  X..   will be represented as X...O....
               .O.
               ...

Pass X...O.... as a command line argument like so:

<code>./ttt X...O....</code>

the computer will return it's move as 'O'. Most likely for the last call:

<code>XO..O....</code>

Use that string with your move as 'X' for the next funcion call.
