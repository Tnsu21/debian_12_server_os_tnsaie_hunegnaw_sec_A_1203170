#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
int main() {
// Allocate a memory region using mmap
size_t length = getpagesize(); // Length = one page of memory
void *addr = mmap(NULL, length, PROT_READ | PROT_WRITE,
MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
if (addr == MAP_FAILED) {
perror("mmap");
return 1;
}
printf("Memory mapped at address %p\n", addr);
// Now unmap the memory
if (munmap(addr, length) == -1) {
perror("munmap");
return 1;
}
printf("Memory unmapped successfully\n");
return 0;
}
