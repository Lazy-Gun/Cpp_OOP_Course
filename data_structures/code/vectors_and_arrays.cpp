#include <iostream>
#include <vector>
using namespace std;

int main()
{
// Determine size
    vector<int> numbers(3);
    int digits[3];

    cout << numbers.size() << endl;
    cout << sizeof(digits) / sizeof(digits[0]) << endl;

// Adding Vector Elements

    vector<int> numbers(0); //vector with no elements
    numbers.push_back(50); //add 50 as an element to end of vector

    cout << numbers.at(0) << endl; //50 becomes first and only element

// Add element to specfic index

    vector<int> numbers(2);
    numbers.insert(numbers.begin()+1, 50); //add 50 to index 1
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl;
    cout << numbers.at(2) << endl;

    numbers.insert(numbers.begin()+1, 100); //add 100 to index 1
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl;
    cout << numbers.at(2) << endl; //50 now becomes index 2 

// Remove vector elements

    vector<int> numbers(0); //empty vector
    numbers.push_back(50); //add 50 to vector
    numbers.push_back(100); //add 100 to vector
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl << endl;

    numbers.pop_back(); //remove last element vector
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl; //100 has been deleted completely

// Remove element form specific index

    vector<int> numbers(0); //empty vector
    numbers.push_back(50); //add 50 to vector
    numbers.push_back(100); //add 100 to vector
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl << endl;

    numbers.erase(numbers.begin()); //removes 50
    cout << numbers.at(0) << endl;
    cout << numbers.at(1) << endl; //no longer exists

// Modifying vector elements
// To modify vector elements, use the at() method to specify the index number and then assign a new element to it.

    vector<string> contact(0);
    contact.push_back("First name");
    contact.push_back("Last name");
    contact.push_back("Phone number");
    cout << contact.at(0) << " " 
        << contact.at(1) << " " 
        << contact.at(2) << endl;

    contact.at(2) = "Email"; //change element at index 2 to "Email"
    cout << contact.at(0) << " " 
        << contact.at(1) << " " 
        << contact.at(2) << endl;

// Iterating Vector Elements

//iterating through an array
    int grades[] = {85, 95, 48, 100, 92};

    for (int i = 0; i < sizeof(grades)/sizeof(grades[0]); i++) {
    cout << grades[i] << endl;
    }

//iterating through an vector
    vector<int> grades_vec {85, 95, 48, 100, 92};

    for (int i = 0; i < grades_vec.size(); i++) {
    cout << grades_vec.at(i) << endl;
    }

    //iterating a vector with Enhanced For Loop


    for (auto i : grades_vec) { //can use int or auto for iterating variable!
    cout << i << endl;
}

 // Searching for a Particular Element

    vector<string> cars(0);
    string Camry = "A Camry is not available."; //default string value

    cars.push_back("Corolla");
    cars.push_back("Camry");
    cars.push_back("Prius");
    cars.push_back("RAV4");
    cars.push_back("Highlander");

    for (auto a : cars) { //enhanced for loop
    if (a == "Camry") { //if "Camry" is in vector
        Camry = "A Camry is available."; //variable changes if "Camry" exists
    }
    }
        
    cout << Camry << endl; //print whether Camry exists or not

//Finding a Minimum or Maximum Value

    vector<int> grades(0);
    grades.push_back(72);
    grades.push_back(84);
    grades.push_back(63);
    grades.push_back(55);
    grades.push_back(98);

    int min = grades.at(0); //set min to the first element in the array

    for (auto a : grades) { //enhanced for loop
    if (a < min) { //if element is less than min
        min = a; //set min to element that is less
    }
    }
    //elements are not modified so enhanced for loop can be used

    cout << "The lowest grade is " << min << endl; //print lowest element

    return 0;

}