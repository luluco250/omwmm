#ifndef OMWMM_EXCEPTIONS_HPP
#define OMWMM_EXCEPTIONS_HPP

#include <stdexcept>
#include <string_view>

namespace omwmm {

class ConfigException : public std::runtime_error {
private:
	const char* msg;

public:
	ConfigException(const char* msg);

	const char* what() const override;
};

}

#endif // Include guard.