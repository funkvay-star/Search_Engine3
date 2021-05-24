#include "LoadResult.h"
#include "PageLoader.h"
#include <string>
#include <iostream>

//std::string document;


size_t PageLoader::function_helper(char* buffer, size_t itemsize, size_t nitems, void* ignorethis)
{
    size_t bytes = itemsize * nitems;
    std::string* str = (std::string*)ignorethis;
    str->append(buffer);

    return bytes;
}


LoadResult PageLoader::get_data(const std::string& url)
{
        CURL *curl = curl_easy_init();
        if(!curl)
        {
            std::cout << "curl_easy_init() failed\n";
            return LoadResult();
        }


        std::string* document = new std::string();

        curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Accept:text/html");


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); ///////
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 3);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_helper);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)document);
        curl_easy_setopt(curl, CURLOPT_HEADER, headers);
        

        CURLcode result = curl_easy_perform(curl);
        if(result != CURLE_OK)
        {
            std::cout << "curl_easy_perform error. Download problem: \n";
    
            return LoadResult();
        }

        long curlinfoResponseCode;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &curlinfoResponseCode);


        char* contentType = nullptr;

        curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType);

        char* substrForContentType = strstr(contentType, "text/html;");


        if(substrForContentType)
        {
            //return LoadResult();
            std::cout << "\n ContentType -> " << contentType << "\n";
        }
        else
        {
            std::cout << "\n It's not url, It's pdf, img, etc\n";
            return LoadResult();
        }

        char *effectiveUrl = nullptr;

        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &effectiveUrl);

        if(effectiveUrl)
        {
            std::cout << "\neffective Url -> " << effectiveUrl << "\n";
            std::cout << "simlpe url: " << url << "\n";
        }

        curl_easy_cleanup(curl);
        return LoadResult(curlinfoResponseCode, std::shared_ptr<std::string>(document), effectiveUrl);
}