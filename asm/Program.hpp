#ifndef __Program_hpp_2018_05_08_16_42
#define __Program_hpp_2018_05_08_16_42

#include <asm/Register.hpp>
#include <utils/Stack.hpp>

template<class stack,class accumulator,class executingInstruction,class... instructions> struct executing_program{
  typedef executingInstruction::execute<stack,accumulator> currInstruction;
  typedef executing_program<currInstruction::stack,currInstruction::accumulator,instructions> nextInstruction;
  typedef nextInstruction::accumulator accumulator;
  typedef nextInstruction::stack stack;
};
template<class stack,class accumulator,class lastInstruction> struct executing_program<stack,accumulator,lastInstruction>{
  typedef lastInstruction::execute<stack,accumulator> currInstruction;
  typedef currInstruction::accumulator accumulator;
  typedef currInstruction::stack stack;
};


template<class... instructions> struct Program{
  typedef executing_program<Stack<>,Accumulator<0>,instructions> program;
  typedef program::accumulator accumulator;
  typedef program::stack stack;
};

#endif
