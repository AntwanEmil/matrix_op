#include <iostream>
#include <math.h>
#include <string>
#include<cstdlib>
using namespace std;

void zayed(float mat1_real[100][100], float mat2_real[100][100], float mat1_img[100][100], float mat2_img[100][100], int row, int col);
void na2s(float mat1_real[100][100], float mat2_real[100][100], float mat1_img[100][100], float mat2_img[100][100], int row, int col);
void darb(float mat1_real[100][100], float mat2_real[100][100], float mat1_img[100][100], float mat2_img[100][100], int row, int col, int row2, int col2);
void pow(float mat1_real[100][100], float row, float power);
void trans(float mat1_real[100][100],int  row,int col);
float det(float mat1_real[100][100],int row);
void Inv(float mat1_real[100][100], float mat2_real[100][100], int row2, int row, int col, int div);


int main() {

	// gettin the 2 matrices as strings 
	string str1, str2 , op;
	getline(cin, str1);
	getline(cin, op);

		//parsing str1 into its elements 
	int len1 = str1.length();
		float real1, real2, img1, img2;
		int power;
		//finding no of rows and col. of str1 matrix
		int col = 1;
		int row = 1;
		for (int i = 0; i < len1; i++) {
			if (str1[i] == ';')
				row++;
		}
		for (int j = 0; j < len1; j++) {
			if (str1[j] == ' ')
				col++;
			if (str1[j] == ';')
				break;
		}
		int finder = str1.find(";", 10);
		int counterz = 0;
		while (1){
			if (str1.find(" ", finder) != -1){
				counterz++;
				finder = str1.find(" " , finder) + 1;
			}
			else break;
		}
		if (counterz+1 != col && op == "T") {
			cout << "ERROR";
			return 0;
		}
		 // 4 matrices w hansafarhoom 
		float mat1_real[100][100];
		float mat2_real[100][100];
		float mat1_img[100][100];
		float mat2_img[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++){
				mat1_real[i][j] = 0;
				mat2_real[i][j] = 0;
				mat1_img[i][j] = 0;
				mat2_img[i][j] = 0;
			}
		}

		//ha3be ellements str1 in mat1 ...... yarab

		string element;
		int before = 1;
		int flag = 0;
		float elem;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int after = str1.find(' ', before);
				int semicolon = str1.find(';', before);
					if (semicolon < after && semicolon!= -1) {
						element = str1.substr(before, semicolon-before);
						before = semicolon + 1;
					}
					
								else if (after != -1) {
								
								element = str1.substr(before, after - before);
								before = after + 1;
							}
								else {
									flag = 1;
									element = str1.substr(before,len1 - before-1);
								}

				//cout << element; ... element is 2-3i now 
				// a7awel el element l float w a7otto f mat1[i][j] ;;; done wow
				
								int length1 = element.length();
								int plus1 = element.find('+',1);
								int minus1 = element.find('-',1);
								int	imgf1 = element.find('i', 0); //8abaaaaaaaaaaaai
								if (minus1 == -1 && plus1 != -1){ //plus exists.
									real1 = atof(element.substr(0, plus1).c_str());
									img1 = atof(element.substr(plus1 , length1 - 1 - plus1).c_str());
									if (imgf1 != -1 && img1 == 0) img1 = 1;  //gded
								}
								
								else if (minus1 != -1 && plus1 == -1) { //minus exists
									real1 = atof(element.substr(0, minus1).c_str());
									img1 = atof(element.substr(minus1 , length1 - 1 - minus1).c_str());
									if (imgf1 != -1 && img1 == 0) img1 = -1;  //gded
								}
								else {
									if (imgf1 == -1){// real only ..
										real1 = atof(element.substr(0, length1).c_str());
										img1 = 0;
									}
									else if (imgf1 !=-1) {  //gdedd // there is an img part only... 5i or i -> 1i
										real1 = 0; 
										minus1 = element.find('-', 0);
									img1 = atof(element.substr(0, imgf1).c_str());
									if (img1 != 0) img1 = atof(element.substr(0, imgf1).c_str());
									else if (img1 == 0 && minus1 ==-1) img1 = 1; //gded 
									  else img1 = -1; //gded
									}
									else { real1 = 0; img1 = 0; } //7lwa y3ni
								}
								mat1_real[i][j] = real1;
								mat1_img[i][j] = img1;		
								
				if (flag == 1) break;
			}
		
		}


		if (op == "^"){
			cin >> power;
			//ERROR :::: SQUARE  ||  power <=0
			if (row == col && power > 0){

				 pow(mat1_real, row, power);
			}
		else cout << "ERORR";

		}
		if (op == "T"){
			int contt = 0;
				for (int j = 0; j < col+5; j++){
					if (mat1_real[0][j] == 0 && mat1_real[0][j]) break;
					contt++;
				}
				if (row == col || row > col){
					trans(mat1_real, row, col);
				}
				else cout << "ERROR";
		}


		if (op == "D"){
			if (row == col) {
			
	
				cout << det(mat1_real, row);
			}
			else cout << "ERROR";
		}




		if (op == "I"){
			if (row == col && det(mat1_real, row) != 0){  
			
				Inv(mat1_real, mat1_real, row ,0,0, 0);
			}
			else cout << "ERROR";
		}
		// str2 b2aa :D  
		if (op == "/" || op == "*" || op == "+" || op == "-"){
			//ezaai lazm ma5odhaash
			getline(cin, str2);
			int len2 = str2.length();
			int col2 = 1;
			int row2 = 1;
			for (int i = 0; i < len2; i++) {
				if (str2[i] == ';')
					row2++;
			}
			for (int j = 0; j< len2; j++) {
				if (str2[j] == ' ')
					col2++;
				if (str2[j] == ';')
					break;
			}


			string element2;
			int before2 = 1;
			int flag2 = 0;
			float elem2;
			for (int i = 0; i < row2; i++) {
				for (int j = 0; j < col2; j++) {
					int after2 = str2.find(' ', before2);
					int semicolon = str2.find(';', before2);
					if (semicolon < after2 && semicolon != -1) {
						element2 = str2.substr(before2, semicolon - before2);
						before2 = semicolon + 1;
					}

					else if (after2 != -1) {

						element2 = str2.substr(before2, after2 - before2);
						before2 = after2 + 1;
					}
					else {
						flag2 = 1;
						element2 = str2.substr(before2, len2 - before2 - 1);
					}

					//	cout << element;
					// a7awel el element l float w a7otto f mat1[i][j] ;;; done wow
					int length2 = element2.length();
					int	imgf2 = element2.find('i', 0);
					int plus2 = element2.find('+', 1);
					int minus2 = element2.find('-', 1);
					if (minus2 == -1 && plus2 != -1){ //plus exists.
						real2 = atof(element2.substr(0, plus2).c_str());
						img2 = atof(element2.substr(plus2, length2 - 1 - plus2).c_str());
						if (imgf2 != -1 && img2 == 0) img2 = 1;  //gded
					}
					else if (minus2 != -1 && plus2 == -1) { //minus exists
						real2 = atof(element2.substr(0, minus2).c_str());
						img2 = atof(element2.substr(minus2, length2 - 1 - minus2).c_str());
						if (imgf2 != -1 && img2 == 0) img2 = -1;  //gded
					}
					else {
						if (imgf2 == -1){
							real2 = atof(element2.substr(0, length2).c_str());
							img2 = 0;
						}
						else if (imgf2 != -1) {
							real2 = 0;
							minus2 = element2.find('-', 0);
							img2 = atof(element2.substr(0, imgf2).c_str());
							if (img2 != 0) img2 = atof(element2.substr(0, imgf2).c_str());
							else	if (img2 == 0 && minus2 == -1) img2 = 1; //gded
							else img2 = -1; //gded
						}
						else { real2 = 0; img2 = 0; } //7lwa y3ni

					}
					mat2_real[i][j] = real2;
					mat2_img[i][j] = img2;

					if (flag2 == 1) break;
				}

			}

			//ADDITION >>>>>>>>>>>
			if (op == "+"){
				if (row == row2 && col == col2)
					zayed(mat1_real, mat2_real, mat1_img, mat2_img, row, col);
				else{
					cout << "ERROR";

				}
			}
			//SUBTraction >>>
			if (op == "-"){
				if (row == row2 && col == col2)
					na2s(mat1_real, mat2_real, mat1_img, mat2_img, row, col);
				else{
					cout << "ERROR";

				}
			}
			//multiplication>>>
			if (op == "*"){
				if (col == row2)
					darb(mat1_real, mat2_real, mat1_img, mat2_img, row, col, row2, col2);
				else{
					cout << "ERROR";

				}
			}

			if (op == "/"){
				if ( row2 == col2 && col == row2){

					Inv(mat1_real, mat2_real, row2 ,row,col , 1);
				}
				else{
					cout << "ERROR";
				}
			}
		}

	system("pause");
	return 0;
}








void zayed(float mat1_real[100][100], float mat2_real[100][100], float mat1_img[100][100], float mat2_img[100][100], int row, int col){
	cout << "[";
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++) {
			float plus_real = mat1_real[i][j] + mat2_real[i][j];
			float plus_img = mat1_img[i][j] + mat2_img[i][j];
		if (plus_real>0 || plus_real<0)	cout << plus_real;
		
		
		if (plus_img > 0 && plus_real != 0) { 
			if (plus_img == 1) cout << '+' <<'i';
			else cout << '+' << plus_img << 'i'; }

		else if (plus_img > 0 && plus_real == 0) {
			if (plus_img == 1) cout << 'i';
			else	cout << plus_img << 'i'; }

		else if (plus_img < 0 ) {
			if (plus_img == -1) cout << "-i";
			else cout << plus_img << 'i'; 
		}
			if (plus_real ==0 && plus_img ==0) cout << '0';
			if (j< col-1)
			cout << " ";
		}
		if (i<row-1)
		cout << ";";
	}

	cout << "]";

}
void na2s(float mat1_real[100][100], float mat2_real[100][100], float mat1_img[100][100], float mat2_img[100][100], int row, int col){
	cout << "[";

	for (int i = 0; i < row; i++){

		for (int j = 0; j < col; j++) {
			float subtraction_real = mat1_real[i][j] - mat2_real[i][j];
			float subtraction_img = mat1_img[i][j] - mat2_img[i][j];
			if (subtraction_real>0 || subtraction_real<0)cout << subtraction_real;

			if (subtraction_img > 0 && subtraction_real != 0){
				if (subtraction_img == 1) cout << '+' << 'i';
				else	cout << '+' << subtraction_img << 'i'; }

			else if (subtraction_img > 0 && subtraction_real == 0){ 
				if (subtraction_img == 1) cout << 'i';
				else	cout << subtraction_img << 'i'; }

			else if (subtraction_img < 0){
				if (subtraction_img == -1) cout << '-' << 'i';
				else cout << subtraction_img << 'i';
			}
			if (subtraction_real == 0 && subtraction_img == 0) cout << '0';
			if (j< col - 1)
				cout << " ";
		}
		if (i<row - 1)
			cout << ";";
	}

	cout << "]";

}


void darb(float mat1_real[100][100], float mat2_real[100][100],float mat1_img[100][100] ,float mat2_img[100][100],  int row, int col ,int row2 , int col2){
	cout << "[";
	
	for (int i = 0; i < row; i++){
		//cuz we wanna multiple the 1st row of mat1 by the 1st and 2nd rows of mat2;;
		for (int k = 0; k < col2; k++){
			float sum_real = 0;
			float sum_img = 0;
			for (int j = 0; j < col; j++) {

				float mult_real = mat1_real[i][j] * mat2_real[j][k] - mat1_img[i][j] * mat2_img[j][k];
				sum_real  += mult_real;
				float mult_img = mat1_real[i][j] * mat2_img[j][k] + mat1_img[i][j] * mat2_real[j][k];
				sum_img += mult_img;
				if (j == col - 1){
					//cout << real And img .. 
					if (sum_real>0 || sum_real<0)	cout << sum_real; 

					if (sum_img > 0 && sum_real != 0){ 
						if (sum_img == 1) cout << '+' << 'i';
						else cout << '+' << sum_img << 'i'; }

					else if (sum_img > 0 && sum_real == 0) {
						if (sum_img == 1) cout << 'i';
						else	cout << sum_img << 'i';
					}

					else if (sum_img < 0) {
						if (sum_img == -1) cout << "-i";
						else cout << sum_img << 'i';
					}
					if (sum_real == 0 && sum_img == 0) cout << '0';


				}
		}
			if (k == col2 - 1 && i == row - 1) {
				cout<< "]";
				break;
			}
			else if (k == col2 - 1 ) cout << ";";
			else  cout << " ";

		}
		
}
	
}

void pow(float mat1_real[100][100], float row, float power){
	
		float sum[100][100];
		float result[100][100];
		//zeroing sum ;; 
		for (int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){

				sum[i][j] = 0;
				result[i][j] = 0;
			}

		}

		//intitializing sum to mat1_real[][]
		for (int i = 0; i < row; i++){
			for (int j = 0; j < row; j++){

				sum[i][j] = mat1_real[i][j];
				result[i][j] = mat1_real[i][j];
			}

		}

		// hadrb el sum f mat1_real[][]
		float mult = 0;
		for (int m = 1; m < power; m++){
			for (int i = 0; i < row; i++){
				//cuz we wanna multiple the 1st row of mat1 by the 1st and 2nd rows of mat2;;
				for (int k = 0; k < row; k++){

					for (int j = 0; j < row; j++) {

						mult += mat1_real[i][j] * sum[j][k];	
							result[i][k] = mult;
				


					}
					mult = 0;
				}
			}

			for (int i = 0; i < row; i++){
				for (int j = 0; j < row; j++){
					sum[i][j] = result[i][j];
				}
			}
		}

		cout << "[";
		for (int i = 0; i < row; i++) {

			for (int j = 0; j < row; j++){

				cout << result[i][j];

				if (j < row - 1)
					cout << " ";
			}
			if (i<row - 1)
				cout << ";";

			}

		cout << "]";
	}
void trans(float mat1_real[100][100], int  row, int col) {
	cout << "[";
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			cout << mat1_real[j][i];
			if (j < row - 1)
				cout << " ";
		}
		if (i < col - 1) cout << ";";

	}
	cout << "]";

}



float det(float mat1_real[100][100], int row){
	float sum = 0;
	if (row == 2) {
		sum = mat1_real[0][0] * mat1_real[1][1] - mat1_real[1][0] * mat1_real[0][1];
		return sum;
	}
	else if (row == 3) {
		sum = mat1_real[0][0] * (mat1_real[1][1] * mat1_real[2][2] - mat1_real[1][2] * mat1_real[2][1]) - mat1_real[0][1] * (mat1_real[1][0] * mat1_real[2][2] - mat1_real[1][2] * mat1_real[2][0]) + mat1_real[0][2] * (mat1_real[1][0] * mat1_real[2][1] - mat1_real[1][1] * mat1_real[2][0]);
		return sum;
	}
	else {
		//hasafarhaa
		//	float submat[50][50][50];

		float submat1[100][100];
		for (int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){
				submat1[i][j] = 0;
			}
		}
		int flag = 0;
		int row1 = 0, col1 = 0;
		float coeff[100];
		for (int i = 0; i < row; i++) coeff[i] = 0;
		for (int i = 0; i < row; i++){
			coeff[i] = mat1_real[0][i];
		}


		//ta2te3 el mat ...
		for (int k = 0; k < row; k++)
		{
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++){


					if (j == k) {
						flag = 1;
						continue;
					}
					else{
						if (flag == 0) submat1[i][j] = mat1_real[i + 1][j];
						else  submat1[i][j - 1] = mat1_real[i + 1][j];
						row1++;
						col1++;
						/*
						if (flag == 0) submat[i][j][k] = mat1_real[i + 1][j];
						else  submat[i][j - 1][k] = mat1_real[i + 1][j];*/
					}

				}
				flag = 0;
			}
			if (k % 2 == 0){
				sum = sum + ( mat1_real[0][k] * det(submat1, row - 1));
			}
			else {
				sum = sum - (mat1_real[0][k] * det(submat1, row - 1));
			}
		}


		return sum;
	}
}







void Inv(float mat1_real[100][100],float mat2_real[100][100] , int row2,int row , int col , int div) {
	float bigdet = det(mat2_real, row2);
	int row1 = 0, col1 = 0;
	float submat[100][100];
	float mat_clone[100][100];
	float mat1_clone[100][100];
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			submat[i][j] = 0;
			mat_clone[i][j] = 0;
			mat_clone[i][j] = 0;
		}
	}


	for (int i = 0; i < row2; i++){
		row1 = 0;
		col1 = 0;
		for (int j = 0; j < row2; j++){
			row1 = 0;
			col1 = 0;
			for (int k = 0; k < row2; k++){
				for (int m = 0; m < row2; m++){
					if (k == i || m == j) continue;

					else {
						submat[row1][col1] = mat2_real[k][m];
						col1++;
						//cout <<submat[k][m] << " ";
					}
				}
				//cout << "\n";
				if (k  != i) row1++;
				col1 = 0;
			}
			mat_clone[i][j] =  det(submat, row2 - 1);
			row1 = 0;
			//hna kamlaaaa
			
		}
	}
	int signcounter = 0;
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < row2; j++) {
			if (signcounter % 2 != 0){ if (mat_clone[i][j] !=0 )mat_clone[i][j] = -1 * mat_clone[i][j]; }
			signcounter++;
		}
	}
	//tgrobaaa 
	for (int i = 0; i < row2; i++) {

		for (int j = 0; j < row2; j++) {

			if (j == i) mat1_clone[i][j] = mat_clone[i][j];
			else mat1_clone[i][j] = mat_clone[j][i];
		}
	}


	for (int i = 0; i < row2; i++) {

		for (int j = 0; j < row2; j++) {

		 mat1_clone[i][j] = mat1_clone[i][j] / bigdet ;
		}
	}

	//output in case of inv. only :D
	if (div == 0){
		cout << "[";

		for (int i = 0; i < row2; i++){
			for (int j = 0; j < row2; j++){

				cout << mat1_clone[i][j];

				if (j < row2 - 1)
					cout << " ";
			}

			if (i < row2 - 1)
				cout << ";";

		}

		cout << "]";

	}

	//darb 3ady
	else{
		//hadrb mat2_real fe mat1_clone :D
		//row2 = col2 :D 
		cout << "[";

		for (int i = 0; i < row; i++){
			//cuz we wanna multiple the 1st row of mat1 by the 1st and 2nd rows of mat2;;
			for (int k = 0; k < row2; k++){
				float sum = 0;
				for (int j = 0; j < col; j++) {

					float mult = mat1_real[i][j] * mat1_clone[j][k];
					sum = sum + mult;
					if (j == col - 1) cout << sum;
				}
				if (k == row2- 1 && i == row - 1) {
					cout << "]";
					break;
				}
				else if (k == row2 - 1) cout << ";";
				else  cout << " ";

			}

		}




	}


}