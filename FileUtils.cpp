//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Gael Garcia Guzman]
 * @date [4/4/2026]
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream

using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream& file, std::string initialFilename) {
    // STUDENT TODO: Replace the following 'if' block with a
    // try...catch block that throws and catches a FileOpenException.

    file.open(initialFilename);
    // 1. Wrap the initial attempt in a try block
    try {
        file.open(initialFilename);

        // 2. Instead of an 'if', we check and THROW
        if (!file.is_open()) {
            throw FileOpenException("Error: File could not be opened: " + initialFilename);
        }

        // 3. This was your 'else' logic—it only runs if no exception is thrown
        cout << "File opened successfully: " << initialFilename << endl;

    }
    // 4. Create the catch block to handle the error
    catch (const FileOpenException& e) {
        // STUDENT TODO (Line 38): This retry logic belongs in the 'catch' block
        cerr << e.what() << endl;

        string alternativeFilename;
        cout << "Enter alternative filename: ";
        cin >> alternativeFilename;

        file.open(alternativeFilename);

        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            exit(1);
        }

        cout << "Alternative file opened successfully: " << alternativeFilename << endl;
    }
}