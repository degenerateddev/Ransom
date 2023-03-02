#ifndef RANSOM_CRAWLER_H
#define RANSOM_CRAWLER_H

#include <vector>
#include <filesystem>

void systemCrawler(std::filesystem::path basePath);
std::vector<wchar_t> crawlDiskDrives();

#endif
