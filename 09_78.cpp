#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdexcept>

#include "PDFWriter/PDFWriter.h"
#include "PDFWriter/PDFPage.h"
#include "PDFWriter/PageContentContext.h"
#include "PDFWriter/PDFFormXObject.h"

using namespace std;

#define height = 842;
#define width = 595;
#define margin = 20;

vector<string> get_file_path_in_dir(const string& dir_name , const string& extension) noexcept(false)
{
    HANDLE hFind;
    WIN32_FIND_DATA win32fd;
    vector<string> fileList;
    string tmpFolder = dir_name + "\\*." + extension;

    hFind = FindFirstFile(tmpFolder.c_str(), &win32fd);

    assert(hFind != INVALID_HANDLE_VALUE);
    do
    {
        string tmpStr = strFolder + "\\" + win32fd.cFileName;
        if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            /* 直下以外は何もしない */
        }
        else
        {
            fileList.push_back(win32fd.cFileName);
        }
    } while (FindNextFile(hFind, &win32fd));

    FindClose(hFind);

    return fileList;
}


void makePdf(const string folderPath, const string fileName)
{
    /* 対象ファイルリスト */
    vector<string> fileList = get_file_path_in_dir(folderPath, "jpg");

    PDFWriter pdfFile;
    pdfFile.StartPDF(folderPath + "\\" + fileName, ePDFVersion13);

    PDFPage* page = new PDFPage();
    page->SetMediaBox(PDFRectangle(0, 0, width, height));
    PageContentContext* context = pdf.StartPageContentContext(page);

    /* 縦方向の残り */
    auto top = height - margin;

    for (auto fileName: fileList) {
        /* 画像のサイズを確認 */
        auto dims = pdfFile.GetImageDimensions(fileName);

        /* 大きすぎるファイルをスキップ */
        if (dims.econd > (height - margin -margin )) continue;

        /* ページ送りの判定 */
        if (top - dims.second < margin) {
            pdf.EndPageContentContext(context);
            pdf.WritePageAndRelease(page);

            page = new PDFPage();
            page->SetMediaBox(PDFRectangle(0, 0, width, height));
            context = pdf.StartPageContentContext(page);

            top = height - margin;
        }

        /* 画像追加 */
        context->DrawImage(margin, top - dims.second, fileName);

        top -= dims.second + margin;
    }

    pdf.EndPageContentContext(context);
    pdf.WritePageAndRelease(page);

    pdf.EndPDF();
}

int main (void) 
{
    string fileName = "sample.pdf";
    string thisFolder = "C:\\tmp\\Cplus\\jpg";

    makePdf(thisFolder, fileName);

    return 0;
}

