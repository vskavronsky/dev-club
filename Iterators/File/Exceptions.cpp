#include "Exceptions.hpp"

const char* ReadError::what() const noexcept {
    return "Error! Could not read the file.";
}
