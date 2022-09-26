/// @file pa15.cpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 07/29/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [The Use of Recursion] within an unsorted
/// in which [Recursion] is used to sort the array, find its size and sum
/// as well as use the List.hpp file (Handmade)
/// @note Time Taken to Develop Program is about 4 hours
/// between days 08/03 and 08/06 with Assitance of
/// [TA William]

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "List.hpp"
int main() {
    using namespace std;

    List<int> list { 10, 8, 6, 4, 2, 7, 1, 3, 5, 9 };

    cout << left;

    cout << setw(10) << "Forward:";
    list.print();
    cout << '\n';

    cout << setw(10) << "Reverse:";
    list.rprint();
    cout << '\n';

    cout << setw(10) << "Size:" << list.size() << '\n';
    cout << setw(10) << "Sum:" << list.sum() << '\n';
    
    try {
        cout << setw(10) << "Smallest:" << list.smallest() << '\n';
    } catch (std::logic_error& ex) {
        cerr << ex.what() << '\n';
    }

    list.push_back(7);
    list.push_back(7);
    cout << setw(10) << "Count(7):" << list.count(7) << '\n';

    list.sort();
    cout << setw(10) << "Sorted:";
    list.print();
    cout << endl;

    return 0;
}