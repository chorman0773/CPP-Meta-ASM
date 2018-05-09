#ifndef __Instructions_hpp_2018_05_08_16_56
#define __Instructions_hpp_2018_05_08_16_56

#include <type_traits>
#include "Registers.hpp"

enum Register{
  a,b
};

template<Register r,int val> class load{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<val>,inAccb>::type accb;
    typedef inIp ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,int val> class add{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value+val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value+val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

 template<Register r,int val> class sub{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value-val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value-val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};
 template<Register r,int val> class mul{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value*val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value*val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0 > flags;
  };
};

 template<Register r,int val> class div{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<r==a,inAcca,inAccb>::type inAcc;
    typedef inStack stack;
    typedef Accumulator<inAcca:value/val> acca;
    typedef Accumulator<inAcc::value%val> accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,Register val> class load{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAcc::value>,inAccb>::type accb;
    typedef inIp ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,Register val> class add{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value+inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value+inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

 template<Register r,Register val> class sub{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value-inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value-inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};
 template<Register r,Register val> class mul{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value*inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value*inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0 > flags;
  };
};

 template<Register r,Register val> class div{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<r==a,inAcca,inAccb> dividend;
    typedef std::conditional<val==a,inAcca,inAccb> divisor;
    typedef inStack stack;
    typedef Accumulator<dividend:value/divisor::value> acca;
    typedef Accumulator<dividend::value%divisor::value> accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef acca accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,Register val> class and{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value&inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value&inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,int val> class and{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value&val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value&val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,Register val> class or{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value|inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value|inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,int val> class or{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value|val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value|val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,Register val> class xor{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<val==a,inAcca,inAccb> inAcc;
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value^inAcc::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value^inAcc::value>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<Register r,int val> class and{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value^val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value^val>,inAccb>::type accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};


template<Register r> class not{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef std::conditional<r==a,Accumulator<~inAcca::value>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<~inAccb::value>,inAccb>::type accb;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};


template<Register r> class push{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef std::conditional<r==a,inAcca,inAccb>::type inAcc;
    typedef inStack::push<inAcc::value>::next stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef inFlags flags;
  };
};

template<Register r> class pop{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack::pop popped;
    typedef popped::next stack;
    typedef std::conditional<r==a,Accumulator<inAcca::value-val>,inAcca>::type acca;
    typedef std::conditional<r==b,Accumulator<inAccb::value-val>,inAccb>::type accb;
    typedef std::conditional<r==a,acca,accb>::type accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

class nop{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef inFlags flags;
  };
};

class clz{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<false,inFlags::negative> flags;
  };
};

class cln{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<inFlags::zero,false> flags;
  };
};

template<short offset> class brz{
 template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef std::conditional<inFlags::zero,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brnz{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef std::conditional<!inFlags::zero,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brn{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef std::conditional<inFlags::negative,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brp{
  template<class inStack,class inAcca,class inAccb,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcca acca;
    typedef inAccb accb;
    typedef std::conditional<!inFlags::negative,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

#endif
