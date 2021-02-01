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
