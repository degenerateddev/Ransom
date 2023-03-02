#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <filesystem>
#include <thread>
#include <future>

#include "modules/encryption.h"
#include "modules/output.h"
#include "modules/crawler.h"
#include "modules/globals.h"
#include "modules/conf.h"


int main() {
    std::promise<const char*> p;
    auto f = p.get_future();

    try {
        std::thread ex(systemCrawler, basePath);
        std::vector<WCHAR>ds =  crawlDiskDrives();
        ex.join();

        for (int j = 0; j < ds.size(); j++) {
            std::cout << "Vector element: " << ds.at(j) << std::endl;
        }

        /*for (int i = 0; i < ds.size(); i++) {
            char* temp = _strdup(ds.at(i));
            unsigned char* tptr = (unsigned char*)temp;
            while (*tptr) {
                *tptr = std::tolower(*tptr);
                tptr++;
            }
            std::filesystem::path _odP = *tptr + ":\\";
            std::cout << "Crawling drive: " << _odP << std::endl;
            //systemCrawler(_odP);
            free(temp);
        }*/
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}