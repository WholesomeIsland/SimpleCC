#include <stdio.h>
void test( int t){ printf("Calling a self declared function\n");t = 6;}int main(){  printf("Hello World From SimpleC!\n");int t = 0; test(t);if(t = 6 ){; printf("t equals 6\n");}}