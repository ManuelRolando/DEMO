# BlackJack Game - C++

## NOTE - Windows Users
### Requirements
The following requirements are only necesary for windows users:
* MinGW - Minimal GNU(gcc collection) compiler for Windows
* CMake (For automatic compilation)

## NOTE - Linux Users
### Requirements
* g++ GNU compiler
* Cmake


After installing these follow a la **Compilation** section.

### Installation - Windows Users
#### MinGW
You should install the [MinGW](http://mingw.org/) compiler for compile this game. For this propose watch [Installation of MinGW in Windows](https://www.youtube.com/watch?v=hAnTiNm7mUE).
#### CMAke
For automatic installation you should install [CMake](https://cmake.org/download/). For this propose watch [Installation of CMake](https://www.youtube.com/watch?v=8_X5Iq9niDE)

### Installation - Linux Users
#### Debian based OS
```bash
sudo apt -y install build-essential # g++ compiler installation
sudo apt -y install cmake
```

#### Centos
```bash
sudo yum -y group install "Development Tools" # g++ compiler installation
sudo yum-y install cmake
```
#### Archlinux(ADD SUPPORT)

## Compilation
### Without CMake
The main function is in `blackjack.cpp` file(within `src` directory). You should compile it with the next command(**Run this Within src directory**):

```bash
g++ blackjack.cpp Player.cpp Answer.cpp and.cpp Deck.cpp Card.cpp Group.cpp -o blackjack_game
``` 

So you should get the `blackjack_game`executable file.
Finaly, you should run `blackjack_game`.

ENJOY PLAYING IT!


### With CMake
Create the `build` directory, then go inside the `build` directory and run the following commands:
```bash
cmake ..
cmake --build .
```

After that, you will have the `blackjack_game` executable file. So run it and ENJOY PLAYING!
