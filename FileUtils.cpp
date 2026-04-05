//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Gael Garcia Guzman]
 * @date [April 4, 2026]
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
    try {
        file.open(initialFilename);

        // 1. If it fails, THROW the exception
        if (!file.is_open()) {
            throw FileOpenException("Error: File could not be opened: " + initialFilename);
        }

        // If we get here, the first file opened successfully
        cout << "File opened successfully: " << initialFilename << endl;

    } catch (const FileOpenException& e) {
        // 2. CATCH the exception and run the fallback logic
        cerr << e.what() << endl;

        string alternativeFilename;
        cout << "Enter alternative filename: ";
        cin >> alternativeFilename;

        file.open(alternativeFilename);

        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            // The starter code comment explicitly says to exit(1) here for this lab
            exit(1);
        }

        cout << "Alternative file opened successfully: " << alternativeFilename << endl;
    }
}