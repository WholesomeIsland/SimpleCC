# SimpleCC

SimpleCC stands for SimpleC Compiler.

SimpleC is a subset of the C programming language with a lua/pascal-like syntax. 
a hello world program with a few other tests can be seen in test.simplec. 

SimpleC has full compatability with the C programming language and can use most if not all C libraries. 

# How it works

it uses some very careful string manipulation to replace keywords in the file. 
this also means that some keywords cannot appear at all in function or variable names.
for example, 
if i have a function like this,
```lua
declare void thentest

end
```
that would translate to,
```c
void ){test(){
```
so please be careful.

# keywords
here is a list of all the keywords,

```lua
if then end main switch else uint --[[all valid C types]] Call declare --[[Any thing not listed here is the same way you do it in C]]
```
###### there is no pascal in this repo. i had to change simplec to pascal for syntax highlighting


# License
This is licensed under the GPL-v2.0


# CI 
![CI](https://github.com/WholesomeIsland/SimpleCC/workflows/CI/badge.svg)

#Building
## Dependancies
To build scc, you need,
1. libc
2. libc++
3. a c++ compiler
4. cmake or VS2019

## building

you can use cmake to build projects for your build system of choice, or you can use the included VS2019 prject files in the build directory.
#### CMake
```
cd build && mkdir projfiles && cmake ../../ && [insert build command here]
```
it should output a executable called scc. you can add this directory to your path or if on linux you can just move it to a location in your path.

for make use the command found in the github actions workflow file under run.

## Getting prebuilt binaries
A prebuilt binary is avalible for linux, windows and macos. go to actions and the latest succsesful workflow will have a binary for you. they are bundled together in a zip file.
Im pretty sure all fo them are 64 bit binaries.
