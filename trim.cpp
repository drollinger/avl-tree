/*****************************************************
 * This code was written by jotik and is not my work
 * Source: 
 *   https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
 *****************************************************/

#include <algorithm> 
#include <cctype>
#include <locale>
#include <string>
#include "trim.h"

using namespace std;

// trim from start (in place)
void ltrim(string &s) 
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
void rtrim(string &s) 
{
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(string &s) 
{
    ltrim(s);
    rtrim(s);
}
