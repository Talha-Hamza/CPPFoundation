# include <iostream>

using namespace std;

// BUILD NO REPEAT 
void noRepeat(char first[], char second[],  char result[])
{
int i = 0;
int j = 0;
    for (i = 0; first[i]!= '\0'; i++) {

        for (int k = 0; k<i; k++) {
            if (first[i] != first[k]) {
                result[i] = first[i];
            }
        }
    }

    for (j = 0; second[j]!= '\0'; j++) {
        for (int k = 0; k<i; k++) {
            if (first[i] != first[k]) {
                result[j + i] = second[j];;
            }
        }
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

char first[] = {'h', 'e', 'l', 'l', 'o', ' '};
char second[] = {'l', 'l', 'a', 'm', 'a'}; 
char result[100];
// append(first, second, result); 
cout << result;
return 0;
}