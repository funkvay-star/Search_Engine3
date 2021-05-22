#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "LinkEntry.h"
#include <vector>
#include <optional>

class LinkRepository
{
private:
    std::vector<LinkEntry> source;

public:
    std::vector<LinkEntry> getAll();

    std::vector<LinkEntry> getByInformation(const std::string& domain, const LinkStatus& status, int count);

    void save(const LinkEntry& entry);

    std::optional<LinkEntry> getByUrl(const std::string& Url);

    size_t source_size()
    {
        return source.size();
    }
};

#endif
