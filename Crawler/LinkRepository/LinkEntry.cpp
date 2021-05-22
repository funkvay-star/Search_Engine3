#include "LinkEntry.h"
#include <iostream>


LinkEntry::LinkEntry()
    : lastUpdate{}, url{}, domain{}, status{} 
{

}

LinkEntry::LinkEntry(const std::string& Url, const std::string& Domain, const LinkStatus& Status, const time_t& LastUpdate)
    : url(Url), domain(Domain), status(Status), lastUpdate(LastUpdate) 
{
     //std::cout << "LINK_ENTRY_DOMINATE\n";
} 


std::string LinkEntry::getUrl() const
{
    return this->url;
}

std::string LinkEntry::getDomain() const
{
    return this->domain;
}

LinkStatus LinkEntry::getStatus() const
{
    return this->status;
}

time_t LinkEntry::getTime() const
{
    return this->lastUpdate;
}