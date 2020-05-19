#include"ExceptiaMea.h"

myException::myException(const char* error): std::logic_error(error) {}
