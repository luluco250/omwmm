#include <omwmm/extractor.hpp>

#include <filesystem>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <algorithm>
#include <cctype>

#include <7zpp/7zpp.h>

#include <omwmm/exceptions.hpp>

using SevenZip::SevenZipLibrary;
using SevenZip::SevenZipExtractor;
using SevenZipString = SevenZip::TString;
using SevenZip::CompressionFormat;
using SevenZip::CompressionFormatEnum;
namespace fs = std::filesystem;

namespace omwmm {

using namespace exceptions;

Extractor::Extractor() : _data(SevenZipLibrary()) {
	auto lzma_lib = std::any_cast<SevenZipLibrary>(&_data);
	if (!lzma_lib->Load())
		throw ExtractorException("Failed to load 7z dll");
}

static const std::unordered_map<std::string_view, CompressionFormatEnum>
extensions{
	{".7z", CompressionFormat::SevenZip},
	{".zip", CompressionFormat::Zip},
	{".rar", CompressionFormat::Rar}
};

void Extractor::extract(const fs::path& source, const fs::path& dest) {
	if (!fs::exists(source))
		throw ExtractorException("Source file doesn't exist");

	if (!fs::exists(dest))
		fs::create_directory(dest);

	auto lib = std::any_cast<SevenZipLibrary>(&_data);

	auto str = fs::path(source).make_preferred().native();
	SevenZipString name;
	name.assign(str.begin(), str.end());
	auto ext = SevenZipExtractor(*lib, name);

	str.assign(dest.native());
	name.assign(str.begin(), str.end());

	if (!ext.DetectCompressionFormat()) {
		auto sf = source.extension().string();
		std::transform(sf.begin(), sf.end(), sf.begin(), std::tolower);

		if (extensions.find(sf) != extensions.end())
			ext.SetCompressionFormat(extensions.at(sf));
		else
			ext.SetCompressionFormat(CompressionFormat::Zip);
	}

	if (!ext.ExtractArchive(name))
		throw ExtractorException("Failed to extract file");
}

}