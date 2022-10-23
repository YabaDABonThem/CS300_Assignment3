#ifndef MYRAND_H_
#define MYRAND_H_

unsigned long int rand_next = 1;

int my_rand()
{
    rand_next = rand_next * 1103515245 + 12345;
    return ((unsigned int)(rand_next / 65536) % 32768);
}

void my_srand(unsigned int seed) { rand_next = seed; }

#endif