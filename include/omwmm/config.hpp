#ifndef OMWMM_CONFIG_HPP
#define OMWMM_CONFIG_HPP

#include <filesystem>
#include <optional>
#include <istream>

namespace omwmm {

struct Config {
	std::optional<std::filesystem::path> data_files_path;
	std::optional<std::filesystem::path> downloaded_mods_path;
	std::optional<std::filesystem::path> extracted_mods_path;

	Config(std::istream& stream);
};

} // Namespace.

#endif // Include guard.