#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: could not open input file." << endl;
        return 1;
    }

    // Read in the list of integers
    vector<int> list;
    int value;
    while (inputFile >> value)
    {
        list.push_back(value);
    }

    // Close the input file
    inputFile.close();

    // Sort the list using the bubble sort algorithm
    int size = list.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    // Open the output file
    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cerr << "Error: could not open output file." << endl;
        return 1;
    }

    // Write the sorted list back to the file
    for (int i = 0; i < size; i++)
    {
        outputFile << list[i] << " ";
    }

    // Close the output file
    outputFile.close();

    // Exit the program
    return 0;
}
