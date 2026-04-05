# 🔬 C++ Lab: Headers, Overloading, and Exception Handling
> **Course:** CMPSC 272
> **Instructor:** Professor Vaughn

## Lab Overview
---
This lab is a comprehensive exercise combining several critical C++ concepts. You will build a robust program that parses a data file, processes its contents using a custom utility library, and gracefully handles all potential runtime errors.

You will implement a clean, multi-file project, separating interface from implementation. This includes creating a **utility library** with **overloaded functions** (for geometry calculations), a separate library for **file operations**, and a set of **custom exception classes**. Your `main()` function will act as the client, coordinating these components and implementing `try...catch` blocks to manage errors like file-not-found, bad data, and invalid parameters.

### Learning Objectives
* Separate C++ code into **header (.h)** and **implementation (.cpp)** files.
* Design and implement **overloaded functions**.
* Implement **`try`**, **`catch`**, and **`throw`** for structured error handling.
* Create and use **custom exception classes** that inherit from `std::exception`.
* Read data from files using `std::ifstream`.
* Validate data and manage runtime errors without crashing.
* Understand the full compile/link process for a multi-file project.

## Programming Challenge: Shape File Parser
---
You are to write a C++ program that reads shape descriptions from a text file, calculates their area and perimeter, and prints the results. The program must be robust and handle all potential errors (missing file, bad data, invalid values) using custom exceptions.

The starter repository you will clone contains an **unfinished project** built with **five (5) sets of files**. Your task is to **complete the logic** in each file as described below:

1.  **`Exceptions.h` / `Exceptions.cpp`**: Defines your custom exception classes.
2.  **`FileUtils.h` / `FileUtils.cpp`**: Contains file-handling logic.
3.  **`GeometryUtils.h` / `GeometryUtils.cpp`**: Contains geometry calculation logic.
4.  **`main.cpp`**: The client code. Contains **only** the `main()` function.

### Part 1: Custom Exception Classes (`Exceptions.h / .cpp`)
Complete the two custom exception classes, which inherit from `std::exception`. You must implement the `what()` method for both.

* **`FileOpenException(const std::string& msg)`**: To be thrown if a file cannot be opened.
* **`ParseException(const std::string& msg)`**: To be thrown if an unknown shape name is encountered in the file.

### Part 2: File Utility (`FileUtils.h / .cpp`)
Complete the file handling logic in the `FileUtils.cpp` file.

* **`void openFileForReading(std::ifstream& file, const std::string& filename)`**
    * This function attempts to open the file.
    * Find the `// TODO:` comment. If `file.is_open()` is false, you must **`throw FileOpenException`**.

### Part 3: Geometry Library (`GeometryUtils.h / .cpp`)
Complete the geometry logic in `GeometryUtils.cpp`. The header file is already complete and uses **function overloading**.

* Implement the logic for all 6 geometry functions.
* **Error Handling:** Inside each function, find the `// TODO:` comment. You must validate the parameters. If any dimension (side, length, width, radius) is **zero or negative**, the function must **`throw std::invalid_argument`** (from `<stdexcept>`).

### Part 4: The Client (`main.cpp`)
Complete the `main()` function by adding all the required exception handling logic.

* Find the first `// TODO:` and wrap the call to `openFileForReading` in a **`try...catch`** block.
    * You must catch **`FileOpenException`** and print a user-friendly error.
* Find the second `// TODO:` and wrap the entire `if/else if/else` block in a **nested `try...catch`** block.
* Your `catch` block must handle:
    * **`ParseException`**: Thrown if `shape` is not "square", "rectangle", or "circle".
    * **`std::invalid_argument`**: Thrown by the `GeometryUtils` functions for bad dimensions.
    * **`std::exception`**: A general catch-all for any other unexpected errors.
* Find the `// TODO:` in the `else` block and **`throw ParseException`** for unknown shapes.
* When an error is caught for a line, print the error and continue to the next line.

### Part 5: Starter Code
A starter repository with all 7 files is provided. Your task is to **clone** this repository and complete the logic in the designated `// TODO:` sections.

Use the following command to clone the starter project:
```bash
git clone [[https://github.com/ProfessorVaughn/cmpsc272-exception-lab-starter]
