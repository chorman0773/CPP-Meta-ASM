#include <asm/Program.hpp>
#include <iostream>

#define SEED 288149951
#define MAX 10

using std::cout;
using std::endl;

typedef Program<
Subroutine<
load<b,1>,
push<b>,
pop<b>,
mul<a,516599491>,
add<a,11>,
add<b,1>,
sub<b,MAX>,
brn<-5>
>,
Accumulator<SEED>>
