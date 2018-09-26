#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  FILE *fp = NULL;
  int linenum = 0;
  char c;

  fp = fopen(argv[1], "r");
  assert(NULL != fp);

  for (c = fgetc(fp); c != EOF; c = fgetc(fp)) {
    if ('\n' == c) linenum++;
  }

  fclose(fp);
  printf("File line number: %d\n", linenum);

  return 0;
}
