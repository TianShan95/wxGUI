#ifndef __UTILS_H__
#define __UTILS_H__

#include"wxGUI.h"
#include<iostream>
#include <fstream>
#include <unistd.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>

#define FILE_MEET_ADD_CONDITION 0
#define FILE_MEET_MODIFY_CONDITION 0
#define FILE_NULL 1
#define FILE_NOT_EXIST 2
#define FILE_ALREADY_EXIST 3

void setWorkPath();
wxVector<wxVariant> getFileFromList(wxDataViewListCtrl* wxDVListCtr, int type);
void flushFrameFileList(wxVector<wxVariant> data,wxDataViewListCtrl* wxDVListCtr);
void flushDialogFileList(wxVector<wxVariant> data,wxDataViewListCtrl* wxDVListCtr);
void rewriteConfig(wxVector<wxVariant> VecSigFiles, wxVector<wxVariant> VecIOFiles);
unsigned int checkPathAddList(wxFileName filePath, wxDataViewListCtrl* m_dataViewListCtrl);
unsigned int checkPathModifyList(unsigned int row, unsigned int col, wxDataViewListCtrl* m_dataViewListCtrl);

wxBoxSizer* GetBoxSizerFromPanel(wxPanel* panel);
void HideOrShowAllControls(wxSizer* sizer, wxString type);

#endif // __UTILS_H__