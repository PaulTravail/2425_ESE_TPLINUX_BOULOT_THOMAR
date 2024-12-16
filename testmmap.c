#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(){
    
    uint32_t * p;
    int fd = open("/dev/mem", O_RDWR); // ouvrir la mémoire
    p = (uint32_t *) mmap(NULL, 4, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0xFF203000);
    *p = (1<<8);
    return 0;
}