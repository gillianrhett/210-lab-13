// COMSC-210 | Lab 13 | Gillian Rhett

#include <iostream>
#include <fstream>
#include <vector>
#include <string> // for the filename and input validation
#include <algorithm> // for sort and find
#include <numeric> // for accumulate
using namespace std;

const string FILENAME = "infile.txt";
const int SIZE = 32;

int main() {
/* Get items from a file that stores 1 integer per line,
*  and store them in a vector for the program to work with.
*  This simulates a situation where we keep track of the
*  visitors a web page recieves each day.
*/
    ifstream inFile; // file object to get the items from
    // try to open the file
    try {
        inFile.open(FILENAME, ios::in);
        if(inFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    vector <int> visitors; // vector to store items from file
    // go back to the beginning so we can store the items in the vector
    inFile.clear();
    inFile.seekg(ios::beg);
    int i = 0;
    // read each int from the file and store it in the vector in the same order
    string tempInput; // for getting each line from the file
    int tempInt; // for validating input
    bool validInput = false;
    while(i < SIZE && !inFile.eof()) {
        inFile >> tempInput;
        try {
            tempInt = stoi(tempInput);
            visitors.push_back(tempInt);
        }
        catch(const exception& e) {
            visitors.push_back(0); // if it's not an int, put 0 instead
            inFile.clear();
        }        
        ++i;    
    }
    // now the ints from the file are in the vector

    // demonstration of vector functions
    cout << "Visitors per day" << endl;
    cout << "1. empty function: ";
    if(visitors.empty())
        cout << "vector is empty" << endl;
    else
        cout << "vector is not empty" << endl;
    cout << "2. size function: days of data collected = " << visitors.size() << endl;
    cout << "3. range-based for loop shows original vector contents:\n   ";
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "4. at function to show 4th item: " << visitors.at(3) << endl;
    cout << "5. [] to show 4th item: " << visitors[3] << endl;
    cout << "6. min_element function: min value is " << *min_element(visitors.begin(), visitors.end()) << endl;
    cout << "6. max_element function: max value is " << *max_element(visitors.begin(), visitors.end()) << endl;
    cout << "7. front function: first value is " << visitors.front() << endl;
    cout << "8. back function: last value is " << visitors.back() << endl;
    cout <<  "9. overloaded = operator to copy vector:" << endl;
    vector <int> copy_of_visitors = visitors;
    cout << "   copy_of_visitors vector: \n   ";
    for (int item : copy_of_visitors) cout << item << " ";
    cout << endl;
    cout << "10. address of visitors vector: " << visitors.data() << endl;
    cout << "11. address of visitors vector: " << copy_of_visitors.data() << endl;
    cout << "12. sort function:\n   ";
    sort(visitors.begin(), visitors.end());
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "13. find function:\n   ";
    cout << "searching for value 23 (appears 3 times in the vector)... ";
    vector<int>::iterator it; // iterator for pointing to elements in the vector
    it = find(visitors.begin(), visitors.end(), 23);
    if (it != visitors.end())
        cout << "found at position " << it - visitors.begin() << endl;
    else
        cout << "value not found" << endl;
    
        cout << "   searching for value 100 (is not in the vector)... ";
    it = find(visitors.begin(), visitors.end(), 100);
    if (it != visitors.end())
        cout << "found at position " << it - visitors.begin() << endl;
    else
        cout << "value not found" << endl;
    cout << "14. sort function to reverse: \n   ";
    sort(visitors.rbegin(), visitors.rend());
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "15. sort the first half: \n   ";
    sort(visitors.begin(), visitors.end() - SIZE / 2);
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "16. sum of items: " << accumulate(visitors.begin(), visitors.end(), 0);
    return 0;
}