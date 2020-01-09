#ifndef OMWMM_EXCEPTIONS_HPP
#define OMWMM_EXCEPTIONS_HPP

#include <stdexcept>

namespace omwmm::exceptions {

struct ConfigException : public std::runtime_error {
	using std::runtime_error::runtime_error;
};

struct InvalidArgumentException : public std::logic_error {
	using std::logic_error::logic_error;
};

}

#endif // Include guard.