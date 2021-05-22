#include "LinkRepository.h"
#include <algorithm>
#include <iostream>

std::vector<LinkEntry> LinkRepository::getAll()
{
    std::vector<LinkEntry> get_all;

    for(auto it : source)
    {
        get_all.push_back(it);
    }

    return get_all;
}

std::vector<LinkEntry> LinkRepository::getByInformation(const std::string& domain, const LinkStatus& status, int count)
{
    std::vector<LinkEntry> linkSource;

    for(auto link : source)
    {
        if(count == 0)
        {
            break;
        }

        //std::cout << "getDomainLink: " << link.getDomain() << " getUrlLink:" << link.getUrl() << "\n";

        if(link.getDomain() == domain && link.getStatus() == status)
        {
            //std::cout << "in push_back()\n";
            linkSource.push_back(link);
            --count;
        }
    }
    return linkSource;
}


void LinkRepository::save(const LinkEntry& entry)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getUrl() == entry.getUrl())
        {
            source[i] = entry;
            return;
        }
    }

    source.push_back(entry);
    std::cout << "source size after save: " << source.size() << "\n";
}

std::optional<LinkEntry> LinkRepository::getByUrl(const std::string& Url)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getUrl() == Url)
        {
            return std::make_optional(source[i]);
        }
    }

    return {};
}