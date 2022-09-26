/// @file List.hpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 08/03/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [The Use of Recursion]
/// @note Time Taken to Develop Program is about 4 hours
/// between days 08/03 and 08/05 with Assitance of
/// [TA William]

#ifndef LIST_HPP
#define LIST_HPP

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <cassert>


template <class T>
class List {
private:
    struct Node {
        Node(const T& item = T{}, Node *node = nullptr)
            : info(item), link(node) {}
        T     info;
        Node *link;
    };

public:
    // Defualt Constructor
    List() = default;
    // Copy Constructor
    List(const List&) = delete;
    // Assignemnt Operator Overload
    List& operator=(const List&) = delete;
    // Destructor
    ~List() {
        clear(head);
    }
    // Number of Items in List
    size_t size() const {
        return size(head);
    }
    // Numbers of items equal to target in the list
    size_t count(const T& target) const {
        return count(head, target);
    }
    // Sum of all numbers in List
    T sum() const {
        return sum(head);
    }
    // Prints the List in Foward Motion
    void print() const {
        print(head);
    }
    // Prints the List in Backwards Motion
    void rprint() const {
        rprint(head);
    }
    // Sorts the List in Ascending Order
    void sort() {
        sort(head);
    }
    // Creates a List with { } containing it
    List(const std::initializer_list<T>& ilist) {
        for (auto item : ilist) {
            push_back(item);
        }
    }
    // Places new node (item) at the end of the list, similar to queue
    void push_back(const T& item) {
        Node *temp = new Node(item, nullptr);  // Temp Variable to place at end

        if (tail != nullptr) {
            tail -> link = temp;
        } else {
            head = temp;
        }

        tail = temp;
    }
    // Returns the Smallest Item in the List
    T& smallest() const {
        if (head == nullptr) {
            throw std::logic_error("There is No List available");
        } else {
            return smallest(head);
        }
    }

private:
    // recursive functions
    // The size() function returns the number of items in the list.
    size_t size(const Node *node) const {
        if (node == nullptr) {
            return 0;
        } else if (node == tail) {
            return 1;
        } else {
            return 1 + size(node -> link);
        }
    }

    // The count() function returns the number of items equal to the target.
    size_t count(const Node *node, const T& target) const {
        if (node == nullptr) {
            return 0;
        } else if (node -> info == target) {
            return 1 + count(node -> link, target);
        } else {
            return 0 + count(node ->link, target);
        }
    }


    // The sum() function returns the arithmetic sum of all items.
    T sum(const Node *node) const {
        if (node == nullptr) {
            return 0;
        } else if (node == tail) {
            return node->info;
        } else {
            return node -> info + sum(node -> link);
        }
    }

    // The print() function prints the list in forward order.
    void print(const Node *node) const {
        if (node != nullptr && node == tail) {
            std::cout << node -> info << " ";
        } else {
            std::cout << node -> info << " ";
            print(node-> link);
        }
    }


    // The rprint() function prints the list in reverse order.
    void rprint(const Node *node) const {
        if (node != nullptr && node == tail) {
            std::cout << node -> info << " ";

        } else {
            rprint(node-> link);
            std::cout << node -> info << " ";
        }
    }

    // smallest() function returns the smallest element in the list.
    T& smallest(Node *node) const {
        if (node == tail) {
            return node ->info;
        } else {
            if (node -> info < smallest(node -> link)) {
                return node-> info;
            } else {
                return smallest(node-> link);
            }
        }
    }

    // sort() function sorts the list in ascending order using the sort algor
    void sort(Node *node) {
        if (node == nullptr) {
            return;
        } else if (node != nullptr && node == tail) {
            T tmp = smallest(node);  // A variable to Hold the the Smallest
            smallest(node) = node ->info;
            node->info = tmp;
        } else {
            T tmp = smallest(node);
            smallest(node) = node ->info;
            node->info = tmp;
            sort(node -> link);
        }
    }

    // The clear() function deletes all memory allocated for the list.
    void clear(const Node *node) noexcept {
        if (node != nullptr) {
            if (node -> link != nullptr) {
                clear(node->link);
                delete node;
            } else {
                delete node;
            }
        } else {
            return;
        }
    }

    Node *head {};  ///< Pointer to the first item.
    Node *tail {};  ///< Pointer to the last item.
};

#endif