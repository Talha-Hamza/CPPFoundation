// TAR File check
// Date: September 20, 2023
// Written by: Nishanth Somashekara Murthy
// Email: somas026@umn.edu
// EE1301 - Fall 2023

//================== USAGE =============================================
// g++ tarfile_check.cpp -o tarfile_check.exe           (MacOS use clang++ instead of g++)
//
// ./tarfile_check.exe somas026 hw1                     (Linux/MacOS)
//               (or)
// .\tarfile_check.exe somas026 hw1                     (Windows)
//======================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
namespace fs = std::filesystem;

const string TAR_COMMAND = "tar -xzf ";

const string TARGET_FILES[] = {"A.cpp", "B.cpp", "C.cpp"};

bool checkTarball(int homeworkNumber, const string& tarballPath, const string& internetID) {
    
    const string targetDirectory = "hw" + to_string(homeworkNumber) + "_directory";
    const string testDirectory = "test_" + targetDirectory;

    // Check if the tarball file exists
    if (!fs::exists(tarballPath)) {
        cout << tarballPath << " file doesn't exist" << endl;
        return false;
    }

    // Extract the tarball
    string tar_command = TAR_COMMAND + tarballPath;
    int tar_result = system(tar_command.c_str());
    if (tar_result != 0) {
        cout << "Error extracting tarball" << endl;
        return false;
    }

    // Check if the target directory exists within the extracted tarball
    if (!fs::exists(targetDirectory)) {
        cout << "Directory '" << targetDirectory << "' not found in the tarball." << endl;
        return false;
    }
    cout << "Checking for Required Files....." << endl;
    Sleep(5000);

    // Check if the target files exist within "hw<#>_directory"
    int hwFiles = 0;
    if(homeworkNumber == 1 || homeworkNumber == 6){ // change to hw_num
        hwFiles = 2; // number of files
    }
    else{
        hwFiles = 3;
    }

    bool flag = true;
    // Check if the target files exist within the target directory
    for (int i = 0; i < hwFiles; i++) {
        
        const string targetFile = internetID + "_hw" + to_string(homeworkNumber) + TARGET_FILES[i];
        if (!fs::exists(targetDirectory + "/" + targetFile)) {
            cout << "File '" + targetFile + "' not found in the tarball." << endl;
            flag = false;
        }
    }

    // Clean up: remove the extracted directory
    int cleanup_result;
    
    // Platform-specific cleanup commands
    // #ifdef _WIN32 // Windows
    // cleanup_result = system(("rmdir /s /q " + targetDirectory).c_str());
    // #else // Unix/Linux
    // cleanup_result = system(("rm -rf " + targetDirectory).c_str());
    // #endif

    // Platform-specific cleanup commands
  if (fs::exists(targetDirectory)) {
    // Attempt to remove the directory
    #ifdef _WIN32
    Sleep(5000);
    cleanup_result = system(("rmdir /s /q " + targetDirectory).c_str());
    #else
    cleanup_result = system(("rm -rf " + targetDirectory).c_str());
    #endif
    if (cleanup_result != 0) {
        cerr << "Error cleaning up extracted files. Cleanup result: " << cleanup_result << endl;
        return false;
    }
}
    // If all checks pass, indicate success
    if(!flag)
        return false;
    else
        return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <internetID> <homeworkInfo>" << endl;
        return 1;
    }
    
    int homeworkNumber = 0;

    string internetID = argv[1];
    string homeWork = argv[2];

    string tarballPath = homeWork + "_" + internetID + ".tgz";  // Construct the tarball filename

    // Extract the numeric part of the string & Convert the numeric part to an integer
     char lastCharacter = homeWork.back();

    try {
        homeworkNumber = stoi(string(1, lastCharacter));
    } catch (const std::invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    } catch (const std::out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
        return 1;
    }

    if (checkTarball(homeworkNumber, tarballPath, internetID)) {
        cout << "SUCCESS !! Tarball '" << tarballPath << "' contains the required directory and files." << endl;
        return 0;
    } else {
        cout << "FAILED !! Check the Submission Requirements in the Homework Manual." << endl;
        return 1;
    }
}
