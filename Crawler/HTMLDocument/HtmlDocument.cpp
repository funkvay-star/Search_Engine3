#include "HtmlDocument.h"


HtmlDocument::HtmlDocument(const std::string& Url) : url(Url), output(nullptr) {}

bool HtmlDocument::parse()
{
  this->output = gumbo_parse(this->url.c_str());
  return true;
}


void HtmlDocument::visitElements(std::function<void(HtmlElement)> visitor)
{
    this->visitElement(output->root, visitor);
}

void HtmlDocument::visitElement(GumboNode* node, std::function<void(HtmlElement)> visitor)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    visitor(HtmlElement(node));

    
  GumboVector* children = &node->v.element.children;
  for (unsigned int i = 0; i < children->length; ++i) 
  {
    visitElement(static_cast<GumboNode*>(children->data[i]), visitor);
  }
}

HtmlDocument::~HtmlDocument()
{
  if(this->output != nullptr)
  {
    gumbo_destroy_output(&kGumboDefaultOptions, this->output);
  }
}