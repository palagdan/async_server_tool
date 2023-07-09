#pragma once
#include <fstream>
#include "logging.h"

/**
 * @class FileLogging
 * @brief Concrete class for logging messages to a file.
 *
 * The FileLogging class is a derived class of Logging that provides functionality to log messages,
 * requests, and responses to a specified file. It inherits the abstract functions from the Logging
 * class and implements them accordingly.
 */
class FileLogging : public Logging {
public:
    /**
     * @brief Constructor.
     * @param target_file The file path of the target file for logging.
     *
     * Creates a FileLogging object with the specified target file for logging.
     */
    FileLogging(const std::string& target_file);

    /**
     * @brief Destructor.
     *
     * Closes the file stream associated with the FileLogging object.
     */
    ~FileLogging() { m_os.close(); };


    /**
     * @brief Log a warning message to the file.
     * @param message The warning message to be logged.
     */
    void logWarning(const std::string& message) override;

    /**
     * @brief Log an informational message to the file.
     * @param message The informational message to be logged.
     */
    void logInfo(const std::string& message) override;

    /**
     * @brief Log a generic message to the file.
     * @param message The message to be logged.
     */
    void logMessage(const std::string& message) override;

    /**
     * @brief Log an error message to the file.
     * @param message The error message to be logged.
     */
    void logError(const std::string& message) override;

    /**
     * @brief Get the type of logger.
     * @return The type of logger as a string.
     */
    std::string loggerType() const override;

private:
    std::string m_target_file;   ///< The target file path for logging.
    std::ofstream m_os;          ///< Output file stream for writing log messages.
};
