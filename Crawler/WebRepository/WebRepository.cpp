#include "WebRepository.h"

std::vector<WebSite> WebRepository::getAll()
{
    return source;
}

void WebRepository::save(const WebSite& website)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getDomain() == website.getDomain())
        {
            source[i] = website;
            return;
        }
    }

    source.push_back(website);
}