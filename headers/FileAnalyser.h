/**
 * @file FileAnalyser.h
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 07/04/2023
*/

#ifndef FILE_ANALYSER
#define FILE_ANALYSER


#include <iostream>
#include <fstream>
#include "Exception.h"
#include "Matrix.h"

#define ERROR_OPENING_FILE 1
#define ERROR_NOT_NUMBER 2
#define ERROR_UNKNOWN_TYPE 3

class FileAnalyser {
	// Attributes :
private:
	char* FileBuffer;// To read file content
	unsigned int FileLength;// The length of file's content
public:

	/**
	* @fn FileAnalyser()
	* @brief Initalise object
	* @param -
	* @return -
	*/
	FileAnalyser();

	/**
	* @fn ~FileAnalyser()
	* @brief Destroy object
	* @param -
	* @return -
	*/
	~FileAnalyser();

	/**
	* @fn getFileBuffer()
	* @brief Get FileBuffer attribute
	* @param -
	* @return FileBuffer
	*/
	char* getFileBuffer();

	/**
	* @fn readFile()
	* @brief Read a file and fill FileBuffer
	* @param filename : file's name
	* @return -
	*/
	void readFile(const char* filename);

	/**
	* @fn getFileLength()
	* @brief Calcul and get the length of file's content
	* @param filename : file's name
	* @return FileLength
	*/
	unsigned int getFileLength(const char* filename);

	/**
	* @fn emptyFileBuffer()
	* @brief Empty FileBuffer
	* @param -
	* @return -
	*/
	void emptyFileBuffer();

	/**
	* @fn analyseFile()
	* @brief Analyse file content and create matrix 
	* @param filename : file's name
	* @return -
	*/
	CMatrix<double>& analyseFile(const char* filename);
};

#endif