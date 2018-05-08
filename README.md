# CPP-Meta-ASM

This program is designed to add a Meta-Assembly language to C++ using templates.
The language is an incomplete, Stack-based language with basic math operations and a single accumulator.
The language does not contain working memory (outside of the stack and 1 accumulator), or branch instructions.
	
An example program: Adds 3, 5, and 7, then devides by 11, then multiplies the remainder by 31. The result is 
transfered to the main program.

	typedef Program<
	load<3>,
	add<5>,
	add<7>,
	div<11>,
	pop,
	multiply<31>> output;
	
	constexpr int result = output::accumulator::value;

Copyright (C) 2018 Connor Horman
