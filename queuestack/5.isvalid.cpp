#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
  int lnum = 0;
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    switch (s[i]) {
    case '(':
      ++lnum;
      break;
    case ')':
      --lnum;
      break;
    default:
      return false;
    }
    if (lnum >= 0)
      continue;
    ;
    return false;
  }
  return lnum == 0;
}
