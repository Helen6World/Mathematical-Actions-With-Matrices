#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
#include<math.h>

using namespace std;

void enter_the_matrix_by_user(int** mas, int m); //input matrix by the user
void enter_the_matrix_random(int** mas, int m); //the introduction of the matrix randomly
void print_the_matrix(int** mas, int m); //display of the matrix on the screen
void transposed_matrix(int** mas, int m); //finding the transposed 2-parameter matrix
void multiply_number_to_matrix(int** mas, int m, int number); //multiplication of the matrix by the number
void Stepin(int** mas, int** mas_result, int m); //raising the matrix to a degree
int determ(int** mas, int m); //finding the determinant of the matrix
void add_and_subtract_two_matrix(int** mas1, int** mas2, int m, int action); //adding and subtracting matrices
void multiply_two_matrix(int** mas1, int** mas2, int m); //multiplication of two matrices

int main() {
	srand(time(NULL));
	string smenu;
	bool temp_boolean, temp_boolean2;
	int menu_for_action = 0, exit_the_program;
	do {
		exit_the_program = 0;
		cout << "Enter the size of the square matrix (m x m): ";
		int number_matrix = 0;
		do {
			cin >> smenu;
			if (smenu == "1") number_matrix = 1;
			else if (smenu == "2") number_matrix = 2;
			else if (smenu == "3") number_matrix = 3;
			else if (smenu == "4") number_matrix = 4;
			else if (smenu == "5") number_matrix = 5;
			else if (smenu == "6") number_matrix = 6;
			else if (smenu == "7") number_matrix = 7;
			else if (smenu == "8") number_matrix = 8;
			else if (smenu == "9") number_matrix = 9;
			else if (smenu == "10") number_matrix = 10;
			else {
				cout << "Error while typing, please select dimension again: ";
				number_matrix = 0;
			}
		} while (number_matrix == 0);
		int** matrix = new int* [number_matrix];
		cout << "Set matrix values manually (1) or randomly (2)?\n";
		int temp_menu;
		do {
			cin >> smenu;
			if (smenu == "1") {
				temp_menu = 1;
				enter_the_matrix_by_user(matrix, number_matrix);
			}
			else if (smenu == "2") {
				temp_menu = 2;
				enter_the_matrix_random(matrix, number_matrix);
			}
			else {
				cout << "Error entering, please select the value again: ";
				temp_menu = 0;
			}
		} while (temp_menu == 0);
		print_the_matrix(matrix, number_matrix);

		do {
			cout << "\nDo you want to calculate over one matrix?(1-yes, 2-no): ";
			do {
				cin >> smenu;
				if (smenu == "1") {
					temp_menu = 1;
				}
				else if (smenu == "2") {
					temp_menu = 2;
				}
				else {
					cout << "Error entering, please select the value again: ";
					temp_menu = 0;
				}
			} while (temp_menu == 0);

			switch (temp_menu) {
			case 1: {
				cout << "\nSelect an action on one matrix:\n\n";
				cout << "\t\t1-Find the determinant of the matrix\n" << "\t\t2-Raise the matrix to the degree\n";
				cout << "\t\t3-Find the transposed matrix\n" << "\t\t4-Multiplication of the matrix by the number\n" << "\t\t5-Exit\n";
				do {
					cin >> smenu;
					if (smenu == "1") menu_for_action = 1;
					else if (smenu == "2") menu_for_action = 2;
					else if (smenu == "3") menu_for_action = 3;
					else if (smenu == "4") menu_for_action = 4;
					else if (smenu == "5") menu_for_action = 5;
					else if (smenu == "6") menu_for_action = 6;
					else if (smenu == "7") menu_for_action = 7;
					else {
						cout << "Error entering, please select the value again: ";
						menu_for_action = 0;
					}
				} while (menu_for_action == 0);
				switch (menu_for_action) {
					case 1: {
						cout << "The determinant of the matrix= " << determ(matrix, number_matrix) << endl;
						break;
					}
					case 2: {
						int** multiply_matrix = new int* [number_matrix];
						for (int i = 0; i < number_matrix; i++) {
							multiply_matrix[i] = new int[number_matrix];
							for (int j = 0; j < number_matrix; j++) {
								multiply_matrix[i][j] = matrix[i][j];
							}
						}
						int to_number;
						cout << "Enter the degree to which the matrix is to be raised: ";
						do {
							cin >> smenu;
							if (smenu == "1") to_number = 1;
							else if (smenu == "2") to_number = 2;
							else if (smenu == "3") to_number = 3;
							else if (smenu == "4") to_number = 4;
							else if (smenu == "5") to_number = 5;
							else {
								cout << "Error entering, please select the value again: ";
								to_number = 0;
							}
						} while (to_number == 0);
						while (to_number != 1) {
							Stepin(matrix, multiply_matrix, number_matrix);
							to_number--;
						}
						cout << "Result of calculations:\n";
						print_the_matrix(multiply_matrix, number_matrix);
						for (int i = 0; i < number_matrix; i++) {
							delete[] multiply_matrix[i];
						}
						delete[] multiply_matrix;
						break;
					}
					case 3: {
						transposed_matrix(matrix, number_matrix);
						break;
					}
					case 4: {
						cout << "Enter a number by which to multiply the matrix: ";
						int number;
						cin >> number;
						multiply_number_to_matrix(matrix, number_matrix, number);
						break;
					}
					case 5: {
						exit_the_program = 1;
						break;
					}
				}
			}
			case 2: {
				int** matrix2 = new int* [number_matrix];
				cout << "Set the second matrix manually (1) or randomly (2)?: ";
				int temp_menu;
				do {
					cin >> smenu;
					if (smenu == "1") {
						temp_menu = 1;
						enter_the_matrix_by_user(matrix2, number_matrix);
					}
					else if (smenu == "2") {
						temp_menu = 2;
						enter_the_matrix_random(matrix2, number_matrix);
					}
					else {
						cout << "Error entering, please select the value again: ";
						temp_menu = 0;
					}
				} while (temp_menu == 0);
				print_the_matrix(matrix2, number_matrix);
				cout << "\nSelect the action on the two matrices:\n\n";
				cout << "\t\t1-Add matrices\n" << "\t\t2-Subtract the matrix\n";
				cout << "\t\t3-Multiply the matrix\n" << "\t\t4-Exit\n";
				do {
					cin >> smenu;
					if (smenu == "1") menu_for_action = 1;
					else if (smenu == "2") menu_for_action = 2;
					else if (smenu == "3") menu_for_action = 3;
					else if (smenu == "4") menu_for_action = 4;
					else if (smenu == "5") menu_for_action = 5;
					else {
						cout << "Error entering, please select the value again: ";
						menu_for_action = 0;
					}
				} while (menu_for_action == 0);
				switch (menu_for_action) {
					case 1: {
						add_and_subtract_two_matrix(matrix, matrix2, number_matrix, 1);
						break;
					}
					case 2: {
						add_and_subtract_two_matrix(matrix, matrix2, number_matrix, 2);
						break;
					}
					case 3: {
	
						multiply_two_matrix(matrix, matrix2, number_matrix);
						break;
					}
					case 4: {
						exit_the_program = 1;
						break;
					}
				}
				for (int i = 0; i < number_matrix; i++) {
					delete[] matrix2[i];
				}
				delete[] matrix2;
			}
		}
			if (!exit_the_program) {
				cout << "Do you want to continue using the program? (1-yes 2-no): ";
				do {
					cin >> smenu;
					if (smenu == "1") {
						exit_the_program = 0;
						cout << "From the beginning of the program(1) or after the matrix announcement(2)?: ";
						do {
							cin >> smenu;
							if (smenu == "1") {
								cout << "\tCONTINUED FROM THE BEGINNING OF THE PROGRAM\n";
								exit_the_program = 10;
							}
							else if (smenu == "2") {
								cout << "\tCONTINUATION AFTER ANNOUNCEMENT OF THE FIRST MATRIX\n";
								exit_the_program = 20;
							}
							else {
								cout << "Помилка при введенні, oберіть, будь ласка, дію ще раз: ";
								exit_the_program = -30;
							}
						} while (exit_the_program == -30);
					}
					else if (smenu == "2") {
						exit_the_program = 1;
						for (int i = 0; i < number_matrix; i++) {
							delete[] matrix[i];
						}
						delete[] matrix;
					}
					else {
						cout << "Error entering, please select the value again: ";
						exit_the_program = -1;
					}
				} while (exit_the_program == -1);
			}
		} while (exit_the_program == 20);
	} while (exit_the_program == 0);
	cout << "\n\tThank you for using the program, goodbye\n";
	return 0;
}

void enter_the_matrix_by_user(int** mas, int m) {
	string stech;
	int lich = 0, length_s;
	bool mark;
	cout << "\nEnter " << pow(m, 2);
	if (m == 1) cout << " element of the matrix ";
	else cout << " elements of the matrix ";
	for (int i = 0; i < m; i++) {
		mas[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin>>mas[i][j];
		}
	}
}

void enter_the_matrix_random(int** mas, int m) {
	for (int i = 0; i < m; i++) {
		mas[i] = new int[m];
		for (int j = 0; j < m; j++) {
			mas[i][j] = 1 + rand() % 30;
		}
	}
}

void print_the_matrix(int** mas, int m) {
	cout << "Your matrix:\n";
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < m; j++) {
			cout << setw(7) << mas[i][j] << " ";
		}
		cout << "|\n";
	}
}

void transposed_matrix(int** mas, int m) {
	int** mas_trans = new int* [m];
	for (int i = 0; i < m; i++) {
		mas_trans[i] = new int[m];
		for (int j = 0; j < m; j++) {
			mas_trans[i][j] = mas[j][i];
		}
	}
	cout << "\nTransposition operation\n";
	print_the_matrix(mas_trans, m);
	for (int i = 0; i < 0; i++) {
		delete[] mas_trans[i];
	}
	delete[] mas_trans;
}

void multiply_number_to_matrix(int** mas, int m, int number) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			mas[i][j] *= number;
		}
	}
	print_the_matrix(mas, m);
}

void Stepin(int** mas, int** mas_result, int m) {
	int** mas_temp = new int* [m];
	for (int i = 0; i < m; i++) {
		mas_temp[i] = new int[m];
		for (int j = 0; j < m; j++) {
			mas_temp[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int s = 0; s < m; s++) {
				mas_temp[i][j] += mas[i][s] * mas_result[s][j];
			}

		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			mas_result[i][j] = mas_temp[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		delete[] mas_temp[i];
	}
	delete[] mas_temp;
}

int determ(int** mas, int m) {
	int i, j;
	int det = 0;
	int** add_mas;
	if (m == 1) {
		det = mas[0][0];
	}
	else if (m == 2) {
		det = mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
	}
	else {
		add_mas = new int* [m - 1];
		for (i = 0; i < m; i++) {
			for (j = 0; j < m - 1; j++) {
				if (j < i) {
					add_mas[j] = mas[j];
				}
				else {
					add_mas[j] = mas[j + 1];
				}
			}
			det += pow(-1, (i + j)) * determ(add_mas, m - 1) * mas[i][m - 1];
		}
		delete[] add_mas;
	}
	return det;
}

void add_and_subtract_two_matrix(int** mas1, int** mas2, int m, int action) {
	int** mas_result = new int* [m];
	for (int i = 0; i < m; i++) {
		mas_result[i] = new int[m];
		for (int j = 0; j < m; j++) {
			if (action == 1) mas_result[i][j] = mas1[i][j] + mas2[i][j];
			else if (action==2) mas_result[i][j] = mas1[i][j] - mas2[i][j];
		}
	}
	print_the_matrix(mas_result, m);
	for (int i = 0; i < 0; i++) {
		delete[] mas_result[i];
	}
	delete[] mas_result;
}

void multiply_two_matrix(int** mas1, int** mas2, int m) {
	int** mas_result = new int* [m];
	for (int i = 0; i < m; i++) {
		mas_result[i] = new int[m];
		for (int j = 0; j < m; j++) {
			mas_result[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int lich = 0; lich < m; lich++) {
				mas_result[i][j] += mas1[i][lich] * mas2[lich][j];
			}
		}
	}
	cout << "\nMultiplication of two matrices:\n";
	print_the_matrix(mas_result, m);
	for (int i = 0; i < 0; i++) {
		delete[] mas_result[i];
	}
	delete[] mas_result;
}
