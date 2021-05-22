#include "PageLoader/PageLoader.h"
#include "PageLoader/LoadResult.h"
#include "WebRepository/WebRepository.h"
#include "InfoExtractor/DocumentExtractor.h"
#include "InfoExtractor/InformationExtractor.h"
#include "LinkRepository/LinkRepository.h"
#include "LinkRepository/LinkEntry.h"
#include "LinkRepository/LinkRepository.h"
#include "LinkRepository/LinkStatus.h"
#include "DocumentRepository/DocumentRepository.h"
#include "HTMLDocument/HtmlDocument.h"


int main()
{
    //std::cout << "CHECK\n";
    
    WebRepository webrep;

    std::time_t currentTime{};

    PageLoader pageLoader;

    DocumentExtractor linkExtractor;

    InformationExtractor informationExtractor;


    WebSite w("rau.am", "https://rau.am/", time(&currentTime));
    webrep.save(w);

    w.getDomain();

    LinkRepository linkRepository;

    //for(auto& website : webrep.getAll())
    
    for(auto& website : webrep.getAll())
    {
        //std::cout << "CHECK_1\n";

        //adding first page for processing
        linkRepository.save(LinkEntry(website.getHomePage(), website.getDomain(), LinkStatus::WAITING, time(&currentTime)));         

        /*
        * if there is still something in the queue for a specific 
        * website, we continue processing
        */
        while(true)
        {
            //std::cout << "CHECK_2\n";
            /*
            * taking all links with the same domain and which have not yet been processed,
            * we take their number in this case 10
            */ 
            auto links = linkRepository.getByInformation(website.getDomain(), LinkStatus::WAITING, 10);


            //if there is not links, then we break this cycle
            if(links.empty())
            {
                std::cout << "number of links: " << links.size();
                break;
            }

            // go through all the links in queue
            for(auto& link : links)
            {
                //std::cout << "CHECK_3\n";
                // getting html code from the link
                auto loadResult = pageLoader.get_data(link.getUrl());
                
                // checking if the respone code >= 200 or < 300, if it's not, then its' an error
                if(loadResult.getStatus() < 200 || loadResult.getStatus() >= 300)
                {
                    linkRepository.save(LinkEntry(website.getHomePage(), website.getDomain(), LinkStatus::WAITING, time(&currentTime)));
                    //linkRepository.save(time(&currentTime), link.getUrl(), website.getDomain(), LinkStatus::ERROR);
                    continue;
                }

                // further we will process the page

                // getting html code and saving in document
                
                HtmlDocument document((*(loadResult.getBody().get())));
                //std::cout << "hehe\n";
                // now we are going to parse and get the tree
                document.parse();


                /*
                * now we are going to Extract links using DocumentExtractor
                * DocumentExtractor linkExtractor;
                */
               auto extractLinks = linkExtractor.extractDocument(document);

                // these are already links that we got from the html code
               for(const auto& newLink : extractLinks)
               {
                   // if the link is in queue, the we just continue
                   if(linkRepository.getByUrl(newLink).has_value()) // has_value is std::optionals function
                   {
                       continue;
                   }


                LinkEntry trash(newLink, website.getDomain(), LinkStatus::WAITING, time(&currentTime));
                // if the link has not yet been added to the queue, then we add it
                //linkRepository.save(LinkEntry(time(&currentTime), newLink, website.getDomain(), LinkStatus::WAITING));
                linkRepository.save(trash);
               }

               auto documentInformation = informationExtractor.extractInformation(document);

                // 59 minute

                


                // the end

                linkRepository.save(LinkEntry(link.getUrl(), link.getDomain(), LinkStatus::SUCCESS, time(&currentTime)));
            }
        }
        
        webrep.save(WebSite(website.getDomain(), website.getHomePage(), time(&currentTime)));
        //std::cout << linkRepository.source_size() << "\n";
    }
}