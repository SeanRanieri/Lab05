#include <iostream>
#include <vector>
#include <chrono>
#include "StringData.h"

using namespace std;

int linearSearch(vector<string> container, string element)
{
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }

    return -1;
}

int binarySearch(vector<string> container, string element)
{
    int low = 0;
    int high = container.size() - 1;
    int mid = (low + high) / 2;

    while (low != high) {
        if (container[mid] == element) {
            return mid;
        } else if (container[mid] < element){
            low = mid + 1;
        } else {
            if (mid - 1 != 0) {
                high = mid - 1;
            } else {
                high = mid;
            }
        }

        mid = (low + high) / 2;
    }

    return -1;
}

int main()
{
    vector<string> data = getStringData();

    // testing linear and binary search for string "not_here"
    cout << "Testing for string \"not_here\"\n";
    auto start = chrono::system_clock::now();
    int res = linearSearch(data, "not_here");
    auto end = chrono::system_clock::now();
    cout << "Linear returned " << res << "in " << (end-start).count() << " seconds.\n";

    start = chrono::system_clock::now();
    res = binarySearch(data, "not_here");
    end = chrono::system_clock::now();
    cout << "Binary returned " << res << "in " << (end-start).count() << " seconds.\n";

    // testing linear and binary search for string "aaaaa"
    cout << "Testing for string \"aaaaa\"\n";
    start = chrono::system_clock::now();
    res = linearSearch(data, "aaaaa");
    end = chrono::system_clock::now();
    cout << "Linear returned " << res << "in " <<  (end-start).count() << " seconds.\n";

    start = chrono::system_clock::now();
    res = binarySearch(data, "aaaaa");
    end = chrono::system_clock::now();
    cout << "Binary returned " << res << "in " << (end-start).count() << " seconds.\n";
}