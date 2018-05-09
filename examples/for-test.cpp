#include <asm/Program.hpp>

#include <iostream>

using std::cout;
using std::endl;

#define TARGET 8

typedef Program<
 load<a,1>,
 load<b,1>,
 push<b>,
 pop<b>,
 mul<a,b>,
 add<b,1>,
 push<b>,
 sub<b,TARGET>,
 ifn<-6>
> output;

int main(){
  cout << TARGET<<"! = "<<output::acca<<endl;
};
