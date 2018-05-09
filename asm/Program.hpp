#ifndef __Program_hpp_2018_05_08_16_42
#define __Program_hpp_2018_05_08_16_42

#include <asm/Register.hpp>
#include <utils/Stack.hpp>

template<class stack,class acca,class accb,class ip,class flags,class prg,class executingInstruction> struct executing_program{
  typedef executingInstruction::execute<stack,acca,accb,ip,flags> currInstruction;
  typedef prg::next<stack,acca,accb,ip,flags> nextInstruction;
  typedef nextInstruction::stack stack;
  typedef nextInstruction::acca acca;
  typedef nextInstruction::accb accb;
  typedef nextInstruction::instructionPointer instructionPointer;
  typedef nextInstruction::flags flags;
};

template<class stack,class acca,class accb,class ip,class flags,class prg> struct 
  executing_program<stack,acca,accb,ip,flags,prg,void>{
  typedef stack stack;
  typedef acca acca;
  typedef accb accb;
  typedef ip instructionPointer;
  typedef flags flags;
};


template<class currInstrution,class... rest> struct get_instruction{
  typedef get_instruction<position-1,rest>::ins ins;
};

template<class currInstruction,class... rest> struct get_instruction<0,currInstruction,rest>{
   typedef currInstruction ins;
};

template<size_t pos,class currInstruction> struct get_instruction<pos,currInstruction>{
  typedef void ins;
};

template<class currInstruction> struct get_instruction<0,currInstruction>{
  typedef currInstruction ins;
};



template<class... instructions> struct Program{
  typedef executing_program<Stack<>,Accumulator<0>,Accumulator<0>,InstructionPointer<0>,Flags<false,false>,Program<instructions>> program;
  typedef program::acca acca;
  typedef program::accb accb;
  typedef program::stack stack;
  typedef program::ip ip;
  typedef program::flags flags;
  template<class inStack,class inAcc,class inIp,class inFlags> next: 
    executing_program<inStack,inAcc,inIp,inFlags,Program<instructions>,get_instruction<inIp::value,instructions>>{};
};

#endif
