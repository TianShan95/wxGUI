#ifndef __RTDBDIALOGNEW_H__
#define __RTDBDIALOGNEW_H__
#include "wxGUI.h"
#include "RTDBFrame.h"
#include <wx/filename.h>
#include <unistd.h>
#include <fstream>

// DialogNew Derived class
class RTDBDialogNew : public DialogNew
{
public:
    
    RTDBDialogNew( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Config"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 520,653 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER) : DialogNew(parent, id, title, pos, size, style)
    {
        auiwxWindow = parent;
    };
    void NewDataViewListCtrlSigAndIO();
    wxVector<wxVariant> getSigFiles();
    wxVector<wxVariant> getIOFiles();
    friend wxVector<wxVariant> getFileFromList(wxDataViewListCtrl* wxDVListCtr);
    friend void OnButtonClickAdd(wxFilePickerCtrl* m_filePicker, wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1);
    friend void OnButtonClickSub(wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1);

protected:
    
    wxWindow* auiwxWindow;
    wxString preEdit;
    wxString postEdit;
    unsigned int editRow;
    unsigned int editCol;
    virtual void OnButtonClickAddSig( wxCommandEvent& event ) override;
    virtual void OnButtonClickSubSig( wxCommandEvent& event ) override;
    virtual void OnButtonClickAddIO( wxCommandEvent& event ) override;
    virtual void OnButtonClickSubIO( wxCommandEvent& event ) override;
    virtual void OnOKButtonClick( wxCommandEvent& event ) override;
    virtual void OnButtonClickLoad( wxCommandEvent& event ) override;
    virtual void OnButtonClickSave( wxCommandEvent& event ) override;
    virtual void OnButtonClickCreate( wxCommandEvent& event ) override;
    virtual void OnDataViewListCtrlItemStartEditingSig( wxDataViewEvent& event ) override;
    virtual void OnDataViewListCtrlItemStartEditingIO( wxDataViewEvent& event ) override;
    virtual void OnDataViewListCtrlItemEditingDoneSig( wxDataViewEvent& event ) override;
    virtual void OnDataViewListCtrlItemEditingDoneIO( wxDataViewEvent& event ) override;
};

void OnButtonClickAdd(wxFilePickerCtrl* m_filePicker, wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1);
void OnButtonClickSub(wxDataViewListCtrl* m_dataViewListCtrl, wxInfoBar* m_infoCtrl1);


#endif //__RTDBDIALOGNEW_H__