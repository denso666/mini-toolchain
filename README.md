# Mini-toolchain

A basic set of commands to implement into your development board.
See `src/README.md` for more information and the state about the toolchain.

## How to compile
1. Take care with the specific architecture about your board, you will need a specific compiler, or toolchain, version. See your board and processor details. You will need make a intensive research about the correct toolchain and his version for a good integration.
2. For see an example about _how to make a rule_, check the outer Makefile (`arm` and `x86_64` are basic rules).
 