#include <omwmm/config.hpp>
#include <istream>
#include <memory>
#include <cpptoml.h>
#include <omwmm/exceptions.hpp>
#include <string>

template<class T>
using Shared = std::shared_ptr<T>;
using String = std::string;

namespace omwmm {

using namespace exceptions;

Config::Config(std::istream& stream) {
	cpptoml::parser parser(stream);

	Shared<cpptoml::table> table;
	try {
		table = parser.parse();
	} catch (const cpptoml::parse_exception& e) {
		throw ConfigException(e.what());
	}

	data_files_path =
		table->get_as<String>("data_files_path").value_or("");
	downloaded_mods_path =
		table->get_as<String>("downloaded_mods_path").value_or("");
	extracted_mods_path =
		table->get_as<String>("extracted_mods_path").value_or("");
}

}