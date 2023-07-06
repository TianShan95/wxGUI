#ifndef __RTDBFRAME_H__
#define __RTDBFRAME_H__

#include"RTDBDialogNew.h"
#include"wxGUI.h"
#include"utils.h"
#include <fstream>
#include <map>

struct TabData 
{
    wxString name;
    wxWindow* content;
};

class RTDBFrame : public AuiFrame
{
public:
    RTDBFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RTDB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 769,850 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL|wxVSCROLL ) : AuiFrame( parent, id, title, pos, size, style )
    {
        // create app icon
        wxIcon icon("icon/hirain.png", wxBITMAP_TYPE_PNG);
        this->SetIcon(icon);
        // store frame and its name to map
        allTabs["Variable"]=this->m_panelVariable;
        allTabs["Files"]=this->m_panelFiles;
        allTabs["Message"]=this->m_panelMessage;
        allTabs["Log"]=this->m_panelLog;
    };
    void initComponet();
    void InitVariableList();
    void InitFileList();
    void InitTreeList();
    void MessageWelcome();
    void AddTreeCtrl();
    void FlushFileList(wxVector<wxVariant> VecSigFiles,  wxVector<wxVariant> VecIOFiles);
    wxVector<wxVariant> getSigFiles();
    wxVector<wxVariant> getIOFiles();
    friend wxVector<wxVariant> getFileFromList(wxDataViewListCtrl* wxDVListCtr);

protected:
    wxTreeItemId rootId;
    std::map<wxString, wxWindow*> allTabs;
    wxVector<TabData> closedTabs;
    virtual void OnMenuSelectionOperationNew( wxCommandEvent& event ) override;
    virtual void OnMenuSelectionOperationDelete( wxCommandEvent& event ) override;
    virtual void OnMenuSelectionViewVariable( wxCommandEvent& event ) override;
	virtual void OnMenuSelectionViewFiles( wxCommandEvent& event ) override;
	virtual void OnMenuSelectionViewMessage( wxCommandEvent& event ) override;
	virtual void OnMenuSelectionViewLog( wxCommandEvent& event ) override;
    virtual void OnToolClickedNew( wxCommandEvent& event ) override;
	virtual void OnToolClickedDelete( wxCommandEvent& event ) override;
    virtual void OnAuiNotebookPageCloseDisplay( wxAuiNotebookEvent& event ) override;
    virtual void OnAuiNotebookPageCloseInfo( wxAuiNotebookEvent& event ) override;
};

TabData OnAuiNotebookPageClose(wxAuiNotebookEvent& event, wxAuiNotebook* AuiNotebook, wxVector<TabData> &tabVec);
void OnMenuSelectionOpenNotebook(wxAuiNotebook* AuiNotebook,wxVector<TabData> &tabVec, wxString name);

#endif //  __RTDBFRAME_H__