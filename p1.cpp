#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;
typedef unsigned int uint;

/**
 * Main driver to test Matrix.cpp class. Creates matrices and performs operations
 * on these matrices.
 */
int main() {

    Matrix m(3, 3); // Matrix m
    m.at(0,0) = 9.0; // initializes values
    m.at(0,1) = 3.0;
    m.at(0,2) = 7.0;
    m.at(1,0) = 1.0;
    m.at(1,1) = 5.0;
    m.at(1,2) = 3.0;
    m.at(2,0) = 2.0;
    m.at(2,1) = 0.0;
    m.at(2,2) = 2.0;

    Matrix n(3, 3); // Matrix n
    n.at(0,0) = 3.0; // initializes values
    n.at(0,1) = 4.0;
    n.at(0,2) = 5.0;
    n.at(1,0) = 1.0;
    n.at(1,1) = 6.0;
    n.at(1,2) = 0.0;
    n.at(2,0) = 1.0;
    n.at(2,1) = 8.0;
    n.at(2,2) = 1.0;

    cout << "Matrix 1:" << endl;
    m.printMatrix(m); // print m
    cout << "Matrix 2:" << endl;
    n.printMatrix(n); // print n

    cout << "Matrix 1 + '2.5'" << endl;
    Matrix o(m.add(2.5)); // add m + 2.5
    o.printMatrix(o); // print
    cout << "Matrix 2 - '4'" << endl;
    Matrix p(n.subtract(4)); // subtract n - 4
    p.printMatrix(p); // print
    cout << "Matrix 1 * '2'" << endl;
    Matrix q(m.multiply(2)); // multiply m * 2
    q.printMatrix(q); // print
    cout << "Matrix 2 / '3'" << endl;
    Matrix r(n.divide(3)); // divides n / 3
    r.printMatrix(r); // print
    cout << "Matrix 1 Transposed" << endl;
    Matrix s(m.t()); // transpose
    s.printMatrix(s); // print
    cout << "Matrix 1 + Matrix 2" << endl;
    Matrix t(m.add(n)); // add m + n
    t.printMatrix(t); // print
    cout << "Matrix 1 - Matrix 2" << endl;
    Matrix u(m.subtract(n)); // subtract m - n
    u.printMatrix(u); // print
    cout << "Matrix 1 * Matrix 2" << endl;
    Matrix v(m.multiply(n)); // m * n
    v.printMatrix(v); // print
    cout << "Number of rows in Matrix 1: " << m.numRows() << endl; // print rows
    cout << "Number of columns in Matrix 2: " << n.numCols() << endl; // print columns
    cout << "Value of (1,2) in Matrix 1: " << m.at(1,2) << endl; // value at m(1,2)
    cout << "Value of (2,2) in Matrix 2: " << n.at(2,2) << endl; // value at n(2,2)

} // main
