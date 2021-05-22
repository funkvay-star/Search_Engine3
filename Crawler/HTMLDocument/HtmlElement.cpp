#include "HtmlElement.h"


HtmlElement::HtmlElement(GumboNode* Node) : HtmlNode(Node) {}

bool HtmlElement::isElement()
{
    return true;
}

bool HtmlElement::isTagA() const
{
    if(node->v.element.tag == GUMBO_TAG_A)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagText() const
{
    if(node->v.element.tag != GUMBO_TAG_SCRIPT && node->v.element.tag != GUMBO_TAG_STYLE)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagDescription() const
{
    if(node->v.element.tag == GUMBO_TAG_META)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagTitle() const
{
    if(node->v.element.tag == GUMBO_TAG_TITLE)
    {
        return true;
    }
    return false;
}

std::string HtmlElement::getAttribute(const std::string& name)
{
    GumboAttribute* attribute = gumbo_get_attribute(&node->v.element.attributes, name.c_str());

    if(attribute == nullptr)
    {
        return "";
    }
    return std::string(attribute->value);
}

std::string HtmlElement::getText()
{
    std::string text = "";

    GumboVector* children = &node->v.element.children;

    for(size_t i = 0; i < children->length; ++i) 
    {
        auto child = static_cast<GumboNode*>(children->data[i]); // WARNING
        
        if(child->type == GUMBO_NODE_TEXT)
        {
            text += child->v.text.text;
        }
    }
    return text;
}