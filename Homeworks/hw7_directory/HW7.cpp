// EE 1301 
// HW 7A
// Talha Hamza
// HAMZA050


#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class houseData {
public:
    // Basic static data:
    // id,value,bedrooms,bathrooms,sqft,yr_built,zipcode
    long long int id = 0;
    int price = 0;
    int bedrooms = 0;
    int bathrooms = 0;
    int sqft = 0;
    int yr_built = 0;
    int zipcode = 0;

    houseData *nextZip = nullptr;

    void printShort();
    void printRecord();
};

void houseData::printShort() {
    cout << id << "," << zipcode << endl;
}

void houseData::printRecord() {
    cout << "Printing House Record:" << endl;
    cout << "ID:" << id << endl;
    cout << "Price:" << price << endl;
    cout << "Bedrooms:" << bedrooms << endl;
    cout << "Bathrooms:" << bathrooms << endl;
    cout << "Square Feet:" << sqft << endl;
    cout << "Year Built:" << yr_built << endl;
    cout << "Zipcode:" << zipcode << endl;
}

// Basic functions supporting House class, but not utilizing links
void ProcHeader(ifstream &file);
houseData* ReadRecord(ifstream &file);
void DelRecord(houseData *record);
void PrintAllHousesByZip(houseData* head);

// Advanced function creating and using links
// *** Function you need to define ***
houseData* AddRecord(houseData* listHead, houseData* houseToAdd);
houseData* FindNodeLessThanZip(houseData* head, int zipcode);
void DelAllRecords(houseData* listHead);
void PrintAveragePriceByZip(houseData* listHead);

int main(int argc, char *argv[]) {


    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    
    // The following line only handles data of size 10
    // houseData* initHouseData[10];
    // 1) TODO: Setup head of linked list
    // Comment the previous line and uncomment the following line to handle data of infinite size
    houseData* listHead = nullptr;

    
    ifstream fin;
    fin.open(argv[1]);

    // houseData* current = nullptr;
    // houseData* previous = nullptr;


    if(fin.is_open()) {
        ProcHeader(fin);        // Just dumps header

        int numRec = 0;

        while(!fin.eof()) {
            houseData* tempHouse = ReadRecord(fin);
            // current = tempHouse;
            if(tempHouse != nullptr) {
                // Insert Element into linked list
                listHead = AddRecord(listHead,tempHouse);
                numRec++;
                if (numRec % 1000 == 0){
                    cout << "Still working...num records processed: " << numRec << endl;
                }
            }
        }
        
        // PrintAllHousesByZip(listHead); //for testing purposes

        PrintAveragePriceByZip(listHead);

        DelAllRecords(listHead); // Delete entire linked list
        

        fin.close();
          
    } 
    else {
        cout << "File missing (or) unable to open!" << endl;
        return 1;
    }

    return 0;
}

void ProcHeader(ifstream &file) {
    int endOfHeader = 0;
    char curChar;

    while(!endOfHeader) {
        curChar = file.get();

        if (curChar == '\n') {
            //End of line found
            endOfHeader = 1;
        }
    }
}

houseData* ReadRecord(ifstream &file) {
    int endOfHeader = 0;
    int c = 0;

    int b = 0;

    long long int tempData[7] = {0};
    houseData* localHouseData = new houseData();
    string tempString = " ";

    while(!endOfHeader) {
        char curChar;
        
        //Get the next character in file
        curChar = file.get();
        
        //Check what the character is
        if (curChar == EOF) {
            return nullptr;
        } else if (curChar == '\n') {
            //Final symbol of row found: put in array and end loop
            tempString.append(1,'\0');
            tempData[c++] = stoll(tempString);
            endOfHeader = 1;
        } else if (curChar == ',') {
            //End of current symbol found: put in array
            tempString.append(1,'\0');
            tempData[c++] = stoll(tempString);
            tempString.clear();
        } else {
            // Append to array
            tempString.append(1,curChar);
            b++;
        }
    }

    localHouseData->id = tempData[0];
    localHouseData->price = tempData[1];
    localHouseData->bedrooms = tempData[2];
    localHouseData->bathrooms = tempData[3];
    localHouseData->sqft = tempData[4];
    localHouseData->yr_built = tempData[5];
    localHouseData->zipcode = tempData[6];

    return localHouseData;
}

void DelRecord(houseData *record) {
    delete record;
}

void PrintAllHousesByZip(houseData* head){
    cout << endl << "Printing List of All Houses by Zip:" << endl;
    houseData* current = head;
    while(current != nullptr) {
        current->printShort();
        current = current->nextZip;
    }
}

// Detailed explaination of the FindNodeLessThanZip function:
// The FindNodeLessThanZip function takes in a pointer to the head of the linked list and a target zipcode.
// The function first initializes the current node to the head of the list and the previous node to null.
// The function then loops through the linked list.
// If the target zipcode is greater than the current node's zipcode, then the function saves the current node as the previous node.
// The function then increments the current node to the next node.
// The function then returns the previous node.
        
houseData* FindNodeLessThanZip(houseData* head, int zipcode) {
    houseData* current = head; // Pointer to the current node during traversal.
    houseData* previous = nullptr; // Pointer to the node with the zipcode less than the target zipcode.

    while (current != nullptr) {
        if (zipcode > current->zipcode) { 
            previous = current;
            // If the incoming house has zip code greater than the checking node, save that node.
        }
        current = current->nextZip; // Increment current to the next element.
    }

    if (previous == nullptr){ // if no node has a zipcode less than the target, then the new node being added is the new head
        // cout << "No node has a zipcode less than the target zipcode. Returning head with Zip code: " << head->zipcode << endl;
        return nullptr;
    }

    // cout <<"Got the zipcode: "<< zipcode << " Returning Node with Zip code: " << previous->zipcode << endl;
    return previous;
}

// Detailed explanation of the AddRecord function:
// The AddRecord function takes in a pointer to the head of the linked list and a pointer to the house to be added to the list.
// The function first checks if the list is empty. If it is, then the new house becomes the head of the list.
// If the list is not empty, then the function finds the node with the nearest zip code less than the target zip code.
// If the previous node is null, then the new house becomes the head of the list.
// If the previous node is not null, then the function checks the entire existing list to see if the house is already in the list.
// If the house is already in the list, then the function returns the head of the list.
// If the house is not already in the list, then the function adds it to the list and returns the head of the list.


houseData* AddRecord(houseData* listHead, houseData* houseToAdd) {
  // Check if the list is empty
  if (listHead == nullptr) {
    // If empty, the new house becomes the head
    listHead = houseToAdd;
    return listHead;
  }

  // Find the node with the nearest zip code less than the target zip code
  houseData* previous = FindNodeLessThanZip(listHead, houseToAdd->zipcode);

    // If the previous node is null, then the new house becomes the head
    if (previous == nullptr) {
        houseToAdd->nextZip = listHead;
        return houseToAdd;
    }

    else{

    // Check the entire existing list to see if the house is already in the list
        houseData* current = listHead;
        while (current != nullptr) {
            if (houseToAdd->id == current->id) {
                // If the house is already in the list, return the head
                return listHead;
            }
            current = current->nextZip;
        }
        
        // If the house is not already in the list, add it to the list
        houseToAdd->nextZip = previous->nextZip;
        previous->nextZip = houseToAdd;
        return listHead;
    }
}

// Detailed explanation of the PrintAveragePriceByZip function:
// The PrintAveragePriceByZip function takes in a pointer to the head of the linked list.
// The function first initializes the sum and count variables to zero.
// The function then initializes the previous and current nodes to null.
// The function then loops through the linked list.
// If the previous node is null or the previous node's zip code is not equal to the current node's zip code, then the function calculates and prints the average price for the previous zip code.
// The function then resets the sum and count variables to zero.
// The function then updates the sum and count variables for the current zip code.
// The function then updates the previous and current nodes.
// The function then prints the average price for the last zip code.

void PrintAveragePriceByZip(houseData* head) {
    // Initialize variables
    long sum = 0;
    int count = 0;
    int average = 0;

    // Initialize previous and current nodes
    houseData* previous = nullptr;
    houseData* current = head;

    // Loop through the linked list
    while (current != nullptr) {
        // Check if zip code changed
        if (previous == nullptr || previous->zipcode != current->zipcode) {
            // Calculate and print average for previous zip code if not the first iteration
            if (previous != nullptr) {
                average = count == 0 ? 0 : sum / count; // Avoid division by zero
                cout << previous->zipcode << ":average price=" << average << endl;
                
                // Reset sum and count for new zip code
                sum = 0;
                count = 0;
            }
        }

        // Update sum and count for current zip code
        sum += current->price;
        count++;

        // Update previous and current nodes
        previous = current;
        current = current->nextZip;
    }

    // Print average for the last zip code
    if (previous != nullptr) {
        average = count == 0 ? 0 : sum / count; // Avoid division by zero
        cout << previous->zipcode << ":average price=" << average << endl;
    }
}

// Detailed explanation of the DelAllRecords function:
// The DelAllRecords function takes in a pointer to the head of the linked list.
// The function first initializes the current and next nodes to null.
// The function then loops through the linked list.
// The function then deletes the current node.
// The function then updates the current node to the next node.
// The function then sets the head to null.

void DelAllRecords(houseData *head) {
    
    houseData* current = head;
    houseData* next = nullptr;

    while (current != nullptr) {
        next = current->nextZip;
        delete current;
        current = next;
    }

    head = nullptr;

}
