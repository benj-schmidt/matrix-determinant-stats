#ifndef MATRIX_H
#define MATRIX_H

#include "random.h"
#include "vector.h"

class Matrix {
  int data[3][3];
  int &a{data[0][0]};
  int &b{data[0][1]};
  int &c{data[0][2]};
  int &d{data[1][0]};
  int &e{data[1][1]};
  int &f{data[1][2]};
  int &g{data[2][0]};
  int &h{data[2][1]};
  int &i{data[2][2]};

public:
  Matrix(int a, int b, int c, int d, int e, int f, int g, int h, int i)
      : data{a, b, c, d, e, f, g, h, i} {};
  int getElt(int row, int col) const { return data[row][col]; };
  Vector getRow(int index) const {
    return {data[index][0], data[index][1], data[index][2]};
  };
  Vector getCol(int index) const {
    return {data[0][index], data[1][index], data[2][index]};
  };
  int determinant() const {
    return (a * e * i + b * f * g + c * d * h) -
           (a * f * h + b * d * i + c * e * g);
  };
  void print() const {
    for (int x{0}; x < 3; ++x) {
      for (int y{0}; y < 3; ++y) {
        printf("%6d", data[x][y]);
      }
      std::cout << '\n';
    }
  };
  void printDeterminant() const { printf("Determinant: %d\n", determinant()); };
};

Matrix operator*(const Matrix &x, const Matrix &y) {
  Vector row0{x.getRow(0)};
  Vector row1{x.getRow(1)};
  Vector row2{x.getRow(2)};
  Vector col0{y.getCol(0)};
  Vector col1{y.getCol(1)};
  Vector col2{y.getCol(2)};
  return {row0 * col0, row0 * col1, row0 * col2, row1 * col0, row1 * col1,
          row1 * col2, row2 * col0, row2 * col1, row2 * col2};
}

int oneOfTwo(int a, int b) { return (randomIntModulo(2) ? a : b); }

Matrix operator|(const Matrix &x, const Matrix &y) {
  int a{oneOfTwo(x.getElt(0, 0), y.getElt(0, 0))};
  int b{oneOfTwo(x.getElt(0, 1), y.getElt(0, 1))};
  int c{oneOfTwo(x.getElt(0, 2), y.getElt(0, 2))};
  int d{oneOfTwo(x.getElt(1, 0), y.getElt(1, 0))};
  int e{oneOfTwo(x.getElt(1, 1), y.getElt(1, 1))};
  int f{oneOfTwo(x.getElt(1, 2), y.getElt(1, 2))};
  int g{oneOfTwo(x.getElt(2, 0), y.getElt(2, 0))};
  int h{oneOfTwo(x.getElt(2, 1), y.getElt(2, 1))};
  int i{oneOfTwo(x.getElt(2, 2), y.getElt(2, 2))};
  return {a, b, c, d, e, f, g, h, i};
}

#endif /* MATRIX_H */
