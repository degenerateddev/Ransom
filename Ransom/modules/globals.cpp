#include "globals.h"
#include <vector>
#include <filesystem>
#include <tchar.h>
#include <Windows.h>

std::vector<std::string>filetypes = {    ".png", ".PNG",
                                         ".jpg", ".JPG",
                                         ".gif", ".GIF",
                                         ".jpeg", ".JPEG",
                                         ".jfif", ".JFIF",
                                         ".bmp", ".BMP",
                                         ".dib", ".DIB",
                                         ".pict", ".PICT",
                                         ".pct", ".PCT",
                                         ".psd", ".PSD",
                                         ".tga", ".TGA",
                                         ".tif", ".TIF",
                                         ".tif", ".TIFF",
                                         ".swf", ".SWF",
                                         ".svg", ".SVG",

                                         ".mov", ".MOV",
                                         ".mp4", ".MP4",
                                         ".avi", ".AVI",
                                         ".vlc", ".VLC",
                                         ".mpg", ".MPG",
                                         ".mpeg", ".MPEG",
                                         ".m2v", ".M2V",
                                         ".mp2", ".MP2",
                                         ".vob", ".VOB",
                                         ".flm", ".FLM",
                                         ".wmv", ".WMV",
                                         ".asf", ".ASF",
                                         ".rm", ".RM",

                                         ".txt", ".TXT",
                                         ".doc", ".DOC",
                                         ".docx", ".DOCX",
                                         ".pdf", ".PDF",
                                         ".odt", ".ODT",
                                         ".indd", ".INDD",
                                         ".RTF", ".rtf",
                                         ".csv", ".CSV",
                                         ".xls", ".XLS",
                                         ".ppt", ".PPT",

                                         ".mp3", ".MP3",
                                         ".wav", ".WAV",
                                         ".aif", ".AIF",
                                         ".wma", ".WMA",
                                         ".ra", ".RA",
                                         ".rm", ".RM",
                                            
                                         ".exe", ".EXE",
                                         ".bat", ".BAT",
                                         ".bin", ".BIN",
                                         ".jar", ".JAR",
                                         ".dll", ".DLL",
                                         ".sys", ".SYS",
                                         ".cpp", ".CPP",
                                         ".h", ".H",
};

//std::filesystem::path basePath = "c:\\Users";
std::filesystem::path basePath = "c:\\Users\\freng\\Desktop\\Test";


WCHAR szDrive[] = (L" A");
