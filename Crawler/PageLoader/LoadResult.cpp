#include "LoadResult.h"


LoadResult::LoadResult()
    : status{}, body{}
{

}

LoadResult::LoadResult(long Status, std::shared_ptr<std::string> Body) 
    : status(Status), body(Body) 
{
    
}


std::shared_ptr<std::string> LoadResult::getBody()
{
    return body;
}

long LoadResult::getStatus()
{
    return status;
}