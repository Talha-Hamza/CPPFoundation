#include <iostream>
#include <string>
using namespace std;

class VHS{
    private:
    int ID;

    public: 
    string title;

    VHS(string incoming_title, int incoming_ID){
        ID = incoming_ID;
        title = incoming_title;
    }

    void printIDTitle();
};

void VHS::printIDTitle(){
    cout << ID << ":" << title;
}


int main() {
    
    VHS orsersVHS = VHS("Monty Python's Life of Brian",13);
    cout << "Prof. Orser Owns the VHS: ";
    orsersVHS.printIDTitle();

    return 0;
}
