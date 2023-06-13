/**
 * @file Matrix.cpp
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 08/04/2023
*/

#ifndef MATRIX_DEF
#define MATRIX_DEF

#include <iostream>
#include "Exception.h"
#include "Matrix.h"

using namespace std;

/**
* @fn CMatrix<MatrixType>()
* @brief Initialise object
* @param -
* @return -
*/
template <class MatrixType> CMatrix<MatrixType>::CMatrix() {
	NBRows = 0;
	NBColumns = 0;
	cMatrixType = NULL;
	Matrix = NULL;
}

/**
* @fn CMatrix<MatrixType>()
* @brief Initalise object's attributes
* @param NBRows : number of rows
* @param NBColumns : number of columns
* @param cMatrixType : matrix type
* @return -
*/
template <class MatrixType> CMatrix<MatrixType>::CMatrix(unsigned int NBRows, unsigned int NBColumns, const char* cMatrixType) {
	this->NBRows = NBRows;
	this->NBColumns = NBColumns;
	this->cMatrixType = cMatrixType;

	int i;

    // Allocate memory :
	Matrix = new MatrixType * [NBRows];
	for (i = 0; i < NBRows; i++) {
		Matrix[i] = new MatrixType[NBColumns]; // Allocation des colonnes
	}

	// Initialisation : 
	for (i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			Matrix[i][j] = 0;
		}
	}
}

/**
* @fn CMatrix<MatrixType>()
* @brief Copy contsructor to initialise object
* @param MATParam : CMatrix object
* @return -
*/
template <class MatrixType> CMatrix<MatrixType>::CMatrix(CMatrix<MatrixType>& MATParam) {

	NBRows = MATParam.NBRows;
	NBColumns = MATParam.NBColumns;
	cMatrixType = MATParam.cMatrixType;

	int i;

	// Allocate memory :
	Matrix = new MatrixType * [NBRows];
	for (i = 0; i < NBRows; i++) {
		Matrix[i] = new MatrixType[NBColumns];
	}

	// Copy matrix variables : 
	for (i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			Matrix[i][j] = MATParam.Matrix[i][j];
		}
	}

}

/**
* @fn ~CMatrix<MatrixType>()
* @brief Destroy object
* @param -
* @return -
*/
template <class MatrixType> CMatrix<MatrixType>::~CMatrix() {
	for (int i = 0; i < NBRows; i++) {
		delete(Matrix[i]);
	}

	delete(Matrix);
}

/**
* @fn getNBRows()
* @brief Get number of rows
* @param -
* @return number of rows
*/
template <class MatrixType> unsigned int CMatrix<MatrixType>::getNBRows() const {
	return NBRows;
}

/**
* @fn getNBColumns()
* @brief Get number of columns
* @param -
* @return number of columns
*/
template <class MatrixType> unsigned int CMatrix<MatrixType>::getNBColumns() const {
	return NBColumns;
}

/**
* @fn getMatrixType()
* @brief Get matrix type
* @param -
* @return matrix type
*/
template <class MatrixType> const char* CMatrix<MatrixType>::getMatrixType() const {
	return cMatrixType;
}


/**
* @fn operator()()
* @brief Read a matrix element Matrix(i)(j)
* @param RowNumber : the row number
* @param ColumnNumber : the column number
* @return Matrix(i)(j)
*/
template <class MatrixType> MatrixType& CMatrix<MatrixType> :: operator()(unsigned int RowNumber, unsigned int ColumnNumber) {
	if (RowNumber >= NBRows || ColumnNumber >= NBColumns) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_ARGUMENTS_OUT_OF_RANGE);
		throw(EXCObject);
	}

	return Matrix[RowNumber][ColumnNumber];
}

/**
* @fn DisplayMatrix()
* @brief Display matrix
* @param -
* @return -
*/
template <class MatrixType> void CMatrix<MatrixType>::DisplayMatrix() {
	// Display for Matrix type :
	if (cMatrixType == "double" || cMatrixType == "float") {
		for (int i = 0; i < NBRows; i++) {
			for (int j = 0; j < NBColumns; j++) {
				cout << "\t" << Matrix[i][j];
			}
			cout << endl;
		}
	}

	else if (cMatrixType == "int") {
		for (int i = 0; i < NBRows; i++) {
			for (int j = 0; j < NBColumns; j++) {
				cout << "\t" << (int) Matrix[i][j];
			}
			cout << endl;
		}
	}

}

/**
* @fn operator=()
* @brief Surchage of = operator
* @param MATParam : CMatrix object
* @return Matrix object
*/
template <class MatrixType> CMatrix<MatrixType>& CMatrix<MatrixType>::operator=(const CMatrix<MatrixType>& MATparam) {
	// If the two matrixs are the same :
	if (this == &MATparam) {
		return *this;
	}

	int i;

	// If the two matrixs don't have the same dimensions : 
	if (NBColumns != MATparam.NBColumns || NBRows != MATparam.NBRows) {
		
		// We desallocate matrix :
		for (i = 0; i < NBRows; i++) {
			delete(Matrix[i]);
		}
		delete(Matrix);

		// Reallocate using the new dimensions :
		NBRows = MATparam.NBRows;
		NBColumns = MATparam.NBColumns;
		cMatrixType = MATparam.cMatrixType;
		
		Matrix = new MatrixType * [NBRows];
		for (i = 0; i < NBRows; i++) {
			Matrix[i] = new MatrixType[NBColumns];
		}

	}

	// Copy matrix variables :
	for (i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			Matrix[i][j] = MATparam.Matrix[i][j];
		}
	}

	return *this;
}

/**
* @fn operator/()
* @brief Surcharge of / operator (division)
* @param variable : a variable
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> CMatrix<MatrixType>::operator/(const double variable) {
	// If variable is 0, we throw exception :
	if (variable == 0) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_DIVISION_0);
		throw(EXCObject);
	}

	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(NBRows, NBColumns, cMatrixType);

	for (int i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			OperationResult(i, j) = (*this)(i, j) / variable;
		}
	}

	return OperationResult;
}

/**
* @fn operator+()
* @brief Surcharge of + operator
* @param MATparam : CMatrix object
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> CMatrix<MatrixType>::operator+(CMatrix<MatrixType>& MATparam) {
	// If the two matrixs have different dimensions :
	if (NBRows != MATparam.NBRows || NBColumns != MATparam.NBColumns) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_INCOMPATIBLE_DIMENSIONS);
		throw(EXCObject);
	}

	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(MATparam);

	for (int i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			OperationResult(i, j) = (*this)(i, j) + MATparam(i, j);
		}
	}

	return OperationResult;
}

/**
* @fn operator-()
* @brief Surcharge of - operator
* @param MATparam : CMatrix object
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> CMatrix<MatrixType> :: operator-(CMatrix<MatrixType>& MATparam) {
	// If the two matrixs have different dimensions :
	if (NBRows != MATparam.NBRows || NBColumns != MATparam.NBColumns) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_INCOMPATIBLE_DIMENSIONS);
		throw(EXCObject);
	}

	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(MATparam);

	for (int i = 0; i < NBRows; i++) {
		for (int j = 0; j < NBColumns; j++) {
			OperationResult(i, j) = (*this)(i, j) - MATparam(i, j);
		}
	}

	return OperationResult;
}

/**
* @fn operator*()
* @brief Surcharge of * operator
* @param MATparam : CMatrix object
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> CMatrix<MatrixType> :: operator*(CMatrix<MatrixType>& MATparam) {
	if (NBColumns != MATparam.NBRows) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_INCOMPATIBLE_MULTIPLICATION_DIMENSIONS);
		throw(EXCObject);
	}

	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(NBRows, MATparam.NBColumns, MATparam.cMatrixType);

	for (int i = 0; i < NBRows; i++) {
		for (int j = 0; j < MATparam.NBColumns; j++) {
			for (int k = 0; k < NBColumns; k++) {
				OperationResult(i, j) += (*this)(i, k) * MATparam(k, j);
			}
		}
	}

	return OperationResult;
}

/**
* @fn MatrixTranspose()
* @brief Matrix Transpose
* @param -
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> CMatrix<MatrixType>::MatrixTranspose() {
	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(NBRows, NBColumns, cMatrixType);

	for (int i = 0; i < OperationResult.NBRows; i++) {
		for (int j = 0; j < OperationResult.NBColumns; j++) {
			OperationResult(j, i) = (*this)(i, j);
		}
	}

	return OperationResult;
}

/**
* @fn operator*()
* @brief Surcharge of * operator (multiplication of type (variable * Matrix))
* @param variable : a variable
* @param MATparam : CMatrix object
* @return Matrix object
*/
template <class MatrixType> CMatrix<MatrixType> operator*(const double variable, CMatrix<MatrixType>& MATparam) {
	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(MATparam.getNBRows(), MATparam.getNBColumns(), MATparam.getMatrixType());

	for (int i = 0; i < OperationResult.getNBRows(); i++) {
		for (int j = 0; j < OperationResult.getNBColumns(); j++) {
			OperationResult(i, j) = variable * (MATparam)(i, j);
		}
	}

	return OperationResult;
}

/**
* @fn operator*()
* @brief Surcharge of * operator (multiplication of type (Matrix * variable))
* @param MATparam : CMatrix object
* @param variable : a variable
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> operator*(CMatrix<MatrixType>& MATparam, const double variable) {
	// Create a matrix to store result : 
	CMatrix<MatrixType> OperationResult(MATparam.getNBRows(), MATparam.getNBColumns(), MATparam.getMatrixType());

	for (int i = 0; i < OperationResult.getNBRows(); i++) {
		for (int j = 0; j < OperationResult.getNBColumns(); j++) {
			OperationResult(i, j) = (MATparam)(i, j) * variable;
		}
	}

	return OperationResult;
}

#endif