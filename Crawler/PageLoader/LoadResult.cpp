#include "LoadResult.h"


LoadResult::LoadResult()
    : status{}, body{}
{

}

LoadResult::LoadResult(long Status, std::shared_ptr<std::string> Body, const std::string& EffectiveUrl) 
    : status(Status), body(Body), effectiveUrl(EffectiveUrl)
{
    
}


std::shared_ptr<std::string> LoadResult::getBody()
{
    return body;
}

std::string LoadResult::getEffectiveUrl()
{
    return effectiveUrl;
}

long LoadResult::getStatus()
{
    return status;
}