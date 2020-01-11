#include <omwmm/modmanager.hpp>

#include <filesystem>
#include <utility>
#include <functional>
#include <unordered_set>
#include <string>
#include <string_view>

#include <omwmm/config.hpp>
#include <omwmm/exceptions.hpp>

#include <7zpp/7zpp.h>

using Path = std::filesystem::path;
using DirectoryIterator = std::filesystem::directory_iterator;
template<class T> using Function = std::function<T>;
template<class T> using UnorderedSet = std::unordered_set<T>;
using String = std::string;
using StringView = std::string_view;

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
		throw ModManagerSetupException("Data files path is empty");
	
	if (!cfg.downloaded_mods_path || cfg.downloaded_mods_path->empty())
		throw ModManagerSetupException("Downloaded mods path is empty");
	
	if (!cfg.extracted_mods_path || cfg.extracted_mods_path->empty())
		throw ModManagerSetupException("Extracted mods path is empty");
	
	_config = cfg;
}

static const UnorderedSet<StringView> download_exts{
	".7z", ".zip", ".rar"
};

void ModManager::query_downloads(
	const Function<void(StringView)>& func
) {
	for (auto p : DirectoryIterator(downloaded_mods_path()))
		if (download_exts.find(p.path().extension().string()) != download_exts.end())
			func(p.path().filename().string());
}

void ModManager::extract_mod(StringView filename) {
	auto source = downloaded_mods_path() / filename;
	auto dest = extracted_mods_path() / source.filename().replace_extension("");

	_extractor.extract(source, dest);
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