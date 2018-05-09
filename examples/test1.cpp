#include <asm/Program.hpp>
#include <asm/Instructions.hpp>
#include <iostream>

using std::cout;
using std::endl;

typedef Program<
load<1>,
push,
mul<2>,
brnz<-2>
> output;

int main(){
  for(int i = 0;i<sizeof(output::stack::array);i++)
    cout << output::stack::array[i] << endl;
    
  return EXIT_SUCCESS;
}
