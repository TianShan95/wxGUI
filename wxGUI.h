///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXGUI_H__
#define __WXGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/dataview.h>
#include <wx/aui/auibook.h>
#include <wx/splitter.h>
#include <wx/srchctrl.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/infobar.h>
#include <wx/scrolwin.h>
#include <wx/filepicker.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class AuiFrame
///////////////////////////////////////////////////////////////////////////////
class AuiFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubarMain;
		wxMenu* m_menuOperation;
		wxMenu* m_menuAccess;
		wxMenu* m_menuView;
		wxMenu* m_menuHelp;
		wxToolBar* m_toolBarMain;
		wxToolBarToolBase* m_toolNew; 
		wxToolBarToolBase* m_toolDelete; 
		wxToolBarToolBase* m_toolConnect; 
		wxToolBarToolBase* m_toolDisconnect; 
		wxSplitterWindow* m_splitterMain;
		wxPanel* m_panelTree;
		wxTreeCtrl* m_treeCtrlHeader;
		wxPanel* m_panelDisplay;
		wxAuiNotebook* m_auinotebookDisplay;
		wxPanel* m_panelVariable;
		wxGrid* m_gridVariable;
		wxPanel* m_panelFiles;
		wxStaticText* m_staticText6;
		wxDataViewListCtrl* m_dataViewListCtrlSigFiles;
		wxStaticText* m_staticText7;
		wxDataViewListCtrl* m_dataViewListCtrlIOFiles;
		wxPanel* m_panelInfo;
		wxAuiNotebook* m_auinotebookInfo;
		wxPanel* m_panelMessage;
		wxToolBar* m_toolBarMessage;
		wxToolBarToolBase* searchIcon; 
		wxSearchCtrl* m_searchCtrlMessage;
		wxToolBarToolBase* down; 
		wxToolBarToolBase* up; 
		wxToolBarToolBase* save; 
		wxRichTextCtrl* m_richText3;
		wxStaticText* m_staticText5;
		wxPanel* m_panelLog;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMenuSelectionOperationNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionOperationDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionViewVariable( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionViewFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionViewMessage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelectionViewLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolClickedNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolClickedDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTreeGetInfo( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnAuiNotebookPageCloseDisplay( wxAuiNotebookEvent& event ) { event.Skip(); }
		virtual void OnGridEditorHiddenVariable( wxGridEvent& event ) { event.Skip(); }
		virtual void OnAuiNotebookPageCloseInfo( wxAuiNotebookEvent& event ) { event.Skip(); }
		
	
	public:
		
		AuiFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RTDB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 569,634 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL|wxVSCROLL );
		wxAuiManager m_mgr;
		
		~AuiFrame();
		
		void m_splitterMainOnIdle( wxIdleEvent& )
		{
			m_splitterMain->SetSashPosition( 250 );
			m_splitterMain->Disconnect( wxEVT_IDLE, wxIdleEventHandler( AuiFrame::m_splitterMainOnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogNew
///////////////////////////////////////////////////////////////////////////////
class DialogNew : public wxDialog 
{
	private:
		wxGridSizer* gSizer3;
	
	protected:
		wxInfoBar* m_infoCtrlNew;
		wxStaticText* m_staticText4;
		wxScrolledWindow* m_scrolledWindowSig;
		wxDataViewListCtrl* m_dataViewListCtrlSig;
		wxPanel* m_panelSig;
		wxStaticText* m_staticText7;
		wxFilePickerCtrl* m_filePickerSig;
		wxBitmapButton* m_bpButtonAddSig;
		wxBitmapButton* m_bpButtonSubSig;
		wxStaticLine* m_staticline211;
		wxStaticText* m_staticText51;
		wxScrolledWindow* m_scrolledWindowIO;
		wxDataViewListCtrl* m_dataViewListCtrlIO;
		wxPanel* m_panelIO;
		wxStaticText* m_staticText71;
		wxFilePickerCtrl* m_filePickerIO;
		wxBitmapButton* m_bpButtonAddIO;
		wxBitmapButton* m_bpButtonSubIO;
		wxStaticLine* m_staticline21;
		wxStaticText* m_staticText10;
		wxPanel* m_panelConf;
		wxFilePickerCtrl* m_filePickerPathFile;
		wxButton* m_buttonLoad;
		wxPanel* m_panelBottom;
		wxButton* m_buttonSave;
		wxButton* m_buttonCreate;
		wxStdDialogButtonSizer* m_sdbSizer8;
		wxButton* m_sdbSizer8OK;
		wxButton* m_sdbSizer8Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDataViewListCtrlItemEditingDoneSig( wxDataViewEvent& event ) { event.Skip(); }
		virtual void OnDataViewListCtrlItemStartEditingSig( wxDataViewEvent& event ) { event.Skip(); }
		virtual void OnButtonClickAddSig( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSubSig( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDataViewListCtrlItemEditingDoneIO( wxDataViewEvent& event ) { event.Skip(); }
		virtual void OnDataViewListCtrlItemStartEditingIO( wxDataViewEvent& event ) { event.Skip(); }
		virtual void OnButtonClickAddIO( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSubIO( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogNew( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Config"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER ); 
		~DialogNew();
	
};

#endif //__WXGUI_H__
