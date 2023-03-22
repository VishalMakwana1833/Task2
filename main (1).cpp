/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Function to register a new user
void registerUser() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;

    // Check if user already exists
    fs::path userFile = "users/" + username + ".txt";
    if (fs::exists(userFile)) {
        std::cout << "User already exists." << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    // Create user file and write access data
    std::ofstream file(userFile);
    file << username << "\n" << password << std::endl;

    std::cout << "User registered successfully." << std::endl;
}

// Function to log in an existing user
void loginUser() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;

    // Check if user exists
    fs::path userFile = "users/" + username + ".txt";
    if (!fs::exists(userFile)) {
        std::cout << "User does not exist." << std::endl;
        return;
    }

    // Read access data from user file
    std::ifstream file(userFile);
    std::string storedUsername, storedPassword;
    file >> storedUsername >> storedPassword;

    std::cout << "Enter password: ";
    std::cin >> password;

    // Check if password matches
    if (password != storedPassword) {
        std::cout << "Incorrect password." << std::endl;
        return;
    }

    std::cout << "User logged in successfully." << std::endl;
}

int main() {
    // Create users directory if it does not exist
    fs::create_directory("users");

    int choice;
    do {
        std::cout << "1. Register user" << std::endl;
        std::cout << "2. Login user" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
