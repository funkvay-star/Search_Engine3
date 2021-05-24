#include "DocumentExtractor.h"
#include <iostream>


// std::string DocumentExtractor::getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl)
// {
//     if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
//     {
//         size_t sizeOfEffectiveUrl = effectiveUrl.size() - 1;

//         while(effectiveUrl[sizeOfEffectiveUrl] != '/')
//         {
//             effectiveUrl.resize(effectiveUrl.size() - 1);
//         }

//         // https://rau.am/contacts/  phone = https://rau.am/contatcs/phone

//         return effectiveUrl + notAbsoluteUrl;
//     }
//     else if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] == '/')
//     {
//         return effectiveUrl + notAbsoluteUrl;
//     }
//     else if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] == '/' ||
//             notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
//     {
//         return domain + notAbsoluteUrl;
//     }
// }

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
        
        size_t foundHttps = href.find("https:");

        if(foundHttps == std::string::npos)
        {
            href = getAbsoluteUrl(foundHttps, domain, effectiveUrl);
        }

        std::cout << "\n\n\nHref - >" << href << "\n\n\n";
        if(href.size() > 0)
        {
            text.push_back(href);
        }
    });

    return text;
}