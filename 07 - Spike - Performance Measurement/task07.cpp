#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void single_measurement(int size)
{
    cout << "Single Function Measurement" << endl;
    int total;
    vector<int> v(size, 50);
    //start time
    auto start = steady_clock::now();

    //perform measureable action
    total = accumulate(v.begin(), v.end(), 0u); 

    //end time
    auto end = steady_clock::now();

    //calculate time
    duration<double> diff = end - start;

    //print time and time per int
    cout << "time: " << diff.count() << ", time/int: " << diff.count()/size << endl;
}

int main()
{
    single_measurement(100000);
}