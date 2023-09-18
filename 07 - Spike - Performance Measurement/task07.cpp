#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void single_func(int size)
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
    auto _dur = duration_cast<nanoseconds>( end - start ).count();

    //print time and time per int
    cout << "time: " << _dur << "ns, time/int: " << _dur/size << "ns/int" << endl;
    cout << endl;
}

void multiple_func(int size, int steps)
{
    cout << "Multiple Function Measurement" << endl;
    int total;
    vector<int> v(size, 50);

    //start time
    auto start = steady_clock::now();

    //loop
    for (auto i = 1; i <= steps; i++){
        //perform action
        total = accumulate(v.begin(), v.end(), 0u); 

        //end time
        auto end = steady_clock::now();

        //calculate time
        auto _dur = duration_cast<nanoseconds>( end - start ).count();

        //print time and time per int
        cout << "Execution: " << i;
        cout << ", Time: " << _dur << "ns, time/int: " << _dur/size << "ns/int" << endl;
    }
    cout << endl;
}

void exponential_rampup_test()
{
    cout << "Exponential Ramp-up Test" << endl;
    int total;

    for (auto size = 1ull; size < 1000000000ull; size *= 100) 
    {
        //start time
        auto start = steady_clock::now();
        //perform action
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u); 
        //get end time
        auto end = steady_clock::now();
        //calculate time
        duration<double> diff = end - start;
        auto _dur = duration_cast<nanoseconds>( end - start ).count();
        cout << " - size: " << size << ", time: " << _dur << " ns";
        cout << ", time/int: " << _dur / size << "ns/int" << endl; 
    }  
    cout << endl;
}

void linear_rampup_test()
{
    cout << "Linear Ramp-up Test" << endl;
    int total;
    for (auto size = 1; size <= 5; size += 1) 
    {
        int vec_size = size * 10000;
        //get start time
        auto start = steady_clock::now();
        //perform action
        vector<int> v(vec_size, 42);
        total = accumulate(v.begin(), v.end(), 0u); 
        //get end time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        auto _dur = duration_cast<nanoseconds>( end - start ).count();
        cout << " - size: " << vec_size << ", time: " << _dur << " ns";
        cout << ", time/int: " << _dur / vec_size << "ns/int" << endl;
    }  
    cout << endl;
}

void exponential_rampdown()
{
cout << "Exponential Ramp-down Test" << endl;
    int total;

    for (auto size = 100000000ull; size >= 1ull ; size /= 100) 
    {
        //start time
        auto start = steady_clock::now();
        //perform action
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u); 
        //get end time
        auto end = steady_clock::now();
        //calculate time
        duration<double> diff = end - start;
        auto _dur = duration_cast<nanoseconds>( end - start ).count();
        cout << " - size: " << size << ", time: " << _dur << " ns";
        cout << ", time/int: " << _dur / size << "ns/int" << endl; 
    }  
    cout << endl;
}

void linear_rampdown_test()
{
    cout << "Linear Ramp-down Test" << endl;
    int total;
    for (auto size = 5; size >= 1; size -= 1) 
    {
        int vec_size = size * 10000;
        //get start time
        auto start = steady_clock::now();
        //perform action
        vector<int> v(vec_size, 42);
        total = accumulate(v.begin(), v.end(), 0u); 
        //get end time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        auto _dur = duration_cast<nanoseconds>( end - start ).count();
        cout << " - size: " << vec_size << ", time: " << _dur << " ns";
        cout << ", time/int: " << _dur / vec_size << "ns/int" << endl;
    }  
    cout << endl;
}

void count_char_using_find_first_of(string s, char delim)
{
    int counter = 0;

    auto start = steady_clock::now();
    auto pos = s.find_first_of(delim);
    while ( (pos = s.find_first_of(delim, pos)) != string::npos)
    {
        counter++;
        pos++;
    }

    auto end = steady_clock::now();
    auto _dur = duration_cast<nanoseconds>( end - start ).count();
    cout << "Count Characters using Find First of" << endl;
    cout << "result: " << counter << ", Time: " << _dur << " ns" << endl;
    cout << endl;
}

void count_char_using_count(string s, char delim)
{
    auto start = steady_clock::now();

    auto counter = count(s.begin(), s.end(), delim);

    auto end = steady_clock::now();
    auto _dur = duration_cast<nanoseconds>( end - start ).count();
    cout << "Count Characters using Count" << endl;
    cout << "result: " << counter << ", Time: " << _dur << " ns" << endl;
    cout << endl;
}

int main()
{
    single_func(100000);
    multiple_func(100000, 10);
    exponential_rampup_test();
    exponential_rampdown();
    linear_rampup_test();
    linear_rampdown_test();
 
    string s1 = "This is a really simple string but it will do for testing.";
    count_char_using_find_first_of(s1, 's');
    count_char_using_count(s1, 's');

}