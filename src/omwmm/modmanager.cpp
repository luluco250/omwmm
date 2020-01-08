#include <omwmm/modmanager.hpp>
#include <stdexcept>
#include <omwmm/config.hpp>

using RuntimeError = std::runtime_error;

namespace omwmm {

ModManager::ModManager(const Config& cfg) {
	config(cfg);
}

const Config& ModManager::config() const {
	return *_config;
}
void ModManager::config(const Config& cfg) {
	if (!cfg.data_files_path || cfg.data_files_path->empty())
		throw RuntimeError("Data files path is empty");
	
	if (!cfg.downloaded_mods_path || cfg.downloaded_mods_path->empty())
		throw RuntimeError("Downloaded mods path is empty");
	
	if (!cfg.extracted_mods_path || cfg.extracted_mods_path->empty())
		throw RuntimeError("Extracted mods path is empty");
	
	_config = cfg;
}

}