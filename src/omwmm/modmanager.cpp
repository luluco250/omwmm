#include <omwmm/modmanager.hpp>

#include <filesystem>
#include <utility>

#include <omwmm/config.hpp>
#include <omwmm/exceptions.hpp>

using Path = std::filesystem::path;

namespace omwmm {

using namespace exceptions;

ModManager::ModManager(const Config& cfg) {
	config(cfg);
}

const Config& ModManager::config() const {
	return _config;
}
void ModManager::config(const Config& cfg) {
	if (!cfg.data_files_path || cfg.data_files_path->empty())
		throw InvalidArgumentException("Data files path is empty");
	
	if (!cfg.downloaded_mods_path || cfg.downloaded_mods_path->empty())
		throw InvalidArgumentException("Downloaded mods path is empty");
	
	if (!cfg.extracted_mods_path || cfg.extracted_mods_path->empty())
		throw InvalidArgumentException("Extracted mods path is empty");
	
	_config = cfg;
}

#define GET_SET(NAME, PRETTY_NAME) \
Path ModManager::NAME() const { \
	return *_config.NAME; \
} \
void ModManager::NAME(const Path& path) { \
	if (path.empty()) \
		throw InvalidArgumentException(PRETTY_NAME " cannot be empty"); \
	\
	_config.NAME = path; \
} \
void ModManager::NAME(Path&& path) { \
	if (path.empty()) \
		throw InvalidArgumentException(PRETTY_NAME " cannot be empty"); \
	\
	_config.NAME = std::move(path); \
}

GET_SET(data_files_path, "Data files path")
GET_SET(downloaded_mods_path, "Downloaded mods path")
GET_SET(extracted_mods_path, "Extracted mods path")

}