#include"utils.h"

void setWorkPath()
{
    // setWorkPath for executable program path
    wxString exePath = wxStandardPaths::Get().GetExecutablePath();
    wxString exeDir = wxPathOnly(exePath);
    chdir(exeDir.c_str());

    // if (chdir(exeDir.c_str()) == 0) 
    // {
    //     std::cout << exeDir << " Setting workdir Success" << std::endl;
    // }
    // else
    // {
    //     std::cout << exeDir << " Setting workdir Failed" << std::endl;
    // }
}

wxVector<wxVariant> getFileFromList(wxDataViewListCtrl* wxDVListCtr, int type)
{
    //check signal file paths
    int rows = wxDVListCtr->GetItemCount();
    wxVector<wxVariant> data;
    for(int i=0; i<rows; i++)
    {
        wxString path = wxDVListCtr ->GetTextValue(i,type);
        data.push_back( wxVariant(path) );
    }
    return data;
}

void flushFrameFileList(wxVector<wxVariant> VecFiles,wxDataViewListCtrl* wxDVListCtr)
{
    wxVector<wxVariant> data;
    wxDVListCtr->DeleteAllItems();
    for(wxVector<wxVariant>::iterator it=VecFiles.begin();it!=VecFiles.end();it++)
    {
        // data.push_back( wxVariant(false) );
        data.push_back(wxVariant(*(it)));
        wxDVListCtr->AppendItem( data );
        data.clear();
    }
}

void flushDialogFileList(wxVector<wxVariant> VecFiles,wxDataViewListCtrl* wxDVListCtr)
{
    wxVector<wxVariant> data;
    wxDVListCtr->DeleteAllItems();
    wxDVListCtr->AppendToggleColumn( "Choice" );
    wxDVListCtr->AppendTextColumn( "Path(s)" , wxDATAVIEW_CELL_EDITABLE);

    for(wxVector<wxVariant>::iterator it=VecFiles.begin();it!=VecFiles.end();it++)
    {
        data.push_back( wxVariant(false) );
        data.push_back(wxVariant(*(it)));
        wxDVListCtr->AppendItem( data );
        data.clear();
    }
}

void rewriteConfig(wxVector<wxVariant> VecSigFiles, wxVector<wxVariant> VecIOFiles)
{
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != nullptr) 
    {
        wxString path(currentPath);
        wxString fullPath = path+"/path.conf";
        std::ofstream file(fullPath.c_str());
        if (file.is_open()) 
        {
            file << "SignalPath:\n";
            for(wxVector<wxVariant>::iterator it=VecSigFiles.begin(); it!=VecSigFiles.end(); it++)
            {
                file << (*(it)).GetString() << "\n";
            }
            file << "IOPath:\n";
            for(wxVector<wxVariant>::iterator it=VecIOFiles.begin(); it!=VecIOFiles.end(); it++)
            {
                file << (*(it)).GetString() << "\n";
            }
            file.close();
            // std::cout << "File overwritten successfully." << std::endl;
        } 
        else
        {
            // std::cout << "Failed to open the file." << std::endl;
        }
    }
}


unsigned int checkPathAddList(wxFileName filePath, wxDataViewListCtrl* m_dataViewListCtrl)
{
    if(filePath == "")
    {
        return FILE_NULL;
    }
    else if (filePath.FileExists()) // if file exists
    {
        // judge the file weather in file list
        int rows = m_dataViewListCtrl->GetItemCount();
        for(int i=0; i<rows; i++)
        {
            wxString path = m_dataViewListCtrl ->GetTextValue(i,1);
            if(path == filePath.GetFullPath())
            {
                return FILE_ALREADY_EXIST;
            }
        }
        return FILE_MEET_ADD_CONDITION;
    }
    else
    {
        return FILE_NOT_EXIST;
    }
}

unsigned int checkPathModifyList(unsigned int row, unsigned int col, wxDataViewListCtrl* m_dataViewListCtrl)
{
    wxString filePathStr = m_dataViewListCtrl->GetTextValue(row, col);
    wxFileName filePath = wxFileName(filePathStr);

    if(filePath == "")
    {
        return FILE_NULL;
    }
    else if (filePath.FileExists()) // if file exists
    {
        // judge the file weather in file list
        int rows = m_dataViewListCtrl->GetItemCount();
        for(int i=0; i<rows; i++)
        {
            if (i==row)
            {
                continue;
            }
            wxString path = m_dataViewListCtrl ->GetTextValue(i,1);
            if(path == filePath.GetFullPath())
            {
                return FILE_ALREADY_EXIST;
            }
        }
        return FILE_MEET_MODIFY_CONDITION;
    }
    else
    {
        return FILE_NOT_EXIST;
    }
}

wxBoxSizer* GetBoxSizerFromPanel(wxPanel* panel)
{
    if (panel)
    {
        wxSizer* sizer = panel->GetSizer();
        if (sizer && sizer->IsKindOf(wxCLASSINFO(wxBoxSizer)))
        {
            return static_cast<wxBoxSizer*>(sizer);
        }
    }
    return nullptr;
}

// hidden or show window in sizer
void HideOrShowAllControls(wxSizer* sizer, wxString type)
{
    if (!sizer)
        return;

    wxSizerItemList& items = sizer->GetChildren();
    for (wxSizerItemList::iterator it = items.begin(); it != items.end(); ++it)
    {
        wxSizerItem* item = *it;
        wxWindow* window = item->GetWindow();

        if (window && type=="hidden")
        {
            window->Show(false);
        }
        else if (window && type=="show")
        {
            window->Show(true);
        }

        wxSizer* subSizer = item->GetSizer();
        if (subSizer)
        {
            HideOrShowAllControls(subSizer, type);
        }
    }
}
