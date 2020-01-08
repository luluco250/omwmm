#ifndef OMWMM_MODMANAGER_HPP
#define OMWMM_MODMANAGER_HPP

#include "config.hpp"
#include <optional>

namespace omwmm {

class ModManager {
private:
	std::optional<Config> _config;

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
};

} // Namespace.

#endif // Include guard.