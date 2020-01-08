#include "main.hpp"

#include <iostream>
#include <stdexcept>
#include <optional>
#include <fstream>
#include <filesystem>

#include <omwmm.hpp>

using std::cout;
using std::cerr;
using InFileStream = std::ifstream;
using Exception = std::exception;
using RuntimeError = std::runtime_error;
template<class T> using Optional = std::optional<T>;

using omwmm::Config;
using omwmm::ModManager;

int main(int argc, char **argv) {
	std::ios_base::sync_with_stdio(false);

	cout << std::filesystem::current_path() << '\n';

	Optional<ModManager> modmgr;

	try {
		modmgr = ModManager(Config(InFileStream("omwmm.toml")));
	} catch (const Exception& e) {
		cerr << "Failed to initialize mod manager: " << e.what() << '\n';
		return 1;
	}

	cout << *modmgr->config().data_files_path << '\n';
	cout << *modmgr->config().downloaded_mods_path << '\n';
	cout << *modmgr->config().extracted_mods_path << '\n';
}