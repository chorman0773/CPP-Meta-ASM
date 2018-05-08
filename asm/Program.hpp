#ifndef __Program_hpp_2018_05_08_16_42
#define __Program_hpp_2018_05_08_16_42

#include <asm/Register.hpp>
#include <utils/Stack.hpp>

template<class stack,class accumulator,class nextInstruction,class... instructions> struct executing_program{
  typedef nextInstruction::execute<stack,accumulator> currInstruction;
  typedef executing_program<currInstruction::stack,currInstruction::accumulator,instructions> nextInstruction;
};
template<class stack,class accumulator,class lastInstruction> struct executing_program<stack,accumulator,lastInstruction>{
  typedef nextInstruction::execute<stack,accumulator> currInstruction;
};


template<class... instructions> struct Program{
  typedef executing_program<Stack<>,Accumulator<0>,instructions> program;
};

#endif
