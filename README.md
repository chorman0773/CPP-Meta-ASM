# CPP-Meta-ASM

This program is designed to add a Meta-Assembly language to C++ using templates.
The language is an incomplete, Stack-based language with basic math operations and a single accumulator.
The language does not contain working memory (outside of the stack and 1 accumulator). The language now has branch support,
and support for processor flags and an instruction pointer. 

In addition, the language is template based, so its easy enough to add new instructions.
You can add an instruction by defining a class with a single member template struct named execute with the parameters
<class inStack,class inAcca,class inAccb,class inIp,class inFlags>, which provides output member typedefs stack, acca, accb, 
ip, and flags.
If the instruction modifies one of these, it should be updated accordingly. Otherwise the output should echo the input.
	
An example program: Adds 3, 5, and 7, then devides by 11, then multiplies the remainder by 31 and adds to the
quotient. The result is transfered to the main program.

	typedef Program<
	load<a,3>,
	add<a,5>,
	add<a,7>,
	div<a,11>,
	pop<b>,
	multiply<b,31>,
	add<a,b>> output;
	
	constexpr int result = output::accumulator::value;

Copyright (C) 2018 Connor Horman


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
