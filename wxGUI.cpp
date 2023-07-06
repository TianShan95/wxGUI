///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxGUI.h"

///////////////////////////////////////////////////////////////////////////

AuiFrame::AuiFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_ALLOW_FLOATING|wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_TRANSPARENT_DRAG);
	
	m_menubarMain = new wxMenuBar( wxMB_DOCKABLE );
	m_menuOperation = new wxMenu();
	wxMenuItem* m_menuItemNew;
	m_menuItemNew = new wxMenuItem( m_menuOperation, wxID_ANY, wxString( wxT("New...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuOperation->Append( m_menuItemNew );
	
	wxMenuItem* m_menuItemDelete;
	m_menuItemDelete = new wxMenuItem( m_menuOperation, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuOperation->Append( m_menuItemDelete );
	
	m_menubarMain->Append( m_menuOperation, wxT("Operation") ); 
	
	m_menuAccess = new wxMenu();
	wxMenuItem* m_menuItemConnect;
	m_menuItemConnect = new wxMenuItem( m_menuAccess, wxID_ANY, wxString( wxT("Connect") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuAccess->Append( m_menuItemConnect );
	
	wxMenuItem* m_menuItemDisconnect;
	m_menuItemDisconnect = new wxMenuItem( m_menuAccess, wxID_ANY, wxString( wxT("Disconnect") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuAccess->Append( m_menuItemDisconnect );
	
	m_menubarMain->Append( m_menuAccess, wxT("Access") ); 
	
	m_menuView = new wxMenu();
	wxMenuItem* m_menuItemVariable;
	m_menuItemVariable = new wxMenuItem( m_menuView, wxID_ANY, wxString( wxT("Variable") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemVariable->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItemVariable->SetBitmap( wxNullBitmap );
	#endif
	m_menuView->Append( m_menuItemVariable );
	
	wxMenuItem* m_menuItemFiles;
	m_menuItemFiles = new wxMenuItem( m_menuView, wxID_ANY, wxString( wxT("Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemFiles );
	
	m_menuView->AppendSeparator();
	
	wxMenuItem* m_menuItemMessage;
	m_menuItemMessage = new wxMenuItem( m_menuView, wxID_ANY, wxString( wxT("Message") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemMessage );
	
	wxMenuItem* m_menuItemLog;
	m_menuItemLog = new wxMenuItem( m_menuView, wxID_ANY, wxString( wxT("Log") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemLog );
	
	m_menubarMain->Append( m_menuView, wxT("View") ); 
	
	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuItemAbout;
	m_menuItemAbout = new wxMenuItem( m_menuHelp, wxID_ANY, wxString( wxT("About...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuHelp->Append( m_menuItemAbout );
	
	m_menubarMain->Append( m_menuHelp, wxT("Help") ); 
	
	this->SetMenuBar( m_menubarMain );
	
	m_toolBarMain = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_toolBarMain->SetToolSeparation( 2 );
	m_toolNew = m_toolBarMain->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/24pix/file-add-line.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Files"), wxEmptyString, NULL ); 
	
	m_toolDelete = m_toolBarMain->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/24pix/close-circle-fill.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBarMain->AddSeparator(); 
	
	m_toolConnect = m_toolBarMain->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/24pix/link-m.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolDisconnect = m_toolBarMain->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/24pix/link-unlink-m.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBarMain->Realize();
	m_mgr.AddPane( m_toolBarMain, wxAuiPaneInfo() .Top() .CaptionVisible( false ).CloseButton( false ).Dock().Resizable().FloatingSize( wxDefaultSize ) );
	
	
	m_splitterMain = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_splitterMain->Connect( wxEVT_IDLE, wxIdleEventHandler( AuiFrame::m_splitterMainOnIdle ), NULL, this );
	
	m_mgr.AddPane( m_splitterMain, wxAuiPaneInfo() .Center() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Dock().Resizable().FloatingSize( wxDefaultSize ) );
	
	m_panelTree = new wxPanel( m_splitterMain, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_treeCtrlHeader = new wxTreeCtrl( m_panelTree, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_treeCtrlHeader->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );
	
	bSizer14->Add( m_treeCtrlHeader, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	m_panelTree->SetSizer( bSizer14 );
	m_panelTree->Layout();
	bSizer14->Fit( m_panelTree );
	m_panelDisplay = new wxPanel( m_splitterMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebookDisplay = new wxAuiNotebook( m_panelDisplay, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxAUI_NB_DEFAULT_STYLE|wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TOP|wxAUI_NB_WINDOWLIST_BUTTON );
	m_auinotebookDisplay->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );
	
	m_panelVariable = new wxPanel( m_auinotebookDisplay, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_gridVariable = new wxGrid( m_panelVariable, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridVariable->CreateGrid( 10, 10 );
	m_gridVariable->EnableEditing( true );
	m_gridVariable->EnableGridLines( true );
	m_gridVariable->EnableDragGridSize( false );
	m_gridVariable->SetMargins( 0, 0 );
	
	// Columns
	m_gridVariable->AutoSizeColumns();
	m_gridVariable->EnableDragColMove( true );
	m_gridVariable->EnableDragColSize( true );
	m_gridVariable->SetColLabelSize( 30 );
	m_gridVariable->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridVariable->AutoSizeRows();
	m_gridVariable->EnableDragRowSize( true );
	m_gridVariable->SetRowLabelSize( 50 );
	m_gridVariable->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridVariable->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer21->Add( m_gridVariable, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelVariable->SetSizer( bSizer21 );
	m_panelVariable->Layout();
	bSizer21->Fit( m_panelVariable );
	m_auinotebookDisplay->AddPage( m_panelVariable, wxT("Variable"), false, wxNullBitmap );
	m_panelFiles = new wxPanel( m_auinotebookDisplay, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText6 = new wxStaticText( m_panelFiles, wxID_ANY, wxT("Signal Path(s):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer3->Add( m_staticText6, 0, wxALL, 5 );
	
	m_dataViewListCtrlSigFiles = new wxDataViewListCtrl( m_panelFiles, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0|wxALWAYS_SHOW_SB|wxHSCROLL|wxVSCROLL );
	bSizer3->Add( m_dataViewListCtrlSigFiles, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText7 = new wxStaticText( m_panelFiles, wxID_ANY, wxT("IO Path(s):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer3->Add( m_staticText7, 0, wxALL, 5 );
	
	m_dataViewListCtrlIOFiles = new wxDataViewListCtrl( m_panelFiles, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_dataViewListCtrlIOFiles, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelFiles->SetSizer( bSizer3 );
	m_panelFiles->Layout();
	bSizer3->Fit( m_panelFiles );
	m_auinotebookDisplay->AddPage( m_panelFiles, wxT("Files"), false, wxNullBitmap );
	
	bSizer15->Add( m_auinotebookDisplay, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	m_panelDisplay->SetSizer( bSizer15 );
	m_panelDisplay->Layout();
	bSizer15->Fit( m_panelDisplay );
	m_splitterMain->SplitVertically( m_panelTree, m_panelDisplay, 250 );
	m_panelInfo = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( m_panelInfo, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).BestSize( wxSize( -1,300 ) ) );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebookInfo = new wxAuiNotebook( m_panelInfo, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxAUI_NB_DEFAULT_STYLE );
	m_panelMessage = new wxPanel( m_auinotebookInfo, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBarMessage = new wxToolBar( m_panelMessage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	searchIcon = m_toolBarMessage->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/18pix/file-search-line-18pix.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_searchCtrlMessage = new wxSearchCtrl( m_toolBarMessage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrlMessage->ShowSearchButton( true );
	#endif
	m_searchCtrlMessage->ShowCancelButton( true );
	m_toolBarMessage->AddControl( m_searchCtrlMessage );
	down = m_toolBarMessage->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/18pix/arrow-down-line-18pix.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	up = m_toolBarMessage->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/18pix/arrow-up-line-18pix.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	save = m_toolBarMessage->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icon/18pix/save-3-fill-18pix.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBarMessage->Realize(); 
	
	bSizer2->Add( m_toolBarMessage, 0, 0, 0 );
	
	m_richText3 = new wxRichTextCtrl( m_panelMessage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer2->Add( m_richText3, 1, wxEXPAND | wxALL, 5 );
	
	m_staticText5 = new wxStaticText( m_panelMessage, wxID_ANY, wxT("Logged in: admin@localhost"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer2->Add( m_staticText5, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panelMessage->SetSizer( bSizer2 );
	m_panelMessage->Layout();
	bSizer2->Fit( m_panelMessage );
	m_auinotebookInfo->AddPage( m_panelMessage, wxT("Message"), true, wxNullBitmap );
	m_panelLog = new wxPanel( m_auinotebookInfo, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebookInfo->AddPage( m_panelLog, wxT("Log"), false, wxNullBitmap );
	
	bSizer12->Add( m_auinotebookInfo, 1, wxEXPAND | wxALL, 0 );
	
	
	m_panelInfo->SetSizer( bSizer12 );
	m_panelInfo->Layout();
	bSizer12->Fit( m_panelInfo );
	
	m_mgr.Update();
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItemNew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionOperationNew ) );
	this->Connect( m_menuItemDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionOperationDelete ) );
	this->Connect( m_menuItemVariable->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewVariable ) );
	this->Connect( m_menuItemFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewFiles ) );
	this->Connect( m_menuItemMessage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewMessage ) );
	this->Connect( m_menuItemLog->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewLog ) );
	this->Connect( m_toolNew->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( AuiFrame::OnToolClickedNew ) );
	this->Connect( m_toolDelete->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( AuiFrame::OnToolClickedDelete ) );
	m_treeCtrlHeader->Connect( wxEVT_COMMAND_TREE_GET_INFO, wxTreeEventHandler( AuiFrame::OnTreeGetInfo ), NULL, this );
	m_auinotebookDisplay->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( AuiFrame::OnAuiNotebookPageCloseDisplay ), NULL, this );
	m_gridVariable->Connect( wxEVT_GRID_EDITOR_HIDDEN, wxGridEventHandler( AuiFrame::OnGridEditorHiddenVariable ), NULL, this );
	m_auinotebookInfo->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( AuiFrame::OnAuiNotebookPageCloseInfo ), NULL, this );
}

AuiFrame::~AuiFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionOperationNew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionOperationDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewVariable ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewFiles ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewMessage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AuiFrame::OnMenuSelectionViewLog ) );
	this->Disconnect( m_toolNew->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( AuiFrame::OnToolClickedNew ) );
	this->Disconnect( m_toolDelete->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( AuiFrame::OnToolClickedDelete ) );
	m_treeCtrlHeader->Disconnect( wxEVT_COMMAND_TREE_GET_INFO, wxTreeEventHandler( AuiFrame::OnTreeGetInfo ), NULL, this );
	m_auinotebookDisplay->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( AuiFrame::OnAuiNotebookPageCloseDisplay ), NULL, this );
	m_gridVariable->Disconnect( wxEVT_GRID_EDITOR_HIDDEN, wxGridEventHandler( AuiFrame::OnGridEditorHiddenVariable ), NULL, this );
	m_auinotebookInfo->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( AuiFrame::OnAuiNotebookPageCloseInfo ), NULL, this );
	
	m_mgr.UnInit();
	
}

DialogNew::DialogNew( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_infoCtrlNew = new wxInfoBar( this );
	m_infoCtrlNew->SetShowHideEffects( wxSHOW_EFFECT_BLEND, wxSHOW_EFFECT_BLEND );
	m_infoCtrlNew->SetEffectDuration( 2000 );
	m_infoCtrlNew->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_infoCtrlNew->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );
	m_infoCtrlNew->SetBackgroundColour( wxColour( 26, 26, 26 ) );
	
	bSizer4->Add( m_infoCtrlNew, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Signal File(s):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 0, wxALL|wxEXPAND, 5 );
	
	m_scrolledWindowSig = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowSig->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_dataViewListCtrlSig = new wxDataViewListCtrl( m_scrolledWindowSig, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE|wxDV_ROW_LINES|wxALWAYS_SHOW_SB|wxVSCROLL );
	bSizer7->Add( m_dataViewListCtrlSig, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowSig->SetSizer( bSizer7 );
	m_scrolledWindowSig->Layout();
	bSizer7->Fit( m_scrolledWindowSig );
	bSizer4->Add( m_scrolledWindowSig, 3, wxEXPAND | wxALL, 5 );
	
	m_panelSig = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( m_panelSig, wxID_ANY, wxT("File Path:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer8->Add( m_staticText7, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_filePickerSig = new wxFilePickerCtrl( m_panelSig, wxID_ANY, wxEmptyString, wxT("Select a Signal DB file"), wxT("*.db"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_OPEN|wxFLP_SMALL|wxFLP_USE_TEXTCTRL|wxALWAYS_SHOW_SB|wxFULL_REPAINT_ON_RESIZE );
	bSizer8->Add( m_filePickerSig, 1, wxALIGN_CENTER, 5 );
	
	m_bpButtonAddSig = new wxBitmapButton( m_panelSig, wxID_ANY, wxBitmap( wxT("icon/18pix/add-line (1).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_bpButtonAddSig, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_bpButtonSubSig = new wxBitmapButton( m_panelSig, wxID_ANY, wxBitmap( wxT("icon/18pix/subtract-fill (1).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButtonSubSig, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	m_panelSig->SetSizer( bSizer8 );
	m_panelSig->Layout();
	bSizer8->Fit( m_panelSig );
	bSizer4->Add( m_panelSig, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline211 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline211, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("IO File(s):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer4->Add( m_staticText51, 0, wxALL, 5 );
	
	m_scrolledWindowIO = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindowIO->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	m_dataViewListCtrlIO = new wxDataViewListCtrl( m_scrolledWindowIO, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_MULTIPLE|wxDV_ROW_LINES );
	m_dataViewListCtrlIO->SetExtraStyle( wxWS_EX_PROCESS_UI_UPDATES );
	m_dataViewListCtrlIO->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );
	
	bSizer71->Add( m_dataViewListCtrlIO, 1, wxALL|wxEXPAND, 5 );
	
	
	m_scrolledWindowIO->SetSizer( bSizer71 );
	m_scrolledWindowIO->Layout();
	bSizer71->Fit( m_scrolledWindowIO );
	bSizer4->Add( m_scrolledWindowIO, 3, wxEXPAND | wxALL, 5 );
	
	m_panelIO = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText71 = new wxStaticText( m_panelIO, wxID_ANY, wxT("File Path:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	bSizer81->Add( m_staticText71, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_filePickerIO = new wxFilePickerCtrl( m_panelIO, wxID_ANY, wxEmptyString, wxT("Select an IO DB file"), wxT("*.db"), wxDefaultPosition, wxDefaultSize, wxFLP_CHANGE_DIR|wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_SMALL|wxFLP_USE_TEXTCTRL|wxALWAYS_SHOW_SB|wxFULL_REPAINT_ON_RESIZE );
	m_filePickerIO->SetMinSize( wxSize( 350,-1 ) );
	
	bSizer81->Add( m_filePickerIO, 1, wxALIGN_CENTER, 5 );
	
	m_bpButtonAddIO = new wxBitmapButton( m_panelIO, wxID_ANY, wxBitmap( wxT("icon/18pix/add-line (1).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_bpButtonAddIO, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_bpButtonSubIO = new wxBitmapButton( m_panelIO, wxID_ANY, wxBitmap( wxT("icon/18pix/subtract-fill (1).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer81->Add( m_bpButtonSubIO, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	m_panelIO->SetSizer( bSizer81 );
	m_panelIO->Layout();
	bSizer81->Fit( m_panelIO );
	bSizer4->Add( m_panelIO, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Config Path:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer4->Add( m_staticText10, 0, wxALL, 5 );
	
	m_panelConf = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_filePickerPathFile = new wxFilePickerCtrl( m_panelConf, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_SMALL|wxFLP_USE_TEXTCTRL );
	bSizer9->Add( m_filePickerPathFile, 1, wxALIGN_CENTER, 0 );
	
	m_buttonLoad = new wxButton( m_panelConf, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_buttonLoad, 0, wxALL, 5 );
	
	
	m_panelConf->SetSizer( bSizer9 );
	m_panelConf->Layout();
	bSizer9->Fit( m_panelConf );
	bSizer4->Add( m_panelConf, 0, wxALL|wxEXPAND, 5 );
	
	m_panelBottom = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	gSizer3 = new wxGridSizer( 0, 3, 0, 0 );
	
	m_buttonSave = new wxButton( m_panelBottom, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_buttonSave, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonCreate = new wxButton( m_panelBottom, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_buttonCreate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sdbSizer8 = new wxStdDialogButtonSizer();
	m_sdbSizer8OK = new wxButton( m_panelBottom, wxID_OK );
	m_sdbSizer8->AddButton( m_sdbSizer8OK );
	m_sdbSizer8Cancel = new wxButton( m_panelBottom, wxID_CANCEL );
	m_sdbSizer8->AddButton( m_sdbSizer8Cancel );
	m_sdbSizer8->Realize();
	
	gSizer3->Add( m_sdbSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	m_panelBottom->SetSizer( gSizer3 );
	m_panelBottom->Layout();
	gSizer3->Fit( m_panelBottom );
	bSizer4->Add( m_panelBottom, 0, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_dataViewListCtrlSig->Connect( wxEVT_COMMAND_DATAVIEW_ITEM_EDITING_DONE, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemEditingDoneSig ), NULL, this );
	m_dataViewListCtrlSig->Connect( wxEVT_COMMAND_DATAVIEW_ITEM_START_EDITING, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemStartEditingSig ), NULL, this );
	m_bpButtonAddSig->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickAddSig ), NULL, this );
	m_bpButtonSubSig->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSubSig ), NULL, this );
	m_dataViewListCtrlIO->Connect( wxEVT_COMMAND_DATAVIEW_ITEM_EDITING_DONE, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemEditingDoneIO ), NULL, this );
	m_dataViewListCtrlIO->Connect( wxEVT_COMMAND_DATAVIEW_ITEM_START_EDITING, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemStartEditingIO ), NULL, this );
	m_bpButtonAddIO->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickAddIO ), NULL, this );
	m_bpButtonSubIO->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSubIO ), NULL, this );
	m_buttonLoad->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickLoad ), NULL, this );
	m_buttonSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSave ), NULL, this );
	m_buttonCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickCreate ), NULL, this );
	m_sdbSizer8OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnOKButtonClick ), NULL, this );
}

DialogNew::~DialogNew()
{
	// Disconnect Events
	m_dataViewListCtrlSig->Disconnect( wxEVT_COMMAND_DATAVIEW_ITEM_EDITING_DONE, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemEditingDoneSig ), NULL, this );
	m_dataViewListCtrlSig->Disconnect( wxEVT_COMMAND_DATAVIEW_ITEM_START_EDITING, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemStartEditingSig ), NULL, this );
	m_bpButtonAddSig->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickAddSig ), NULL, this );
	m_bpButtonSubSig->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSubSig ), NULL, this );
	m_dataViewListCtrlIO->Disconnect( wxEVT_COMMAND_DATAVIEW_ITEM_EDITING_DONE, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemEditingDoneIO ), NULL, this );
	m_dataViewListCtrlIO->Disconnect( wxEVT_COMMAND_DATAVIEW_ITEM_START_EDITING, wxDataViewEventHandler( DialogNew::OnDataViewListCtrlItemStartEditingIO ), NULL, this );
	m_bpButtonAddIO->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickAddIO ), NULL, this );
	m_bpButtonSubIO->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSubIO ), NULL, this );
	m_buttonLoad->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickLoad ), NULL, this );
	m_buttonSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickSave ), NULL, this );
	m_buttonCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnButtonClickCreate ), NULL, this );
	m_sdbSizer8OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogNew::OnOKButtonClick ), NULL, this );
	
}
