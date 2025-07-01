
# A Button Controlled Snake Game

This project is used to implement the popular game "snake" on a ChipKit 32 Uno Board with a display such as the Basic I/O Shield. 


## Features

- Correct snake logic and behaviour
- Complete and failsafe behaviour of buttons
- Hours of fun


## Lessons Learned
We achieved our objective, despite encountering challenges along the way. While the planning phase was relatively straightforward, we had to make several adjustments as we progressed due to unforeseen circumstances. This also involved a lot of refactoring and improving the readability of our code.

During the coding phase, we evenly distributed tasks and held discussions about our thoughts and implementations before integrating them into the working code. We also established a shared GitHub repository to facilitate learning and expedite work.

Overall, this was an invaluable experience. We gained a wealth of knowledge about programming in C and assembly, locating information about ports and pins for the ChipKit Uno 32 including the Basic I/O Shield, and effective team collaboration.


## Installation

Assuming you have [Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) installed you need to follow these steps:

1 - Install gcc using the command: 

```bash
  git clone git://gcc.gnu.org/git/gcc.git SomeLocalDir
```

2 - Install [MCB32Tools](https://github.com/is1200-example-projects/mcb32tools/releases/)

3 - To compile and install on the ChipKit. Connect the board to the computer using a USB-A to micro-USB cable. Then use the following commands after navigating to the project directory:

```bash
  . '/Applications/mcb32tools.app/Contents/Resources/Toolchain/environment'
```

```bash
  make
```

```bash
  make install TTYDEV=/dev/<yourUSBserial>
```

4 - Enjoy, and try to alter the code in the files to tinker around.
## Tech Stack

**Languages:** C, MIPS Assembly, GCC

**Hardware:** ChipKit Uno32 Board, Basic I/O Shield (OLED)


## Authors

- [Bran Quanne](https://www.github.com/branquanne)
- [Abdinasir Abdi](https://www.github.com/Trek120)


## License

MIT License

Copyright (c) 2024 Bran Quanne and Abdinasir Abdi

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

