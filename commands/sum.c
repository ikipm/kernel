#include "sum.h"
#include <screen.h>
#include <commands.h>

int sum_command(char *args[]){
  if(!is_number(args[1]) || !is_number(args[2])) return 1;
  int n1 = str_to_int(args[1]), n2 = str_to_int(args[2]);
  print_char('\n');
  print_int(n1+n2);
  return 0;
}

__attribute__((section("commands")))
struct command sum_cmd = {"sum", sum_command};
