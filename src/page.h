#pragma once
#include"logger.h"
/**
 * @brief The Page object is the main memory representation of a physical page
 * (equivalent to a block). The page class and the page.h header file are at the
 * bottom of the dependency tree when compiling files. 
 *<p>
 * Do NOT modify the Page class. If you find that modifications
 * are necessary, you may do so by posting the change you want to make on Moodle
 * or Teams with justification and gaining approval from the TAs. 
 *</p>
 */

class Page{

    string tableName;
    string pageIndex;
    int columnCount;
    int rowCount;
    vector<vector<int>> rows;

    public:

    string pageName = "";
    Page();
    Page(string tableName, int pageIndex);
    Page(string tableName, int pageIndex, vector<vector<int>> rows, int rowCount);
    vector<int> getRow(int rowIndex);
    vector<vector<int>> getRows();
    void writePage();
    //--------------------------Our Code----------------------------------------
    //-------Matrix
    Page(string matrixName, pair<int,int> pageIndex);
    Page(string matrixName, pair<int,int> pageIndex, vector<vector<int>> rows,int rowCount);
    // friend void transposeOfaPage(Page& obj);
    // friend bool checkSymmetryOfDiagonal(Page &page);
    // friend bool checkSymmetryOfNonDiagonal(Page &page1,Page &page2);
    // friend void differenceOfTwoMatrixDiagonal(Page& page1, Page& page2);
    // friend void differenceOfTwoMatrixNonDiagonal(Page& page1, Page& page2);
    vector<vector<int>> getMatrixRows();
    int getRowCount();

};