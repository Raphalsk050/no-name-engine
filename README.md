# no-name-engine

## How to clone the project

This project has some third_party lib dependencies like:
- bullet-physics sdk
- glfw
- glew

you must clone the project and initialize the .gitmodules

`git clone --recursive https://github.com/Raphalsk050/no-name-engine.git`

Note: if you already have cloned the project, to initialize the gitmodules use:

`git submodule update --init --recursive`

## How to build

make a build folder

`mkdir build`

Go to this folder

`cd build`

run

`cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_POLICY_VERSION_MINIMUM=3.5`

after completed, run

`make`

and then, run

`./no-name-engine`
