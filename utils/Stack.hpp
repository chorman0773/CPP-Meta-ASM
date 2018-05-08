#ifndef __Stack_hpp_2018_05_07_15_29
#define __Stack_hpp_2018_05_07_15_29


template<int top,int... rest> struct stack{
	template<int val> struct push{
		typedef stack<val,top,rest> nextStack;
	};
	struct pop{
		static const constexpr int value = top;
		typedef stack<rest> nextStack;
	};
};

#endif
