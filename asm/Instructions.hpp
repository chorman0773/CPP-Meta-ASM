#ifndef __Instructions_hpp_2018_05_08_16_56
#define __Instructions_hpp_2018_05_08_16_56

template<int val> class load{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<val> accumulator;
  };
};

template<int val> class add{
  template<class inStack,class inAcc> execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value+val> accumulator;
  };
};

template<int val> class sub{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value-val> accumulator;
  };
};

template<int val> class mul{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef Accumulator<inAcc::value*val> accumulator;
  };
};

template<int val> class div{
  template<class inStack,class inAcc> struct execute{
    typedef inStack::push<inAcc::value%val>::next stack;
    typedef Accumulator<inAcc::value/val> accumulator;
  };
};

class push{
  template<class inStack,class inAcc> struct execute{
    typedef inStack::push<inAcc::value>::next stack;
    typedef inAcc accumulator;
  };
};

class pop{
  template<class inStack,class inAcc> struct execute{
    typedef inStack::pop popped;
    typedef pop::next stack;
    typedef Accumulator<popped::value> accumulator;
  };
};

class nop{
  template<class inStack,class inAcc> struct execute{
    typedef inStack stack;
    typedef inAcc accumulator;
  };
};

#endif
