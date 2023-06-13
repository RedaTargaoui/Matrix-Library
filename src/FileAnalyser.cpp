/**
 * @file FileAnalyser.cpp
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 07/04/2023
*/

#include "FileAnalyser.h"

using namespace std;

/**
* @fn FileAnalyser()
* @brief Initalise object
* @param -
* @return -
*/
FileAnalyser::FileAnalyser() {
	FileBuffer = NULL;
	FileLength = 0;
}

/**
* @fn ~FileAnalyser()
* @brief Destroy object
* @param -
* @return -
*/
FileAnalyser ::~FileAnalyser() {
	delete[] FileBuffer;
}

/**
* @fn getFileBuffer()
* @brief Get FileBuffer attribute
* @param -
* @return FileBuffer
*/
char* FileAnalyser::getFileBuffer() {
	return FileBuffer;
}

/**
* @fn readFile()
* @brief Read a file and fill FileBuffer
* @param filename : file's name
* @return -
*/
void FileAnalyser::readFile(const char* filename) {
	// If filename is empty, we throw Exception :
	if (filename == NULL) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_OPENING_FILE);
		throw(EXCObject);
	}

	// Get file length and reinitialise FileBuffer :
	FileLength = getFileLength(filename);
	emptyFileBuffer();

	ifstream File(filename); // Open file

	// If file is open, we fill buffer :
	if (File.is_open()) {

		int index = 0;
		char c;

		while (File.get(c)) {
			FileBuffer[index] = c;
			index++;
		}

		FileBuffer[index] = '\0';

	}

	File.close();
}



/**
* @fn getFileLength()
* @brief Calcul and get the length of file's content
* @param filename : file's name
* @return FileLength
*/
unsigned int FileAnalyser::getFileLength(const char* filename) {
	ifstream File(filename); // Open file

	// If file openning has failed, we throw an Exception :
	if (!File.is_open()) {
		Exception EXCObject;
		EXCObject.EXCSetErrorNumber(ERROR_OPENING_FILE);
		throw(EXCObject);
	}

	unsigned int length = 0;
	char c;

	while (File.get(c)) {
		length++;
	}

	File.close();

	return length;
}

/**
* @fn emptyFileBuffer()
* @brief Empty FileBuffer
* @param -
* @return -
*/
void FileAnalyser::emptyFileBuffer() {
	// We empty buffer and we realocate it :
	delete[] FileBuffer;
	FileBuffer = new char[FileLength];
}

/**
* @fn analyseFile()
* @brief Analyse file content and create matrix
* @param filename : file's name
* @return -
*/
CMatrix<double>& FileAnalyser::analyseFile(const char* filename) {
	// Read file :
	readFile(filename);

	CMatrix<double>* Matrix = NULL;

	// If buffer is not empty :
	if (getFileBuffer() != NULL) {
		char* FileContent = getFileBuffer();

		// Use patterns to look for parameters :
		char MatrixTypePattern[] = "MatrixType=(.*)";
		char NbRowsPattern[] = "NBRows=(\\d+)";
		char NbColumnsPattern[] = "NBColumns=(\\d+)";
		char MatrixPattern[] = "Matrix\\s*=\\s*\\[((?:\\s*-?\\d+)+\\s*)+\\]";

		// -----------------------To get Matrice type------------------------------------- :
		const char* MatrixTypePos;
		const char* cMatrixType = NULL;

		// Matrix type pattern exist in file :
		if ((MatrixTypePos = strstr(FileContent, MatrixTypePattern)) != NULL) {
			// Move pointer to the end of MatrixType=
			MatrixTypePos += strlen(MatrixTypePattern);

			// If type is different than int, float and double, we throw Exception:
			if (strcmp(MatrixTypePos, "float") != 0 && strcmp(MatrixTypePos, "int") != 0 && strcmp(MatrixTypePos, "double") != 0) {
				Exception EXCObject;
				EXCObject.EXCSetErrorNumber(ERROR_UNKNOWN_TYPE);
				throw(EXCObject);
			}
			cMatrixType = MatrixTypePos;
		}

		// -----------------------To get Number of rows----------------------------------- :
		const char* NBRowsPos;
		unsigned int NBRows = 0;

		// If NbRows pattern exist in file, we extract the variable :
		if ((NBRowsPos = strstr(FileContent, NbRowsPattern)) != NULL) {
			// Move pointer to the end of NBRows= :
			NBRowsPos += strlen(NbRowsPattern);

			// If what we found if not a number, we throw exception :
			if (!isdigit(*NBRowsPos)) {
				Exception EXCObject;
				EXCObject.EXCSetErrorNumber(ERROR_NOT_NUMBER);
				throw(EXCObject);
			}
			NBRows = atoi(NBRowsPos);// Get NBRows
		}

		// -----------------------To get Number of columns----------------------------------- :
		const char* NBColumnsPos;
		unsigned int NBColumns = 0;

		// If NbColumns pattern exist in file, we extract the variable :
		if ((NBColumnsPos = strstr(FileContent, NbColumnsPattern)) != NULL) {
			// Move pointer to the end of NBColumns= :
			NBColumnsPos += strlen(NbColumnsPattern);

			// If what we found if not a number, we throw exception :
			if (!isdigit(*NBColumnsPos)) {
				Exception EXCObject;
				EXCObject.EXCSetErrorNumber(ERROR_NOT_NUMBER);
				throw(EXCObject);
			}
			NBColumns = atoi(NBColumnsPos);// Get NBcolumns
		}

		// Initialise matrix :
		Matrix = new CMatrix<double>(NBRows, NBColumns, cMatrixType);

		// ------------------------To get matrix values-------------------------------------- :
		char* MatrixStart;

		// If MatrixPattern exist in file :
		if ((MatrixStart = strstr(FileContent, MatrixPattern)) != NULL) {
			MatrixStart = strchr(MatrixStart, '[');// Move pointer to the beginnig of the matrix

			int i = 0;
			int j = 0;

			char* cursor = MatrixStart + 1;// Create cursor to go through matrix variables

			while (*cursor != ']' && *cursor != '\0') {
				// Skip spaces :
				while (isspace(*cursor)) {
					++cursor;
				}

				// If what we found if not a number, we throw exception :
				if (!isdigit(*cursor)) {
					Exception EXCObject;
					EXCObject.EXCSetErrorNumber(ERROR_NOT_NUMBER);
					throw(EXCObject);
				}
				// add value to matrix :
				(*Matrix)(i, j) = atoi(cursor);

				// Move to next index :
				j++;

				// Move to next line :
				if (*cursor == '\n') {
					i++;
					j = 0;
				}

				while (!isspace(*cursor) && *cursor != ']' && *cursor != '\0') {
					++cursor;
				}
			}
		}
	}

	return *Matrix;
}