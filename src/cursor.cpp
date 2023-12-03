#include "global.h"

Cursor::Cursor()
{
    ;
}

Cursor::Cursor(string tableName, int pageIndex)
{
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pagePointer = 0;
    this->tableName = tableName;
    this->pageIndex = pageIndex;
}

/**
 * @brief This function reads the next row from the page. The index of the
 * current row read from the page is indicated by the pagePointer(points to row
 * in page the cursor is pointing to).
 *
 * @return vector<int> 
 */
vector<int> Cursor::getNext()
{
    logger.log("Cursor::geNext");
    vector<int> result = this->page.getRow(this->pagePointer);
    this->pagePointer++;
    if(result.empty()){
        tableCatalogue.getTable(this->tableName)->getNextPage(this);
        if(!this->pagePointer){
            result = this->page.getRow(this->pagePointer);
            this->pagePointer++;
        }
    }
    return result;
}
vector<int> Cursor::getNextRow()
{
    logger.log("Cursor::geNext");
    vector<int> result = this->page.getRow(this->pagePointer);
    this->pagePointer++;
    // if(result.empty()){
    //     tableCatalogue.getTable(this->tableName)->getNextPage(this);
    //     if(!this->pagePointer){
    //         result = this->page.getRow(this->pagePointer);
    //         this->pagePointer++;
    //     }
    // }
    return result;
}
vector<vector<int>> Cursor::getAllRows()
{
    logger.log("Cursor::geNext");
    vector<vector<int>> result = this->page.getRows();
    return result;
}
/**
 * @brief Function that loads Page indicated by pageIndex. Now the cursor starts
 * reading from the new page.
 *
 * @param pageIndex 
 */
void Cursor::nextPage(int pageIndex)
{
    logger.log("Cursor::nextPage");
    this->page = bufferManager.getPage(this->tableName, pageIndex);
    this->pageIndex = pageIndex;
    this->pagePointer = 0;
}

//-----------------------------------Our Code----------------------------------------

Cursor::Cursor(string MatrixName, pair<int,int> pageIndex)
{
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPageMatrix(MatrixName, pageIndex);
    this->pagePointer = 0;
    this->tableName = MatrixName;
    // this->pageIndex = pageIndex;
}

