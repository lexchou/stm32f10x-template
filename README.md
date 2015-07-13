STM32F10x Bootstrap template
==========================
This is my bootstrap template for starting a new STM32F10x project.


## Features
* A shell script *stm32* that can burn image to board, and start GDB for remote debugging, and reset the board.
* Stack allocation
* ISR Vectors
* System Initialization

## Dependencies
GCC for ARM
OpenOCD
STM32F103's periph library

## Building
```
cmake -G 'Unix Makefiles'
make
```

## Credit
This template project was made in 2013, some files are from internet but I can't remember where they're from.
