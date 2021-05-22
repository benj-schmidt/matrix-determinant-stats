#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
  int data[3];
  int &x{data[0]};
  int &y{data[1]};
  int &z{data[2]};

public:
  Vector(int x, int y, int z) : data{x, y, z} {};

  int getElt(int index) const { return data[index]; };
  void print() const {
    for (int i{0}; i < 3; ++i) {
      printf("%6d", data[i]);
    }
    std::cout << '\n';
  }
};

int operator*(const Vector &x, const Vector &y) {
  return (x.getElt(0) * y.getElt(0) + x.getElt(1) * y.getElt(1) +
          x.getElt(2) * y.getElt(2));
}

#endif /* VECTOR_H */
