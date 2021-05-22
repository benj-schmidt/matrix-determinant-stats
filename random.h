#ifndef RANDOM_H
#define RANDOM_H

#include <cstdio>
#include <ctime>
#include <iostream>

int randomIntModulo(int modulus) {
  return std::rand() % modulus; // potentially overweights values closer to 0
}

#endif /* RANDOM_H */
