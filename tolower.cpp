#include <algorithm>
#include <cctype>
#include <string>
#include<iostream>

int main()
{
    std::string data = "";
    std::transform(data.begin(), data.end(),data.begin(), ::tolower);
    std::cout<<data;
}
