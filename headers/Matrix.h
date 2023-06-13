/**
 * @file Matrix.h
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 08/04/2023
*/

#ifndef MATRIX
#define MATRIX

#define ERROR_ARGUMENTS_OUT_OF_RANGE 4
#define ERROR_DIVISION_0 5
#define ERROR_INCOMPATIBLE_DIMENSIONS 6
#define ERROR_INCOMPATIBLE_MULTIPLICATION_DIMENSIONS 7

template <class MatrixType> class CMatrix {
	// Attributes :
private:
	unsigned int NBRows;
	unsigned int NBColumns;
	const char* cMatrixType;
	MatrixType** Matrix;

public:

	/**
	* @fn CMatrix<MatrixType>()
	* @brief Initialise object
	* @param -
	* @return -
	*/
	CMatrix<MatrixType>();

	/**
	* @fn CMatrix<MatrixType>()
	* @brief Initalise object's attributes
	* @param NBRows : number of rows
	* @param NBColumns : number of columns
	* @param cMatrixType : matrix type
	* @return -
	*/
	CMatrix<MatrixType>(unsigned int NBRows, unsigned int NBColumns, const char* MatrixType);

	/**
	* @fn CMatrix<MatrixType>()
	* @brief Copy contsructor to initialise object
	* @param MATParam : CMatrix object
	* @return -
	*/
	CMatrix<MatrixType>(CMatrix<MatrixType>& MATParam);

	/**
	* @fn ~CMatrix<MatrixType>()
	* @brief Destroy object
	* @param -
	* @return -
	*/
	~CMatrix<MatrixType>();

	/**
	* @fn getNBRows()
	* @brief Get number of rows
	* @param -
	* @return number of rows
	*/
	unsigned int getNBRows() const;

	/**
	* @fn getNBColumns()
	* @brief Get number of columns
	* @param -
	* @return number of columns
	*/
	unsigned int getNBColumns() const;

	/**
	* @fn getMatrixType()
	* @brief Get matrix type
	* @param -
	* @return matrix type
	*/
	const char* getMatrixType() const;

	/**
	* @fn operator()()
	* @brief Read a matrix element Matrix(i)(j)
	* @param RowNumber : the row number
	* @param ColumnNumber : the column number
	* @return Matrix(i)(j)
	*/
	MatrixType& operator()(unsigned int RowNumber, unsigned int ColumnNumber);

	/**
	* @fn DisplayMatrix()
	* @brief Display matrix
	* @param -
	* @return -
	*/
	void DisplayMatrix();

	/**
	* @fn operator=()
	* @brief Surchage of = operator
	* @param MATParam : CMatrix object
	* @return Matrix object
	*/
	CMatrix<MatrixType>& operator=(const CMatrix<MatrixType>& MATParam);


	/**
	* @fn operator/()
	* @brief Surcharge of / operator (division)
	* @param variable : a variable
	* @return CMatrix object
	*/
	CMatrix<MatrixType> operator/(const double variable);

	/**
	* @fn operator+()
	* @brief Surcharge of + operator
	* @param MATparam : CMatrix object
	* @return CMatrix object
	*/
	CMatrix<MatrixType> operator+(CMatrix<MatrixType>& MATparam);

	/**
	* @fn operator-()
	* @brief Surcharge of - operator
	* @param MATparam : CMatrix object
	* @return CMatrix object
	*/
	CMatrix<MatrixType> operator-(CMatrix<MatrixType>& MATparam);

	/**
	* @fn operator*()
	* @brief Surcharge of * operator
	* @param MATparam : CMatrix object
	* @return CMatrix object
	*/
	CMatrix<MatrixType> operator*(CMatrix<MatrixType>& MATparam);

	/**
	* @fn MatrixTranspose()
	* @brief Matrix Transpose
	* @param -
	* @return CMatrix object
	*/
	CMatrix<MatrixType> MatrixTranspose();
};

/**
* @fn operator*()
* @brief Surcharge of * operator (multiplication of type (variable * Matrix))
* @param variable : a variable
* @param MATparam : CMatrix object
* @return Matrix object
*/
template <class MatrixType> CMatrix<MatrixType> operator*(const double variable, CMatrix<MatrixType>& MATparam);

/**
* @fn operator*()
* @brief Surcharge of * operator (multiplication of type (Matrix * variable))
* @param MATparam : CMatrix object
* @param variable : a variable
* @return CMatrix object
*/
template <class MatrixType> CMatrix<MatrixType> operator*(CMatrix<MatrixType>& MATparam, const double variable);

#include "Matrix.cpp"

#endif