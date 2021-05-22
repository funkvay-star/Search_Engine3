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
public:
    LoadResult();

    LoadResult(long Status, std::shared_ptr<std::string> Body);

    std::shared_ptr<std::string> getBody();

    long int getStatus();
};



#endif
