#include "main.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <filesystem>

#include <omwmm.hpp>

using std::cout;
using std::cerr;
using InFileStream = std::ifstream;
using Exception = std::exception;
using RuntimeError = std::runtime_error;

using omwmm::Config;
using omwmm::ModManager;
using namespace omwmm::exceptions;

int main(int argc, char **argv) {
	try {
		auto modmgr = setup();
		test(modmgr);
	} catch (const Exception& e) {
		cerr << "Fatal error: " << e.what() << '\n';
		return 1;
	}
}

ModManager setup() {
	std::ios_base::sync_with_stdio(false);

	cout << std::filesystem::current_path() << '\n';

	try {
		return ModManager(Config(InFileStream("omwmm.toml")));
	} catch (const ConfigException&) {
		cerr << "Failed to parse config file!\n";
		throw;
	} catch (const Exception&) {
		cerr << "Failed to initialize mod manager!\n";
		throw;
	}
}

void test(ModManager& modmgr) {
	cout << modmgr.data_files_path() << '\n';
	cout << modmgr.downloaded_mods_path() << '\n';
	cout << modmgr.extracted_mods_path() << '\n';
}