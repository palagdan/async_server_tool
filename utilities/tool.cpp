
#include "tool.h"


static void displayHelpMessage(const std::string & helper_filename){
    std::ifstream is(helper_filename);

    if(!is.is_open()){
        throw std::runtime_error("Failed to open helper file: " + helper_filename);
    }

}