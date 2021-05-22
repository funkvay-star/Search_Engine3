#include "DocumentExtractor.h"

std::vector<std::string> DocumentExtractor::extractDocument(HtmlDocument& doc)
{
    std::vector<std::string> text;
    doc.visitElements([&text](HtmlElement elem)
    { 
        if(!elem.isTagA())
        {
            return;
        }

        auto href = elem.getAttribute("href");
        if(href.size() > 0)
        {
            text.push_back(href);
        }
    });

    return text;
}