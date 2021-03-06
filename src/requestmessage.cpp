#include "requestmessage.h"

#include <algorithm>
#include <iostream>
#include <vector>

std::string RequestMessage::first_line() const
{
    return method + " " + uri + " " + version + "\r\n";
}

std::string RequestMessage::header() const
{
    std::string header_string;
    for (auto iter = header_map.cbegin();
         iter != header_map.cend(); ++iter) {
        header_string += iter->first + ": " + iter->second + "\r\n";
    }
    return header_string;
}

std::string RequestMessage::to_string() const
{
    return first_line() + header() + "\r\n" + data;
}
