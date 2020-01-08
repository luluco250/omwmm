#include <omwmm/exceptions.hpp>

namespace omwmm {

ConfigException::ConfigException(const char* msg) : msg(msg), std::runtime_error(msg) {}

const char* ConfigException::what() const {
	return msg;
}

}