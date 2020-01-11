#ifndef OMWMM_EXCEPTIONS_HPP
#define OMWMM_EXCEPTIONS_HPP

#include <stdexcept>

namespace omwmm::exceptions {

#define DECLARE(NAME, BASE_NAMESPACE, BASE_NAME) \
struct NAME : public BASE_NAMESPACE::BASE_NAME { \
	using BASE_NAMESPACE::BASE_NAME::BASE_NAME; \
};

DECLARE(ModManagerSetupException, std, runtime_error)
DECLARE(ConfigException, std, runtime_error)
DECLARE(ExtractorException, std, runtime_error)
DECLARE(InvalidArgumentException, std, logic_error)

#undef DECLARE

}

#endif // Include guard.