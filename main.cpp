/**
 * @file main.cpp
 * @brief Main client program for the ShapeFile Parser.
 *
 * This program reads shape data from a file, validates it, and calculates
 * areas. It handles all file and data exceptions.
 *
 * @author [Gael Garcia Guzman]
 * @date [4/4/20206]
 * @version 1.0
 */

#include <iostream>
#include <fstream>      // For file I/O (ifstream)
#include <string>       // For std::string
#include <iomanip>      // For std::setprecision
#include <stdexcept>    // For std::invalid_argument

#include "GeometryUtils.h"
#include "Exceptions.h"
#include "FileUtils.h"      // NEW: Include the file utility header

using namespace std;

/**
 * @brief Main entry point for the ShapeFile Parser.
 *
 * This function contains all client logic. It handles:
 * 1. Prompting for an initial filename.
 * 2. Calling the file-opening utility.
 * 3. Reading the file line by line.
 * 4. Catching ParseException for unknown shape types.
 * 5. Catching std::invalid_argument for invalid shape dimensions.
 *
 * No other functions or classes should be defined in this file.
 */
int main() {
    // Set up clean console output for floating point numbers
    cout << fixed << setprecision(2);

    string filename;
    ifstream file;
    int lineNumber = 0;

    // --- 1. File Opening Logic ---
    cout << "Enter filename: ";
    cin >> filename;

    // Call the new utility function to handle the entire file-opening process.
    // We pass 'file' by reference to be opened, and 'filename' by value.
    try {
        openFileForReading(file, filename);
    } catch (const FileOpenException& e) {
        // If the file fails to open, print the error and stop the program
        cerr << "Critical Error: " << e.what() << endl;
        return 1;
    }


    // --- 2. File Parsing Logic ---
    cout << "--- Processing Shapes ---" << endl;
    string shapeType;

    // STUDENT TODO: Wrap the entire 'while' loop in a try...catch block
    // that catches a ParseException.

    // Read from the file one "word" at a time
    while (file >> shapeType) {
        lineNumber++;

        try {
            if (shapeType == "square") {
                double side;
                file >> side;

                double area = calculateArea(side);
                cout << "Line " << lineNumber << ": Square Area: " << area << endl;

            } else if (shapeType == "rectangle") {
                double length, width;
                file >> length >> width;

                double area = calculateArea(length, width);
                cout << "Line " << lineNumber << ": Rectangle Area: " << area << endl;

            } else if (shapeType == "circle") {
                double radius;
                file >> radius;

                double area = calculateCircleArea(radius);
                cout << "Line " << lineNumber << ": Circle Area: " << area << endl;

            } else {
                throw ParseException("Unknown shape type: " + shapeType);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Math Error (Line " << lineNumber << "): " << e.what() << endl;
        } catch (const ParseException& e) {
            cerr << "Parse Error (Line " << lineNumber << "): " << e.what() << endl;
        } catch (const exception& e) {
            // General catch-all for any other unexpected errors
            cerr << "Unexpected Error (Line " << lineNumber << "): " << e.what() << endl;
        }
    }


    // --- 3. Cleanup ---
    cout << "--- Processing Complete ---" << endl;
    file.close();
    
    return 0; // Successful execution
}
