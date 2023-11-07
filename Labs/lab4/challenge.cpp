#include <iostream>
using namespace std;

void noRepeat(char first[], int length_first, char second[], int length_second, char result[]) {
    int i = 0;
    int j = 0;

    // Remove repeated characters from the 'first' array
    for (i = 0; i < length_first; i++) {
        bool isRepeated = false;
        for (int k = 0; k < i; k++) {
            if (first[i] == first[k]) {
                isRepeated = true;
                break;
            }
        }
        if (!isRepeated) {
            result[j] = first[i];
            j++;
        }
    }

    // Remove repeated characters from the 'second' array
    for (int k = 0; k < length_second; k++) {
        bool isRepeated = false;
        for (int l = 0; l < j; l++) {
            if (second[k] == result[l]) {
                isRepeated = true;
                break;
            }
        }
        if (!isRepeated) {
            result[j] = second[k];
            j++;
        }
    }
}

int main() {
    char first[] = {'h', 'e', 'l', 'l', 'o', ' '};
    char second[] = {'l', 'l', 'a', 'm', 'a'};
    char result[100] = {};

    noRepeat(first, 6, second, 5, result);

    cout << result << endl;
    return 0;
}
