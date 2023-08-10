#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxRows = 10;
const int maxCols = 10;

void initialize(int array[][maxCols], int row, int col, int num = -1) {
    if (num == -1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                array[i][j] = num;
            }
        }
    } else if (num != -1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                array[i][j] = rand() % 20 + 1;
            }
        }
    }
}

void display(int disp_array[][maxCols], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int f = 0; f < c; f++) {
            cout << disp_array[i][f] << "\t";
        }
        cout << endl;
    }
}

void getEmail(string &userEmail) {
    cout << "Enter your email: ";
    cin >> userEmail;
}

bool isWrongFormat(string userEmail) {
    int emailLength = userEmail.length();
    int atLocation = userEmail.find('@');
    int dotLocation = userEmail.find('.');
    
    if (atLocation != string::npos && atLocation != 0 && atLocation != emailLength - 1 &&
        dotLocation != string::npos && dotLocation != emailLength - 1 &&
        dotLocation > atLocation && isalnum(userEmail[atLocation + 1])) {
        return false;
    } else {
        return true;
    }
}

int main() {
    srand(time(NULL));

    int num_array[maxRows][maxCols];
    int disp_array[maxRows][maxCols];
    int r, c;

    cout << "Enter rows and columns of the matrix: ";
    cin >> r >> c;

    if ((r <= 1 && c <= 1) || r > 10 || c > 10) {
        cout << "Values are not within range. Please enter rows and columns of the matrix: ";
        cin >> r >> c;
    }

    initialize(num_array, r, c);

    initialize(disp_array, r, c);
    display(disp_array, r, c);

    string userEmail;
    getEmail(userEmail);

    while (isWrongFormat(userEmail)) {
        cout << "Your email is not in the correct format. Please enter again." << endl;
        getEmail(userEmail);
    }

    cout << "Enter coordinates to reveal: ";
    int crd1, crd2;
    cin >> crd1 >> crd2;

    disp_array[crd1][crd2] = num_array[crd1][crd2];
    cout << num_array[crd1][crd2] << " " << disp_array[crd1][crd2] << endl;

    initialize(disp_array, r, c);
    display(disp_array, r, c);

    cout << "Enter second coordinates to reveal second matching number: ";
    int ecrd1, ecrd2;
    cin >> ecrd1 >> ecrd2;

    disp_array[ecrd1][ecrd2] = num_array[ecrd1][ecrd2];
    cout << num_array[ecrd1][ecrd2] << " " << disp_array[ecrd1][ecrd2] << endl;

    initialize(disp_array, r, c);
    display(disp_array, r, c);

    if (disp_array[ecrd1][ecrd2] == disp_array[crd1][crd2]) {
        cout << "You have found a matched number +2 points" << endl;
    } else {
        cout << "NOT A MATCH. You lose 1 point" << endl;
    }

    return 0;
}