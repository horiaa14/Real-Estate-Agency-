#ifndef EXCEPTIAMEA_H_INCLUDED
#define EXCEPTIAMEA_H_INCLUDED
#include<stdexcept>
#pragma once

class myException : public std::logic_error {
public:
    myException(const char* error);
};

#endif // EXCEPTIAMEA_H_INCLUDED
