#include <string>
#include <utility>

class ConfigParser {
public:
    ConfigParser(std::string  filename) : m_filename(std::move(filename)){};
    virtual void parse() = 0;
    virtual ~ConfigParser() = default;

protected:
    std::string m_filename;
};



