#ifndef __Registers_hpp_2018_05_08_16_31
#define __Registers_hpp_2018_05_08_16_31

template<int val> struct register{
	const static constexpr int value = val;
};

template<int val> struct accumulator : register<val>{};

#endif
