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
        
        // PrintAllHousesByZip(listHead);
        // FindNodeLessThanZip(listHead, 98126);

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


houseData* AddRecord(houseData* listHead, houseData* houseToAdd) {
    
    if (listHead == nullptr){ // If linked list is empty, incoming house is the first head
    listHead = houseToAdd;
    return listHead;
    }
    
    else{
        houseData* current = listHead; // I am going to start going through the list at the very beginning
        houseData* previous = nullptr;
        if (houseToAdd->zipcode < listHead->zipcode){ // If incoming house has a smaller zipcode than head, it necomes new list head
        houseToAdd->nextZip = listHead;
        return houseToAdd;
        }
        else{
            if (houseToAdd->id == current->id){return listHead;} // check if incoming house is the duplicate of head 
            else{
            current = listHead->nextZip;
            previous = listHead;
            while(current!=nullptr) {
                if (houseToAdd->zipcode < current->zipcode){ // If the incoming house has zip code less that next house in search, place it there
                previous->nextZip = houseToAdd;
                houseToAdd->nextZip = current;
                return listHead;
                }
                else if (houseToAdd->id == current->id){return listHead;} // check if incoming house is the duplicate of the current element being checked 
                else{
                previous = current; // if not increment both previous and current to the next elements
                current = current->nextZip;
                }

            }
        previous->nextZip = houseToAdd; // reached end of list without a zipcode being less that incoming house's zip code. 
        houseToAdd->nextZip =nullptr; 
        return listHead;
            }
        }    
    }
}

houseData* FindNodeLessThanZip(houseData* head, int zipcode) {
    houseData* previous = nullptr; // Pointer to the previous node during traversal.
    houseData* current = head; // Pointer to the current node during traversal.
    houseData* node_holder = nullptr; // Pointer to the node with the zipcode less than the target zipcode.

    while (current != nullptr) {
        if (zipcode > current->zipcode) { 
            node_holder = current;
            // If the incoming house has zip code greater than the checking node, save that node.
        } else {
            // If not, increment both previous and current to the next elements.
            previous = current;
        }
        current = current->nextZip; // Increment current to the next element.
    }

    if (node_holder == nullptr){ // If no node was found with a zipcode less than the target zipcode, return head.
        cout << "No node with a zipcode less than " << zipcode << ". Returning head." << endl;
        node_holder = head;
    }
    cout << "Returning Node with Zip code: " << node_holder->zipcode << endl;
    return node_holder;
}


void PrintAveragePriceByZip(houseData* head) {
    int sum = 0; // Sum of all prices for a given zipcode.
    int count = 0; // Number of houses for a given zipcode.
    int average = 0; // Average price for a given zipcode.

    houseData* previous = head;      // Pointer to the previous node during traversal.
    houseData* current = head->nextZip; // Pointer to the current node during traversal.

    // Iterate through the linked list.
    while (current != nullptr) {
        // If the current node's zip code is less than the target zipcode,
        // update node_holder to the current node.
        if (previous->zipcode == current->zipcode) { // If the current node's zip code is equal to the previous node's zip code,
            sum = sum + previous->price; // add the price of the previous node to the sum.
            count = count + 1; 
            previous = current;
            current = current->nextZip; // Increment current to the next element.
        }
        else{ // If the current node's zip code is not equal to the previous node's zip code, 
             // print the average price for the previous node's zip code and reset the sum and count to move on to the next zipcode.
            sum = sum + previous->price;
            count = count + 1;
            average = sum/count;
            cout << previous->zipcode << ":average price=" << average << endl;
            previous = current;
            current = current->nextZip;
            sum = 0;
            count = 0;
        }
    }
    // Print the average price for the last zipcode.
    sum = sum + previous->price;
    count = count + 1;
    average = sum/count;
    cout << previous->zipcode << ":average price=" << average << endl;
    sum = 0;    
    count = 0;
    }

// Function to deallocate entire linked list
void DelAllRecords(houseData *head) {
    // 7) TODO: Implement this function
    // Delete all records in the linked list and free the memory
    houseData* current = head;
    houseData* next = nullptr;
    while (current != nullptr) {
        next = current->nextZip;
        delete current;
        current = next;
    }
    head = nullptr;

}
