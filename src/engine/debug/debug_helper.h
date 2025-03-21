#include <iostream>
#include <sstream>
#include <unordered_map>

template <typename T>
std::string ToString(const T &value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template <typename... Args>
void DEBUG(Args &&...args)
{
    std::ostringstream oss;
    ((oss << ToString(std::forward<Args>(args))), ...);
    std::cout << "[DEBUG] " << oss.str() << std::endl;
}