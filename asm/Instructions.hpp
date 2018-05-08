#ifndef __Instructions_hpp_2018_05_08_16_56
#define __Instructions_hpp_2018_05_08_16_56

#include <type_traits>

template<int val> class load{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef Accumulator<val> accumulator;
    typedef inIp ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<int val> class add{
  template<class inStack,class inAcc,class inIp,class inFlags> execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value+val> accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<class inStack,class inAcc,class inIp,class inFlags> class sub{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value+val> accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<class inStack,class inAcc,class inIp,class inFlags> class mul{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value+val> accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

template<class inStack,class inAcc,class inIp,class inFlags> class div{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value+val> accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

class push{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack::push<inAcc::value>::next stack;
    typedef inAcc accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef inFlags flags;
  };
};

class pop{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack::pop popped;
    typedef popped::next stack;
    typedef Accumulator<popped::value> accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<accumulator::value==0,accumulator::value<0> flags;
  };
};

class nop{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inAcc accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef inFlags flags;
  };
};

class clz{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<false,inFlags::negative> flags;
  };
};

class cln{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef InstructionPointer<inIp::value+1> ip;
    typedef Flags<inFlags::zero,false> flags;
  };
};

template<short offset> class brz{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef std::conditional<inFlags::zero,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brnz{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef std::conditional<!inFlags::zero,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brn{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef std::conditional<inFlags::negative,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

template<short offset> class brp{
  template<class inStack,class inAcc,class inIp,class inFlags> struct execute{
    typedef inStack stack;
    typedef inZ accumulator;
    typedef std::conditional<!inFlags::negative,InstructionPointer<inIp::value+offset>,InstructionPointer<inIp::value+1>>::type ip;
    typedef inFlags flags;
  };
};

#endif
