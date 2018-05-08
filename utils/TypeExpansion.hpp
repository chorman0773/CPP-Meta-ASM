#ifndef __TypeExpansion_hpp_2018_05_08_16_15
#define __TypeExpansion_hpp_2018_05_08_16_15

template<typename T,T val> struct extend{
	const static constexpr int value = val;
};

#endif
