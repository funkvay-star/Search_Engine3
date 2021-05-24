#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include "LoadResult.h"
#include <string>
#include <iostream>
#include <memory>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp> 

class LoadResult
{
private:
    long status;
    std::shared_ptr<std::string> body;
    std::string effectiveUrl;

public:
    LoadResult();

    LoadResult(long Status, std::shared_ptr<std::string> Body, const std::string& effectiveUrl);

    std::shared_ptr<std::string> getBody();

    std::string getEffectiveUrl();

    long int getStatus();
};



#endif
