/**
 * @file Exception.cpp
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 07/04/2023
*/

#include  <iostream>
#include "../headers/Exception.h"

using namespace std;

/**
* @fn Exception()
* @brief Initialise object
* @param -
* @return -
*/
Exception::Exception() {
	EXCErrorNumber = 0;
}

/**
* @fn Exception()
* @brief Initialise EXCErrorNumber
* @param ErrorNumber : Error number
* @return -
*/
Exception::Exception(unsigned int ErrorNumber) {
	EXCSetErrorNumber(ErrorNumber);
}

/**
* @fn EXCGetErrorNumber()
* @brief Get Exception error number
* @param -
* @return Exception error number
*/
unsigned int Exception::EXCGetErrorNumber() {
	return EXCErrorNumber;
}


/**
* @fn EXCSetErrorNumber()
* @brief Set Error Number
* @param ErrorNumber : Error number
* @return -
*/
void Exception::EXCSetErrorNumber(unsigned int ErrorNumber) {
	EXCErrorNumber = ErrorNumber;
}


/**
* @fn EXCDisplayMessage()
* @brief Display error message
* @param -
* @return -
*/
void Exception::EXCDisplayMessage() {
	if (EXCErrorNumber == 1) {
		cerr << "*** ERROR : couldn't open file. Please verify file path and file name" << endl;
	}
	
	else if (EXCErrorNumber == 2) {
		cerr << "*** ERROR : all values in the file must be numbers" << endl;
	}

	else if (EXCErrorNumber == 3) {
		cerr << "*** ERROR : matrix type must be either double, float or int!" << endl;
	}

	else if (EXCErrorNumber == 4) {
		cerr << "*** ERROR : arguments you provided are out of matrix range!" << endl;
	}

	else if (EXCErrorNumber == 5) {
		cerr << "*** ERROR : can't divide a matrix by 0" << endl;
	}

	else if (EXCErrorNumber == 6) {
		cerr << "*** ERROR : matrix dimensions are incompatible for - and + operations!" << endl;
	}

	else if (EXCErrorNumber == 7) {
		cerr << "*** ERROR : matrix dimensions are incompatible for multiplication operation!" << endl;
	}
}
