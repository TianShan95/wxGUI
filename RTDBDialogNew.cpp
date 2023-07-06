#include "RTDBDialogNew.h"

// Init DataViewListCtrlSig
void RTDBDialogNew :: NewDataViewListCtrlSigAndIO()
{
    // fill file picker if there has config file
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != nullptr) 
    {
        std::string path(currentPath);
        std::string fullPath = path+"/path.conf";
        if(access(fullPath.c_str(), F_OK) == 0)
        {
            this->m_filePickerPathFile->SetPath(fullPath);
        }
    }

    // flush DialogNew file list
    RTDBFrame* auiFrame=(RTDBFrame*)this->auiwxWindow;
    wxVector<wxVariant> VecSigFiles = auiFrame->getSigFiles();
    flushDialogFileList(VecSigFiles, this -> m_dataViewListCtrlSig);
    wxVector<wxVariant> VecIOFiles = auiFrame->getIOFiles();
    flushDialogFileList(VecIOFiles, this -> m_dataViewListCtrlIO);
}

// Signal File Add Button
void RTDBDialogNew :: OnButtonClickAddSig( wxCommandEvent& event )
{
    OnButtonClickAdd(this->m_filePickerSig, this->m_dataViewListCtrlSig, this->m_infoCtrlNew);
}

// Signal File Subtract Button
void RTDBDialogNew :: OnButtonClickSubSig( wxCommandEvent& event )
{
    OnButtonClickSub(this->m_dataViewListCtrlSig, this->m_infoCtrlNew);
}

// IO File Add Button
void RTDBDialogNew :: OnButtonClickAddIO( wxCommandEvent& event ) 
{
    OnButtonClickAdd(this->m_filePickerIO, this->m_dataViewListCtrlIO, this->m_infoCtrlNew);
}

// IO File Subtract Button
void RTDBDialogNew :: OnButtonClickSubIO( wxCommandEvent& event )
{
    OnButtonClickSub(this->m_dataViewListCtrlIO, this->m_infoCtrlNew);
}

void RTDBDialogNew :: OnOKButtonClick( wxCommandEvent& event )
{
    // fill Signal and IO file in frame    
    wxVector<wxVariant> VecSigFiles = this->getSigFiles();
    wxVector<wxVariant> VecIOFiles = this->getIOFiles();
    RTDBFrame* auiFrame=(RTDBFrame*)this->auiwxWindow;
    auiFrame->FlushFileList(VecSigFiles, VecIOFiles);
    // destroy dialog
    this->Destroy();
}

// flush dataviewListCtrl
void RTDBDialogNew::OnButtonClickLoad(wxCommandEvent& event)
{
    // get conf file
    wxFileName ConfPath = this -> m_filePickerPathFile -> GetFileName();
    // read file Config File
    std::ifstream file(ConfPath.GetFullPath());

    if (ConfPath.FileExists() && file.is_open()) // if file exists
    {
        // get Signal Files
        std::string line;
        unsigned int mark=0;
        wxVector<wxVariant> SignalFiles;
        wxVector<wxVariant> IOFiles;
        while (std::getline(file, line)) {
            if(line=="SignalPath:") mark=1;
            else if(line=="IOPath:") mark=2;
            else if(mark==1)
            {
                SignalFiles.push_back(wxVariant(line));
            }
            else if(mark==2)
            {
                IOFiles.push_back(wxVariant(line));
            }
        }
        file.close();

        // judge the file weather in file list and remove repeated files
        int rows = this->m_dataViewListCtrlSig->GetItemCount();
        for(int i=0; i<rows; i++)
        {
            wxString path = this->m_dataViewListCtrlSig ->GetTextValue(i,1);
            // traversal Signalvector
            for(wxVector<wxVariant>::iterator it=SignalFiles.begin();it!=SignalFiles.end();)
            {
                if(*(it)==path)
                {
                    SignalFiles.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }

        rows = this->m_dataViewListCtrlIO->GetItemCount();
        for(int i=0; i<rows; i++)
        {
            wxString path = this->m_dataViewListCtrlIO->GetTextValue(i,1);
            // traversal Signalvector
            for(wxVector<wxVariant>::iterator it=IOFiles.begin();it!=IOFiles.end();)
            {
                if(*(it)==path)
                {
                    IOFiles.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }

        // Add files to displayList
        wxVector<wxVariant> data;
        for ( wxVector<wxVariant>::iterator it = SignalFiles.begin(); it != SignalFiles.end(); ++it) 
        {
            data.push_back(false);
            data.push_back(wxVariant(*(it)));
            this->m_dataViewListCtrlSig->AppendItem( data );
            data.clear();
        }

        // Add files to displayList
        for ( wxVector<wxVariant>::iterator it = IOFiles.begin(); it != IOFiles.end(); ++it) 
        {
            data.push_back(false);
            data.push_back(*(it));
            this->m_dataViewListCtrlIO->AppendItem( data );
            data.clear();
        }
        // clear the input dir text
        this -> m_filePickerPathFile ->SetPath("");
    }
}

wxVector<wxVariant> RTDBDialogNew :: getSigFiles()
{
    return getFileFromList(this->m_dataViewListCtrlSig, 1);
}

wxVector<wxVariant> RTDBDialogNew :: getIOFiles()
{
    return getFileFromList(this->m_dataViewListCtrlIO, 1);
}

void RTDBDialogNew :: OnButtonClickCreate( wxCommandEvent& event )
{
    RTDBFrame* auiFrame=(RTDBFrame*)this->auiwxWindow;
    auiFrame->AddTreeCtrl();
}

void RTDBDialogNew :: OnButtonClickSave( wxCommandEvent& event )
{
    wxVector<wxVariant> SigFiles = this->getSigFiles();
    wxVector<wxVariant> IOFiles = this->getIOFiles();
    // rewrite config file
    rewriteConfig(SigFiles, IOFiles);
}


void RTDBDialogNew :: OnDataViewListCtrlItemStartEditingSig( wxDataViewEvent& event )
{
    wxDataViewItem item = event.GetItem();
    
    this -> editRow = this->m_dataViewListCtrlSig->GetSelectedRow();
    this -> editCol = event.GetColumn();

    if(item.IsOk())
    {
        this->preEdit = this->m_dataViewListCtrlSig->GetTextValue(this -> editRow, this -> editCol);
    }
}

void RTDBDialogNew :: OnDataViewListCtrlItemStartEditingIO( wxDataViewEvent& event )
{
    wxDataViewItem item = event.GetItem();
    
    this -> editRow = this->m_dataViewListCtrlIO->GetSelectedRow();
    this -> editCol = event.GetColumn();

    if(item.IsOk())
    {
        this->preEdit = this->m_dataViewListCtrlIO->GetTextValue(this -> editRow, this -> editCol);
    }
}

void RTDBDialogNew :: OnDataViewListCtrlItemEditingDoneSig( wxDataViewEvent& event )
{
    wxDataViewItem item = event.GetItem();
    if(item.IsOk())
    {
        this->postEdit = this->m_dataViewListCtrlSig->GetTextValue(this->editRow, this->editCol);
    }

    unsigned int status=checkPathModifyList(this -> editRow, this -> editCol, this->m_dataViewListCtrlSig);

    if (status!=FILE_MEET_MODIFY_CONDITION)
    {
        this->m_dataViewListCtrlSig->SetValue(wxVariant(preEdit), editRow, editCol);
    }

    switch (status)
    {
        case FILE_NULL:
            m_infoCtrlNew->ShowMessage("Can not add empty Path");
            break;
        case FILE_ALREADY_EXIST:
            m_infoCtrlNew->ShowMessage("Can not add Already exist Path");
            break;
        case FILE_NOT_EXIST:
            m_infoCtrlNew->ShowMessage("Can not add Not exist Path");
            break;
        default:
            m_infoCtrlNew->ShowMessage("Modify File Path Ok");
            break;
    }
}

void RTDBDialogNew :: OnDataViewListCtrlItemEditingDoneIO( wxDataViewEvent& event )
{
    wxDataViewItem item = event.GetItem();
    if(item.IsOk())
    {
        this->postEdit = this->m_dataViewListCtrlIO->GetTextValue(this->editRow, this->editCol);
    }

    unsigned int status=checkPathModifyList(this -> editRow, this -> editCol, this->m_dataViewListCtrlIO);

    if (status!=FILE_MEET_MODIFY_CONDITION)
    {
        this->m_dataViewListCtrlIO->SetValue(wxVariant(preEdit), editRow, editCol);
    }

    switch (status)
    {
        case FILE_NULL:
            m_infoCtrlNew->ShowMessage("Can not add empty Path");
            break;
        case FILE_ALREADY_EXIST:
            m_infoCtrlNew->ShowMessage("Can not add Already exist Path");
            break;
        case FILE_NOT_EXIST:
            m_infoCtrlNew->ShowMessage("Can not add Not exist Path");
            break;
        default:
            m_infoCtrlNew->ShowMessage("Modify File Path Ok");
            break;
    }
}

// Add file Path
void OnButtonClickAdd(wxFilePickerCtrl* m_filePicker, wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1)
{
    // Get signal file path
    wxFileName filePath = m_filePicker ->GetFileName();

    // unsigned int status = checkPathAddList(filePath, m_dataViewListCtrl);
    switch (checkPathAddList(filePath, m_dataViewListCtrl))
    {
        case FILE_NULL:
            m_infoCtrl1->ShowMessage("Can not add empty Path");
            break;
        case FILE_ALREADY_EXIST:
            m_infoCtrl1->ShowMessage("Can not add Already exist Path");
            break;
        case FILE_NOT_EXIST:
            m_infoCtrl1->ShowMessage("Can not add Not exist Path");
            break;
        default:
            wxVector<wxVariant> data;
            // display Signal file in list
            data.push_back( wxVariant(false) );
            data.push_back( wxVariant(filePath.GetFullPath()) );
            m_dataViewListCtrl->AppendItem( data );
            // clear the input dir text
            m_filePicker ->SetPath("");
            m_infoCtrl1->ShowMessage("Add File(s) Path Ok");
            break;
    }
}

// Subtract Muti File(s) path
void OnButtonClickSub(wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1)
{
    // traversal Signal File list and get Selected file
    int rows = m_dataViewListCtrl->GetItemCount();
    int a=0;
    for(int i=0; i<(rows-a); i++)
    {
        if(m_dataViewListCtrl->GetToggleValue(i,0))
        {
            m_dataViewListCtrl->DeleteItem(i);
            i--;
            a++;
        }
    }
    m_infoCtrl1->ShowMessage("Delete file(s) Path Ok");
}