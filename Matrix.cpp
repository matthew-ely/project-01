#include <iostream>
#include <iomanip>
#include "Matrix.h"

typedef unsigned int uint;
using namespace std;

/**
 * Matrix constructor with size based on rows and cols values.
 *
 * @param uint rows  number of rows
 * @param uint cols  number of columns
 */
Matrix::Matrix(uint rows, uint cols) {
    mRows = rows; // sets number of rows
    mCols = cols; // sets number of columns
    mat = new double*[rows];
    for (uint i = 0; i < rows; i++) { // allocates space
        mat[i] = new double[cols];
    } // for
} // Matrix

/**
 * Matrix copy constructor with size and values based on Matrix m.
 *
 * @param Matrix m  Matrix object
 */
Matrix::Matrix(const Matrix & m) {
    mRows = m.mRows; // sets number of rows
    mCols = m.mCols; // sets number of columns
    mat = new double*[m.mRows];
    for (uint k = 0; k < m.mRows; k++) { // allocates space
        mat[k] =  new double[m.mCols];
    } // for
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) { // copies values to Matrix
            mat[i][j] = m.mat[i][j];
        } // for
    } // for
} // Matrix

/**
 * Matrix destructor that deletes Matrix.
 */
Matrix::~Matrix() {
    for (uint i = 0; i < mRows; i++) { // deletes Matrix
        delete [] mat[i];
    } // for
    delete [] mat;
} // Matrix

/**
 * Adds a double value to every value of the Matrix.
 *
 * @param double s  value added to Matrix values
 * @return Matrix ad  new Matrix with added values
 */
Matrix Matrix::add(double s) const {
    Matrix ad(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            ad.mat[i][j] = mat[i][j] + s; // adds double value
        } // for
    } // for
    return ad;
} // add

/**
 * Adds values from one Matrix to the other.
 *
 * @param Matrix m  Matrix of values to be added
 * @return Matrix ad  new Matrix with sum of values
 */
Matrix Matrix::add(const Matrix & m) const {
    Matrix ad(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            ad.mat[i][j] = mat[i][j] + m.mat[i][j]; // adds Matrix values
        } // for
    } // for
    return ad;
} // add

/**
 * Subtracts double value from every value of Matrix.
 *
 * @param double s  value to be subtracted
 * @return Matrix sub  new Matrix with value subtracted
 */
Matrix Matrix::subtract(double s) const {
    Matrix sub(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            sub.mat[i][j] = mat[i][j] - s; // subtracts double value
        } // for
    } // for
    return sub;
} // subtract

/**
 * Subtracts double values from one Matrix and another.
 *
 * @param Matrix m  Matrix to subtract values from
 * @return Matrix sub  new Matrix with subtracted values
 */
Matrix Matrix::subtract(const Matrix & m) const {
    Matrix sub(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            sub.mat[i][j] = mat[i][j] - m.mat[i][j]; //subtracts Matrix values
        } // for
    } // for
    return sub;
} // subtract

/**
 * Multiplies values of Matrix by a double value.
 *
 * @param double s  value to multiply Matrix by
 * @return Matrix mult  new Matrix with multiplied values
 */
Matrix Matrix::multiply(double s) const {
    Matrix mult(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            mult.mat[i][j] = mat[i][j] * s; // multiplies by double value
        } // for
    } // for
    return mult;
} // multiply

/**
 * Multiplies values of both Matrices and creates new Matrix.
 * The size of the new Matrix has the amount of rows of the first Matrix
 * and amount of columns of second Matrix. The amount of columns of the
 * first Matrix must equal the amount of rows of the second Matrix in order
 * to muliply. r1 x c1 * r2 x c2 -> r1 x c2, c1 = r2
 *
 * @param Matrix m  Matrix to be multiplied
 * @return Matrix mult  new Matrix with new size and values
 */
Matrix Matrix::multiply(const Matrix & m) const {
    Matrix mult(mRows, m.mCols); // new Matrix with new size
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < m.mCols; j++) {
            double mVal = 0;
            for (uint k = 0; k < mCols; k++) { // multiplies values together
                mVal += mat[i][k]*m.mat[k][j];
            } // for
            mult.mat[i][j] = mVal; // assigns to position in Matrix
        } // for
    } // for
    return mult;
} // multiply

/**
 * Divides values of the Matrix by a double value.
 *
 * @param double s  value for Matrix values to be divided by
 * @return Matrix div  new Matrix with values divided
 */
Matrix Matrix::divide(double s) const {
    Matrix div(mRows, mCols); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            div.mat[i][j] = mat[i][j] / s; // divides by double value
        } // for
    } // for
    return div;
} // divide

/**
 * Transposes the Matrix by switching the columns to become rows
 * and rows to become columns.
 *
 * @return Matrix tran  new transposed Matrix
 */
Matrix Matrix::t() const {
    Matrix tran(mCols, mRows); // new Matrix
    for (uint i = 0; i < mRows; i++) {
        for (uint j = 0; j < mCols; j++) {
            tran.mat[j][i] = mat[i][j]; // transposes Matrix values
        } // for
    } // for
    return tran;
} // t

/**
 * Returns number of rows in Matrix.
 *
 * @return mRows  uint value of number of rows
 */
const uint Matrix::numRows() const {
    return mRows; // returns rows
} // numRows

/**
 * Returns number of columns in Matrix.
 *
 * @return mCols  uint value of number of columns
 */
const uint Matrix::numCols() const {
    return mCols; // return columns
} // numCols

/**
 * Returns value at specified poition in Matrix.
 *
 * @param uint row  row value
 * @param uint col  column value
 * @return double value at specified position
 */
double & Matrix::at(uint row, uint col) {
    return mat[row][col]; // value at position
} // at

/**
 * Returns constant value at specified poition in Matrix.
 *
 * @param uint row  row value
 * @param uint col  column value
 * @return double value at specified position
 */
const double & Matrix::at(uint row, uint col) const {
    return mat[row][col]; // constant value at position
} // at

/**
 * Prints values in Matrix with brackets and in comma separated list.
 *
 * @param Matrix m  Matrix to be printed
 */
void Matrix::printMatrix(const Matrix & m) {
    for (uint i = 0; i < m.mRows; i++) {
        cout << "[ ";
        for (uint j = 0; j < m.mCols - 1; j++) { // prints values  // [x1, x2, x3]
                                                                   // [x4, x5, x6]
            cout << setprecision(1) << fixed << m.at(i,j) << ", "; // [x7, x8, x9]
        } // for
        cout << m.at(i, m.mCols - 1) << " ]" << endl;
    } // for
    cout << "\n";
} // printMatrix
