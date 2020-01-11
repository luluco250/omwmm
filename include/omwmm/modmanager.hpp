#ifndef OMWMM_MODMANAGER_HPP
#define OMWMM_MODMANAGER_HPP

#include "config.hpp"

#include <optional>
#include <filesystem>
#include <functional>
#include <string_view>

#include "extractor.hpp"

namespace omwmm {

class ModManager {
private:
	Config _config;
	Extractor _extractor;

public:
	/**
	 * Construct a new instance of the mod manager.
	 * 
	 * @param cfg The configuration to be used.
	 * 
	 * @see config()
	 */
	ModManager(const Config& cfg);

	/**
	 * Iterate over downloaded mods.
	 */
	void query_downloads(
		const std::function<void(std::string_view)>& func
	);

	/**
	 * Extract mod.
	 * 
	 * @param name Mod filename, including extension.
	 */
	void extract_mod(std::string_view name);

	/**
	 * Get the current configuration.
	 */
	const Config& config() const;
	
	/**
	 * Set a new configuration.
	 * 
	 * Can throw a std::runtime_error if any configuration parameters are
	 * invalid.
	 * 
	 * @param cfg The new configuration to be used.
	 */
	void config(const Config& cfg);

	/**
	 * Get the current "data files" path.
	 */
	std::filesystem::path data_files_path() const;

	/**
	 * Set a new "data files" path.
	 * 
	 * @param path The new path.
	 */
	void data_files_path(const std::filesystem::path& path);

	/**
	 * Set a new "data files" path.
	 * 
	 * @param path The new path.
	 */
	void data_files_path(std::filesystem::path&& path);

	/**
	 * Get the current "downloaded mods" path.
	 */
	std::filesystem::path downloaded_mods_path() const;

	/**
	 * Set a new "downloaded mods" path.
	 * 
	 * @param path The new path.
	 */
	void downloaded_mods_path(const std::filesystem::path& path);

	/**
	 * Set a new "downloaded mods" path.
	 * 
	 * @param path The new path.
	 */
	void downloaded_mods_path(std::filesystem::path&& path);

	/**
	 * Get the current "extracted mods" path.
	 */
	std::filesystem::path extracted_mods_path() const;

	/**
	 * Set a new "extracted mods" path.
	 * 
	 * @param path THe new path.
	 */
	void extracted_mods_path(const std::filesystem::path& path);

	/**
	 * Set a new "extracted mods" path.
	 * 
	 * @param path THe new path.
	 */
	void extracted_mods_path(std::filesystem::path&& path);
};

} // Namespace.

#endif // Include guard.