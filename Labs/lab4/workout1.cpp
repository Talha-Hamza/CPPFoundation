# include <iostream>

using namespace std;


void append(char first[], int length_first, char second[], int length_second, char result[])
{
    int i = 0;
    for (i = 0; i < length_first-1; i++) {
        result[i] = first[i];
        // cout << "item " << i << " " << result[i] << endl;
    }

    for (int j = 0; j < length_second; j++) {
        result[j + i] = second[j];
        // cout << "item " << j << " " << result[j + i] << endl;
    }

    // Null-terminate the result string
    result[length_first + length_second] = '\0';
}

int main(){

char first[] = "I am ";
char second[] = {'i', 'r', 'o', 'n', 'm', 'a', 'n', '\0'}; 
char result[100];
append(first, 6, second, 8, result); 
cout << result;
return 0;
}