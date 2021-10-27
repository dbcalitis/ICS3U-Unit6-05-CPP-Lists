// Copyright (c) 2021 D.B. Calitis All rights reserved
//
// Created by: Daria Bernice Calitis
// Created on: Oct 2021
// This program determines the average

#include <iostream>
#include <string>
#include <list>
#include <cmath>

float Mean(std::list<float> marks) {
    // This function calculates the average mark
    float average = 0;
    for (float mark : marks) {
        average += mark;
    }

    average = average / marks.size();
    /* https://stackoverflow.com/questions/
    7870003/rounding-a-double-number-up-to-the-tenths-place */
    average = round(10 * average) / 10;

    return average;
}

int main() {
    // This function is the main function
    std::list<float> userMarks;
    std::string userInputString;
    float userInput;

    std::cout << "Please enter 1 mark at a time. Enter -1 to end\n"
    << std::endl;

    // input
    while (true) {
        std::cout << "What is your mark? (as %): ";
        getline(std::cin, userInputString);
        try {
            // process & output
            userInput = std::stof(userInputString);
            if (userInput >= 1 && userInput <= 100) {
                userMarks.push_back(userInput);
            } else if (userInput == -1) {
                std::cout << "\nThe average is " << Mean(userMarks) << "%\n";
                break;
            } else {
                std::cout << "\nInvalid Input." << std::endl;
                break;
            }
        } catch (...) {
            std::cout << "\nInvalid Input." << std::endl;
            break;
        }
    }

    std::cout << "\nDone." << std::endl;
}
