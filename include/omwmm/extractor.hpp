#ifndef INCLUDE_OMWMM_EXTRACTOR_HPP
#define INCLUDE_OMWMM_EXTRACTOR_HPP

#include <filesystem>
#include <any>
#include <functional>

namespace omwmm {

class Extractor {
private:
	std::any _data;

public:
	Extractor();

	void extract(
		const std::filesystem::path& source,
		const std::filesystem::path& dest
	);
};

}

#endif // Include guard.