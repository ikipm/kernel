#include "operation.h"
#include <screen.h>
#include <commands.h>
#include <functions.h>

int operation_command(char *args[]){
  double result = str_to_int(args[1]), part = 0;
  char op = ' ';
  for(int i = 2; args[i]; i++){
    if(is_number(args[i])){
      if(op != ' '){
        if(op == '+') result += str_to_int(args[i]);
        else if(op == '-') result -= str_to_int(args[i]);
        else if(op == '*') result *= str_to_int(args[i]);
        else if(op == '/') result /= str_to_int(args[i]);
        op = ' ';
      } else return 1;
    } else if(op != ' ') return 1;
    else {
      op = *args[i];
    }
  }
  print_char('\n');
  print_int(result);
  return 0;
}

__attribute__((section("commands")))
struct command operation_cmd = {"operation", operation_command};

