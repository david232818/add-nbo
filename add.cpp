#include <stdint.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include "add.h"

uint32_t add(uint32_t n1, uint32_t n2, bool isbe)
{
  if (isbe) {
    n1 = ntohl(n1);
    n2 = ntohl(n2);
  }
  return (n1 + n2);
}
