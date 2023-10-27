# Minesweeper Game

Welcome to Minesweeper, a classic game implemented in C with a user-friendly interface powered by the ncurses library.

## Features
- Clean and intuitive user interface.
- Customizable grid size and mine density.
- Flagging and revealing cells.
- Win and lose conditions with informative messages.

## How to Play
1. Navigate the grid using arrow keys.
2. Press 'f' to flag a cell.
3. Press 'r' to reveal a cell.
4. Avoid revealing mines to win the game.

## Cloning the Project

To clone the repository, use the following command:
```git clone https://github.com/Maclow42/Minesweeper.git```

## Installing Dependencies

Before compiling the project, make sure you have the ncurses library installed on your system.

On Debian-based systems, you can install it with:
```sudo apt-get install libncurses5-dev libncursesw5-dev```

On Red Hat-based systems, use:
```sudo yum install ncurses-devel```

On Manjaro-based systems, use:
```pamac install ncurses```

## Compilation

To Navigate, compile and execute the game, use the following command:
```cd Minesweeper && make && make run```

## License
(MIT License)

Copyright (c) 2023 Maclow42 <maclow.cartier@hotmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.