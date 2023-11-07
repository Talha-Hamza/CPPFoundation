# include <iostream>

using namespace std;

// BUILD NO REPEAT 
void append(char first[], char second[],  char result[])
{
int i = 0;
int j = 0;
    for (i = 0; first[i]!= '\0'; i++) {
        result[i] = first[i];
        // cout << "item " << i << " " << result[i] << endl;
    }

    for (j = 0; second[j]!= '\0'; j++) {
        result[j + i] = second[j];
        // cout << "item " << j << " " << result[j + i] << endl;
    }

    // Null-terminate the result string
    result[i+j+1] = '\0';

    // while (*first != '\0') {
    //     *result = *first;
    //     first++;
    //     result++;
    // }
    // while (*second != '\0') {
    //     *result = *second;
    //     second++;
    //     result++;
    // }
    // *result = '\0';

}

int main(){

char first[] = "I am ";
char second[] = {'i', 'r', 'o', 'n', 'm', 'a', 'n', '\0'}; 
char result[100];
append(first, second, result); 
cout << result;
return 0;
}