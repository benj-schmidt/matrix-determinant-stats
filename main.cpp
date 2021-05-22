#include "matrix.h"
#include "random.h"
#include "vector.h"
#include <assert.h>
#include <cmath>
#include <ctime>
#include <iostream>

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  Matrix first{randomIntModulo(10), randomIntModulo(10), randomIntModulo(10),
               randomIntModulo(10), randomIntModulo(10), randomIntModulo(10),
               randomIntModulo(10), randomIntModulo(10), randomIntModulo(10)};
  first.print();

  printf("Determinant: %d\n", first.determinant());

  Matrix second{randomIntModulo(10), randomIntModulo(10), randomIntModulo(10),
                randomIntModulo(10), randomIntModulo(10), randomIntModulo(10),
                randomIntModulo(10), randomIntModulo(10), randomIntModulo(10)};
  second.print();

  printf("Determinant: %d\n", second.determinant());

  std::cout << '\n';

  int trials{100};

  int detTotal{0};
  int detSqTotal{0};

  for (int i = 0; i < trials; ++i) {
    Matrix random{first | second};
    random.print();
    std::cout << '\n';
    int det = random.determinant();
    detTotal += det;
    detSqTotal += det * det;
  }

  double detAverage{static_cast<double>(detTotal) / trials};
  double detSqAverage{static_cast<double>(detSqTotal) / trials};
  double detVar{detSqAverage - detAverage * detAverage};

  assert(detVar >= 0 &&
         "Variance should be non-negative."); // possible floating point
                                              // comparison problem

  std::cout << "Average: " << detAverage << '\n';
  std::cout << "Variance: " << detVar << '\n';
  std::cout << "Standard deviation: " << std::sqrt(detVar) << '\n';
}
