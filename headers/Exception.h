/**
 * @file Exception.h
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 07/04/2023
*/

#ifndef EXCEPTION
#define EXCEPTION

class Exception {
	// Attributes :
private:
	unsigned int EXCErrorNumber;
public:

	/**
	* @fn Exception()
	* @brief Initialise object
	* @param -
	* @return -
	*/
	Exception();

	/**
	* @fn Exception()
	* @brief Initialise EXCErrorNumber 
	* @param ErrorNumber : Error number
	* @return -
	*/
	Exception(unsigned int ErrorNumber);

	/**
	* @fn EXCGetErrorNumber()
	* @brief Get Exception error number
	* @param -
	* @return Exception error number
	*/
	unsigned int EXCGetErrorNumber();

	/**
	* @fn EXCSetErrorNumber()
	* @brief Set Error Number
	* @param ErrorNumber : Error number
	* @return -
	*/
	void EXCSetErrorNumber(unsigned int ErrorNumber);

	/**
	* @fn EXCDisplayMessage()
	* @brief Display error message
	* @param -
	* @return -
	*/
	void EXCDisplayMessage();
};

#endif