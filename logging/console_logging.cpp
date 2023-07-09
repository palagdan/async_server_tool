#include "console_logging.h"



std::string ConsoleLogging::loggerType() const {
    return "console";
}

void ConsoleLogging::logWarning(const std::string & src) {
    std::cout << logCurrentDate() << " WARN " << src << std::endl;
}

void ConsoleLogging::logInfo(const std::string & src) {
    std::cout << logCurrentDate() << " INFO "   << src << std::endl;
}

void ConsoleLogging::logError(const std::string & src) {
    std::cout << logCurrentDate() << " ERROR " << src << std::endl;
}

void ConsoleLogging::logMessage(const std::string & src) {
    std::cout << logCurrentDate()  << " " << src << std::endl;
}

