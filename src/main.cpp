/**
 * @file main.cpp
 * @author Reda TARGAOUI & Zakaria JANNANI
 * @version 1.0
 * @date 08/04/2023
*/

#include <iostream>
#include "../headers/Exception.h"
#include "../headers/FileAnalyser.h"
#include "../headers/Matrix.h"

using namespace std;

/**
* @fn main()
* @brief main fonction
* @param argc : number of passed arguments
* @param argv : passed arguments
* @return 0 in case of normal end
*/
int main(int argc, char* argv[]) {
	CMatrix<double> Matrix;

	FileAnalyser test;

	Matrix = test.analyseFile(argv[1]);
	// If user passed arguments :
	//if (argc > 1) {
	//	try {
	//		unsigned int NBMatrices = argc - 1;

	//		CMatrix<double>* Matrices = new CMatrix<double>[NBMatrices];

	//		FileAnalyser fileAnalyser;
	//		int i;

	//		// *************************Matrices creation :******************************
	//		for (i = 0; i < NBMatrices; i++) {
	//			Matrices[i] = fileAnalyser.analyseFile(argv[i + 1]);
	//		}

	//		// *************************Display matrices :******************************
	//		cout << "--------------------------Matrices :------------------------------" << endl;
	//		for (i = 0; i < NBMatrices; i++) {
	//			cout << "\n-->Matrix " << i + 1 << " : " << endl;
	//			Matrices[i].DisplayMatrix();
	//		}

	//		// *************************Operations on Matrices :******************************
	//		cout << "\n-------------------------Operations on Matrices :------------------------------" << endl;
	//		// Addition operation :
	//		CMatrix<double> OperationResult = Matrices[0];

	//		for (i = 1; i < NBMatrices; i++) {
	//			OperationResult = OperationResult + Matrices[i];
	//		}
	//		cout << "\n-->Addition operation on all matrices : " << endl;
	//		OperationResult.DisplayMatrix();

	//		// Minus operation : 
	//		OperationResult = Matrices[0];

	//		for (i = 1; i < NBMatrices; i++) {
	//			OperationResult = OperationResult - Matrices[i];
	//		}
	//		cout << "\n-->Minus operation on all matrices : " << endl;
	//		OperationResult.DisplayMatrix();

	//		// Multiplication operation :
	//		OperationResult = Matrices[0];

	//		for (i = 1; i < NBMatrices; i++) {
	//			OperationResult = OperationResult * Matrices[i];
	//		}
	//		cout << "\n-->Multiplication operation on all matrices : " << endl;
	//		OperationResult.DisplayMatrix();

	//		cout << endl;

	//		// Transpose :
	//		for (i = 0; i < NBMatrices; i++) {
	//			cout << "\n-->Transpose of Matrice " << i + 1 << " : " << endl;
	//			(Matrices[i].MatrixTranspose()).DisplayMatrix();
	//		}

	//		// Operations on variables :
	//		double variable;
	//		cout << "\n*Enter a variable :";
	//		cin >> variable;

	//		// Division :
	//		for (i = 0; i < NBMatrices; i++) {
	//			cout << "\n-->Matrice " << i + 1 << " Divided by " << variable << " : " << endl;
	//			(Matrices[i] / variable).DisplayMatrix();
	//		}

	//		cout << endl;

	//		// Multiplication of type (Matrice * variable):
	//		for (i = 0; i < NBMatrices; i++) {
	//			cout << "\n-->Matrice " << i + 1 << " Multiplied by " << variable << " : " << endl;
	//			(Matrices[i] * variable).DisplayMatrix();
	//		}

	//		cout << endl;

	//		// Multiplication of type (variable * Matrice)):
	//		for (i = 0; i < NBMatrices; i++) {
	//			cout << "\n-->" << variable << " Multiplied by matrice" << i + 1 << " : " << endl;
	//			(variable * Matrices[i]).DisplayMatrix();
	//		}

	//		// Operation of type M1-M2+M3-M4+M5-M6+...
	//		OperationResult = Matrices[0];

	//		cout << endl;

	//		cout << "\n-->Operation of type M1-M2+M3-M4+M5-M6+... : " << endl;
	//		for (i = 1; i < NBMatrices; i++) {
	//			if (i % 2 == 0) {
	//				OperationResult = OperationResult - Matrices[i];
	//			}
	//			else {
	//				OperationResult = OperationResult + Matrices[i];
	//			}
	//		}
	//		OperationResult.DisplayMatrix();

	//	}
	//	catch (Exception EXCObject) {
	//		EXCObject.EXCDisplayMessage();
	//	}

	//}

	//// If user didn't give any arguments :
	//else {
	//	cout << "ERROR : Please passe some files as arguments !!" << endl;
	//}

	return 0;
}
