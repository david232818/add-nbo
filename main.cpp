#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include "add.h"

int main(int argc, char *argv[])
{
  uint32_t n1, n2, sum;
  FILE *rfp1, *rfp2;
  
  if (argc != 3) {
    fputs("add-nbo <file1> <file2>\n", stderr);
    return -1;
  }

  if ((rfp1 = fopen(argv[1], "r")) == NULL)
    goto FILE_OPEN_ERR;

  if ((rfp2 = fopen(argv[2], "r")) == NULL)
    goto FILE_OPEN_ERR;

  if (fread(&n1, sizeof(n1), 1, rfp1) != 1)
    goto FILE_READ_ERR;
  
  if (fread(&n2, sizeof(n2), 1, rfp2) != 1)
    goto FILE_READ_ERR;

  sum = add(n1, n2, true);
  printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", ntohl(n1), ntohl(n1),
	 ntohl(n2), ntohl(n2), sum, sum);
  return 0;

 FILE_OPEN_ERR:
  perror("fopen(): ");
  return -1;

 FILE_READ_ERR:
  perror("fread(): ");
  return -1;
}
  
