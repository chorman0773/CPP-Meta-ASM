#ifndef __Registers_hpp_2018_05_08_16_31
#define __Registers_hpp_2018_05_08_16_31

template<int val> struct register{
	const static constexpr int value = val;
};

template<int val> struct Accumulator : register<val>{};

template<int val> struct InstructionPointer : register<val> {};

template<bool z,bool n> struct Status : register<(z?2:0)|(n?1:0)>{
	const static constexpr bool zero = z;
	const static constexpr bool negative = n;
};

#endif
