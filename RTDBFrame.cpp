#include"RTDBFrame.h"


void RTDBFrame :: initComponet()
{
    this->InitVariableList();
    this->InitFileList();
    this->InitTreeList();
    this->MessageWelcome();
}

void RTDBFrame :: MessageWelcome()
{
    this->m_richText3->BeginFontSize(12);
    this->m_richText3->BeginBold();
    this->m_richText3->WriteText("Welcome to RTDBwxGUI!");
    this->m_richText3->EndBold();
    // this->m_richText3->EndFontSize();
}

void RTDBFrame :: InitTreeList()
{
    this->rootId = this->m_treeCtrlHeader->AddRoot("varpool HeaderInfo");
}

void RTDBFrame :: AddTreeCtrl()
{
    this->m_treeCtrlHeader->DeleteChildren (this->rootId);
    // creat parent node
    wxString parentText = wxString::Format("HIRAIN_RTDB");
    wxTreeItemId parentId = this->m_treeCtrlHeader->AppendItem(this->rootId, parentText);
    // creat children node
    wxString childText = "Name: VARPOOL_HIRAIN_RTDB";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Item Number: 476";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Item Used: 476";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Value Table Size: 3824 bytes";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Item Key: 0x55aa";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Value Key: 0x55ab";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);
        childText = "Status: Ready";
    this->m_treeCtrlHeader->AppendItem(parentId, childText);

    this->m_treeCtrlHeader->ExpandAll();
}

void RTDBFrame :: InitVariableList()
{
    this->m_gridVariable->SetColLabelValue(0, "Name");
    this->m_gridVariable->SetColLabelValue(1, "CVT Type");
    this->m_gridVariable->SetColLabelValue(2, "Point Type");
    this->m_gridVariable->SetColLabelValue(3, "Value");
    this->m_gridVariable->SetColLabelValue(4, "Default Value");
    this->m_gridVariable->SetColLabelValue(5, "EU Conversion a");
    this->m_gridVariable->SetColLabelValue(6, "EU Conversion b");
    this->m_gridVariable->SetColLabelValue(7, "EU Min");
    this->m_gridVariable->SetColLabelValue(8, "EU Max");
    this->m_gridVariable->SetColLabelValue(9, "Number Of Element");
    this->m_gridVariable->AutoSizeColumns();
}

void RTDBFrame :: InitFileList()
{
    // init fileList
    this -> m_dataViewListCtrlSigFiles->AppendTextColumn( "Path(s)" );
    this -> m_dataViewListCtrlIOFiles->AppendTextColumn( "Path(s)" );   
}

void RTDBFrame :: FlushFileList(wxVector<wxVariant> VecSigFiles,  wxVector<wxVariant> VecIOFiles)
{
    flushFrameFileList(VecSigFiles, this -> m_dataViewListCtrlSigFiles);
    flushFrameFileList(VecIOFiles, this -> m_dataViewListCtrlIOFiles);
}

// Open Variable notebook
void RTDBFrame :: OnMenuSelectionViewVariable( wxCommandEvent& event )
{
    OnMenuSelectionOpenNotebook(this->m_auinotebookDisplay, this->closedTabs, "Variable");
    HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelVariable), "show");
    this->m_auinotebookDisplay->SetSelection(this->m_auinotebookDisplay->GetPageIndex(this->allTabs["Variable"]));
}

// Open Files notebook
void RTDBFrame :: OnMenuSelectionViewFiles( wxCommandEvent& event )
{
    OnMenuSelectionOpenNotebook(this->m_auinotebookDisplay, this->closedTabs, "Files");
    HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelFiles), "show");
    this->m_auinotebookDisplay->SetSelection(this->m_auinotebookDisplay->GetPageIndex(this->allTabs["Files"]));
}

// close the tab from AuiNotebookDisplay
void RTDBFrame :: OnAuiNotebookPageCloseDisplay( wxAuiNotebookEvent& event )
{
    // store page control
    TabData tabdata = OnAuiNotebookPageClose( event, this->m_auinotebookDisplay, this->closedTabs);

    // hidden the controls from the page
    if(tabdata.name == "Variable")
    {
        HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelVariable), "hidden");
    }
    else if(tabdata.name == "Files")
    {
        HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelFiles), "hidden");
    }

    // check the last page and hidden all panel
    if(m_auinotebookDisplay->GetPageCount() == 0)
    {
        this->m_panelVariable->Hide();
        this->m_panelFiles->Hide();
    }
    // prevent auinotebook call RemovePage again
    event.Veto();
}

// Open Message notebook
void RTDBFrame :: OnMenuSelectionViewMessage( wxCommandEvent& event )
{
    OnMenuSelectionOpenNotebook(this->m_auinotebookInfo, this->closedTabs, "Message");
    HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelMessage), "show");
    this->m_auinotebookInfo->SetSelection(this->m_auinotebookInfo->GetPageIndex(this->allTabs["Message"]));
}

// Open Log notebook
void RTDBFrame :: OnMenuSelectionViewLog( wxCommandEvent& event )
{
    OnMenuSelectionOpenNotebook(this->m_auinotebookInfo, this->closedTabs, "Log");
    HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelLog), "show");
    this->m_auinotebookInfo->SetSelection(this->m_auinotebookInfo->GetPageIndex(this->allTabs["Log"]));
}

// close the tab from AuiNotebookInfo
void RTDBFrame :: OnAuiNotebookPageCloseInfo( wxAuiNotebookEvent& event )
{
    // store Page Control
    TabData tabdata = OnAuiNotebookPageClose( event, this->m_auinotebookInfo, this->closedTabs);

    // hidden the controls from the page
    if(tabdata.name == "Message")
    {
        HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelMessage), "hidden");
    }
    else if(tabdata.name == "Log")
    {
        HideOrShowAllControls(GetBoxSizerFromPanel(this->m_panelLog), "hidden");
    }

    // check the last page and hidden all panel
    if(m_auinotebookInfo->GetPageCount() == 0)
    {
        this->m_panelMessage->Hide();
        this->m_panelLog->Hide();
    }
    // prevent auinotebook call RemovePage again
    event.Veto();
}

void RTDBFrame :: OnMenuSelectionOperationNew( wxCommandEvent& event )
{
    RTDBDialogNew diglog(this);
    diglog.NewDataViewListCtrlSigAndIO();
    diglog.ShowModal();
}

void RTDBFrame :: OnMenuSelectionOperationDelete( wxCommandEvent& event )
{
    // clear tree list
    this->m_treeCtrlHeader->DeleteChildren (this->rootId);
    // clear Grid Table
    this->m_gridVariable->ClearGrid();
    // fill col label
    this->InitVariableList();
    // delete Frame Files List
    this->m_dataViewListCtrlSigFiles->DeleteAllItems();
    this->m_dataViewListCtrlIOFiles->DeleteAllItems();
}

// Open DialogNew
void RTDBFrame :: OnToolClickedNew( wxCommandEvent& event )
{
    this->OnMenuSelectionOperationNew(event);
}

void RTDBFrame :: OnToolClickedDelete( wxCommandEvent& event )
{
    this->OnMenuSelectionOperationDelete(event);
}

wxVector<wxVariant> RTDBFrame :: getSigFiles()
{
    return getFileFromList(this->m_dataViewListCtrlSigFiles, 0);
}

wxVector<wxVariant> RTDBFrame :: getIOFiles()
{   
    return getFileFromList(this->m_dataViewListCtrlIOFiles, 0);
}


TabData OnAuiNotebookPageClose(wxAuiNotebookEvent& event, wxAuiNotebook* AuiNotebook, wxVector<TabData> &tabVec)
{
    TabData tabData;
    tabData.name = AuiNotebook->GetPageText(event.GetSelection());
    tabData.content = AuiNotebook->GetPage(event.GetSelection());
    tabVec.push_back(tabData);
    AuiNotebook->RemovePage(event.GetSelection());
    return tabData;
}

void OnMenuSelectionOpenNotebook(wxAuiNotebook* AuiNotebook, wxVector<TabData> &tabVec, wxString name)
{
    // int index=-1;
    if (!tabVec.empty())
    {
        for(wxVector<TabData>::iterator it =tabVec.begin(); it != tabVec.end();it++)
        {
            if((*it).name == name)
            {
                wxWindow* closedTabData = (*it).content;
                // Add Page
                AuiNotebook->AddPage(closedTabData,(*it).name, true, wxNullBitmap );
                // show
                AuiNotebook->SetSelection(AuiNotebook->GetPageCount() - 1);
                // remove from vector
                tabVec.erase(it);
                break;
            }
        }
    }
}