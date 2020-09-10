/*
// file: DorianBenitez_HW1.cpp
// author: Dorian Benitez (drb160130)
// date: 1/26/2020
// purpose: CS 4375.001 - Homework #1
// 
// This .cpp file is for Homework 1 of Intro to Machine Learning with instructor Karen Mazidi. This program will read a two-column csv 
// file into two vectors. The sum, mean, median, range, covariance, and correlation of the vectors will be calculated and displayed.
// 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// ------ STEP 2a ------ //
// Function to find the sum of the two vectors
void findSum(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {
    float sum1 = 0;
    float sum2 = 0;

    for(int i = 0; i < rm_vec.size(); i++){
        sum1 += rm_vec.at(i);
        sum2 += medv_vec.at(i);
    }
    cout << "----------" << '\n' << "rm sum: " << sum1 << endl;
    cout << "medv sum: " << sum2 << endl;
}

// ------ STEP 2b ------ //
// Function to find the mean of the two vectors
void findMean(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {
    float sum1 = 0;
    float sum2 = 0;
    float mean1 = 0;
    float mean2 = 0;

    for(int i = 0; i < rm_vec.size(); i++){
        sum1 += rm_vec.at(i);
        sum2 += medv_vec.at(i);
    }

    cout << "----------" << '\n' << "rm mean: " << sum1 / rm_vec.size() << endl;
    cout << "medv mean: " << sum2 / medv_vec.size() << endl;
}

// ------ STEP 2c ------ //
// Function to find the median of the two vectors
void findMedian(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {

    int rm_size = rm_vec.size();
    int medv_size = medv_vec.size();

    if (rm_size % 2 == 0)
    {
      cout << "----------" << '\n' << "rm median: " << (rm_vec[rm_size / 2 - 1] + rm_vec[rm_size / 2]) / 2 << endl;
    }
    else 
    {
      cout << "----------" << '\n' << "rm median: "<< rm_vec[rm_size / 2] << endl;
    }

    if (medv_size % 2 == 0)
    {
      cout << "medv median: " << (medv_vec[medv_size / 2 - 1] + medv_vec[medv_size / 2]) / 2 << endl;
    }
    else 
    {
      cout << "medv median: " << medv_vec[medv_size / 2] << endl;
    }
}

// ------ STEP 2d ------ //
// Function to find the range of the two vectors
void findRange(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {
    float range1 = 0;
    float range2 = 0;

    // Subtracts the last value from the first value of the vector to obtain the range
    range1 = rm_vec.back() - rm_vec.front();
    range2 = medv_vec.back() - medv_vec.front();

    cout << "----------" << '\n' << "rm range: " << range1 << "  (" << rm_vec.front() << " " << rm_vec.back() << ")" << endl;
    cout << "medv range: " << range2 << "  (" << medv_vec.front() << " " << medv_vec.back() << ")" << endl;
}

// ------ STEP 2e ------ //
// Function to find the covariance of the two vectors
void covariance(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {
    float sum1 = 0;
    float sum2 = 0;
    float total = 0;
    float mean1 = 0;
    float mean2 = 0;
    
    // finds the sum of rm and medv
    for(int i = 0; i < rm_vec.size(); i++){
        sum1 += rm_vec.at(i);   
        sum2 += medv_vec.at(i);
    }

    // finds mean of rm and medv
    mean1 = sum1 / rm_vec.size();   // rm mean
    mean2 = sum2 / medv_vec.size();   // medv mean

    // Calculates the final covariance value
    for(int k = 0; k < rm_vec.size(); k++) 
        total = total + (rm_vec.at(k) - mean1) * (medv_vec.at(k) - mean2); 

    cout << "----------" << '\n' << "Covariance: " << total / (rm_vec.size() -1) << endl; 
}

// ------ STEP 2f ------ //
// Function to find the correlation of the two vectors
void correlation(std::vector<float> const &rm_vec, std::vector<float> const &medv_vec) {
    float sum1 = 0;
    float sum2 = 0;
    float sum_XY = 0;
    float squareSum_X = 0;
    float squareSum_Y = 0;
    float corr;

    for (int i = 0; i < rm_vec.size(); i++) 
    { 
        sum1 += rm_vec.at(i);
        sum2 += medv_vec.at(i);
  
        // sum of the vectors 
        sum_XY += rm_vec.at(i) * medv_vec.at(i); 
  
        // sum of square of array elements. 
        squareSum_X += rm_vec.at(i) * rm_vec.at(i); 
        squareSum_Y += medv_vec.at(i) * medv_vec.at(i); 
    } 

    // Formula for deriving correlation value
    corr = (rm_vec.size() * sum_XY - sum1 * sum2) / sqrt((rm_vec.size() * squareSum_X - sum1 * sum1) * (medv_vec.size() * squareSum_Y - sum2 * sum2));
    cout << "----------" << '\n' << "Correlation: " << corr << endl << "----------" << '\n';
}


int main()
{
    ifstream ip("Boston.csv");   // This calls the csv file 
    string rm, medv;
    string dummy;                // This  will be used to omit the first row of text from the csv document
    double mean, median, range;

    if(!ip.good()){
        cout << "FILE ERROR: " << '\n';
        return 0;
    }

    vector<float> rm_vec;     // vector to hold the rm values
    vector<float> medv_vec;   // vector to hold the medv values

                        
    // ------ STEP 1 ------ //

    // Skips reading the first line of the CSV file
    getline(ip, dummy, '\n'); 

    // While content is being read from CSV file, this executes
    while(ip.good()) { 
        
        // Gets each value from the CSV file that is seperated by a comma or space
        getline(ip, rm, ',');
        getline(ip, medv, '\n');

        // Converts the string values to float values
        float rm_val = std::stof(rm); 
        float medv_val = std::stof(medv);

        // Pushes the float values into their desginated vectors
        rm_vec.push_back(rm_val);
        medv_vec.push_back(medv_val);
    }
    
    // Sorts the vectors is ascending order
    sort(rm_vec.begin(), rm_vec.end());
    sort(medv_vec.begin(), medv_vec.end());

    // ------ STEP 3 ------ //
    // All of the function calls
    findSum(rm_vec, medv_vec);
    findMean(rm_vec, medv_vec);
    findMedian(rm_vec, medv_vec);
    findRange(rm_vec, medv_vec);
    covariance(rm_vec, medv_vec);
    correlation(rm_vec, medv_vec);

    ip.close();   // Closes the csv file being read
}