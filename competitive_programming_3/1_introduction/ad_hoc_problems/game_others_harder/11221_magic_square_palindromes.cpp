#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // sqrt(x), ceil(x)
#include <algorithm> // erase


using namespace std;

bool DEBUG = false;

bool isSquare(string line) {
    double res;
	res = sqrt(line.length());
    return (res == floor(res));
}

int indexOfMatrix(int row, int column, int size) {
    return (row * size) + column;
}

bool is_palindrome_from_1_1_down_right(string line) {
    int lado = (int) sqrt(line.length());

    int iter = 0;

    for (int j = 0; j < lado; j++) {
        for (int i = 0; i < lado; i++) {
            if (line[indexOfMatrix(i,j,lado)] ==  line[iter]) {
                // cool
            } else {
                return false;
            }
            iter++;
        }
    }
    return true;
}

bool is_palindrome_from_K_K_left_up(string line) {
    int lado = (int) sqrt(line.length());

    int iter = 0;

    for (int i = lado - 1; i >= 0; i--) {
        for (int j = lado -1; j >= 0; j--) {
            if (line[indexOfMatrix(i,j,lado)] ==  line[iter]) {
                // cool
            } else {
                return false;
            }
            iter++;
        }
    }
    return true;
}

bool is_palindrome_from_K_K_up_left(string line) {
    int lado = (int) sqrt(line.length());

    int iter = 0;

    for (int j = lado - 1; j >= 0; j--) {
        for (int i = lado -1; i >= 0; i--) {
            if (line[indexOfMatrix(i,j,lado)] ==  line[iter]) {
                // cool
            } else {
                return false;
            }
            iter++;
        }
    }
    return true;
}

bool isMagic(string line) {
    return is_palindrome_from_1_1_down_right(line) 
        && is_palindrome_from_K_K_left_up(line) 
        && is_palindrome_from_K_K_up_left(line);
}

void remove_whitespace_and_punctuation(string& line) {
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    line.erase(remove(line.begin(), line.end(), '.'), line.end());
    line.erase(remove(line.begin(), line.end(), '('), line.end());
    line.erase(remove(line.begin(), line.end(), ')'), line.end());
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    line.erase(remove(line.begin(), line.end(), '?'), line.end());
    line.erase(remove(line.begin(), line.end(), '!'), line.end());
}


int main()
{
    int testCases;
    scanf("%d\n", &testCases);
    
    string line;
    int numCase = 0;

    while (testCases--)
    {
        numCase++;
        cout << "Case #" <<   numCase << ":" << endl;
        getline(cin, line);

        if (DEBUG) cout << line << endl;
        remove_whitespace_and_punctuation(line);
        if (DEBUG) cout << line << endl;

        if (isSquare(line)){
            if (isMagic(line)) {
                cout << sqrt(line.length()) << endl;
            } else {
                cout << "No magic :(" << endl;    
            }
        } else {
            cout << "No magic :(" << endl;
        }    
    }
}