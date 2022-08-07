# Toy Robot Code Challenge

## Description and requirements

* The application is a simulation of a toy robot moving on a square tabletop, of dimensions 5 units x 5 units. 
* There are no other obstructions on the table surface.
* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. 
* Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.
* Create a console application that can read in commands of the following form:
```
PLACE X,Y,F  
MOVE  
LEFT  
RIGHT  
REPORT  
```

* **PLACE** will put the toy robot on the table in position **X**,**Y** and facing **NORTH**, **SOUTH**, **EAST** or **WEST**.
* The **origin** (0,0) can be considered to be the **SOUTH WEST** most corner.
* It is **required** that the first command to the robot is a **PLACE** command, after that, any sequence of commands may be issued, in any order, including another PLACE command. 
* The application should discard all commands in the sequence until a valid **PLACE** command has been executed
* **MOVE** will move the toy robot one unit forward in the direction it is currently facing.
* **LEFT** and **RIGHT** will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
* **REPORT** will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.
* A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
* Input can be from a file, or from standard input, as the developer chooses.
* Provide test data to exercise the application.
* It is not required to provide any graphical output showing the movement of the toy robot.
* The application should handle error states appropriately and be robust to user input.

## Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
* Any move that would cause the robot to fall must be ignored.

## Example Input and Output:

### Example a
```
PLACE 0,0,NORTH  
MOVE  
REPORT  
```
#### Expected output:
`0,1,NORTH`

### Example b
```
PLACE 0,0,NORTH  
LEFT  
REPORT  
```
#### Expected output:
`0,0,WEST`

### Example c
```
PLACE 1,2,EAST  
MOVE  
MOVE  
LEFT  
MOVE  
REPORT  
```
#### Expected output
`3,3,NORTH`

## How to build the project
Although you can easily make in-source builds for this project with some IDEs (such as CLion, Visual Studio), it is recommended that to build the project out of source.   

### Dependencies
You might need to install some dependencies before starting:
* **cmake** (version 3.16.3 or above)   
You can download it here `https://cmake.org/download/`, or alternatively install it with the following commands:
```
Ubuntu: apt install cmake      
macOS: brew install cmake   
```
* **boost** (version 1.79 or above):   
You can download it here `https://www.boost.org/users/history/version_1_79_0.html` and compile, or alternatively install it with the following commands:   
```
Ubuntu: apt install libboost-dev   
macOS: brew install boost   
```
After that, you might need to add `${BOOST_ROOT}` and `${BOOST_INCLUDEDIR}` to your environment variables if it hasn't been added automatically.     
   
Such as on macOS (when boost was installed by homebrew):
```
$ export BOOST_ROOT=/usr/local/Cellar/boost/1.79.0_1
$ export BOOST_INCLUDEDIR=$BOOST_ROOT/include
```

### Build & Run   

* Clone repo:   
```
$ git clone git@github.com:darwinsww/ToyRobot.git
```   

* Build project:
```
$ cd ToyRobot   
$ mkdir build && cd build   
$ cmake ../   
$ make
```

* Run Toy Robot: 
```
./ToyRobot
```

* Run all unit test:
```
cd test   
./testToyRobot   
```
