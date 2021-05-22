#ifndef DOCUMENT_EXTRACTOR
#define DOCUMENT_EXTRACTOR

#include "../HTMLDocument/HtmlDocument.h"
#include <vector>

class DocumentExtractor
{
private:
public:
    DocumentExtractor() = default;
    std::vector<std::string> extractDocument(HtmlDocument& doc);
};

#endif
