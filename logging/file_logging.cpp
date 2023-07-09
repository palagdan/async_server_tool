
#include "file_logging.h"

FileLogging::FileLogging(const std::string &target_file) : m_os(target_file){

}


std::string FileLogging::loggerType() const {
    return "File";
}

void FileLogging::logWarning(const std::string & src) {

    if(m_os.is_open()){
        m_os << logCurrentDate() << " WARN "  << src << std::endl;
    }else{
        throw std::runtime_error("Error: logger file is closed " + m_target_file);
    }
}
void FileLogging::logInfo(const std::string & src) {
    if(m_os.is_open()){
        m_os << logCurrentDate() << " INFO " << src << std::endl;
    }else{
        throw std::runtime_error("Error: logger file is closed " + m_target_file);
    }
}
void FileLogging::logError(const std::string & src) {
    if(m_os.is_open()){
        m_os << logCurrentDate() << " ERROR " << src << std::endl;
    }else{
        throw std::runtime_error("Error: logger file is closed " + m_target_file);
    }
}

void FileLogging::logMessage(const std::string & src) {
    if(m_os.is_open()){
        m_os << logCurrentDate() << " " << src << std::endl;
    }else{
        throw std::runtime_error("Error: logger file is closed " + m_target_file);
    }
}


