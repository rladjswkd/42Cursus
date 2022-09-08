#include <iostream>
#include <ctime>
#include <iomanip>

int main(void){
    time_t  now = time(0);
    tm      *tmp = localtime(&now);

    std::cout << "["
        << tmp->tm_year + 1900
        << std::setw(2) << std::setfill('0') << tmp->tm_mon
        << std::setw(2) << std::setfill('0') << tmp->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << tmp->tm_hour
        << std::setw(2) << std::setfill('0') << tmp->tm_min
        << std::setw(2) << std::setfill('0') << tmp->tm_sec
        << "]";
    return (0);
}