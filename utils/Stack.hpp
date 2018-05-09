#ifndef __Stack_hpp_2018_05_07_15_29
#define __Stack_hpp_2018_05_07_15_29
namespace _hidden{
	template<class target,int first,int... rest> struct pop{
		static const constexpr int val = first;
		typedef typename target<rest> next;
	};

	template<int val,class target,int... rest> struct push{
		typedef typename target<val,first,rest> next; 
	};
};


template<int... stackVals> struct stack{
	template<int val> struct push: _hidden::push<val,stack,stackVals>{};
	struct pop: _hidden::pop<stack,stackVals>{};
	
	const static constexpr int array[sizeof...(stackVals)] = {stackVals};
};
template<> struct stack<>{
	template<int val> struct push: _hidden::push<val,stack>{};
	const static constexpr int array[];
};

#endif
