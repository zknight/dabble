#include "wx/wx.h"
#include "wx/aui/aui.h"
#include "wx/artprov.h"
#include "mainframe.hh"
#include "osc_src.xpm"
#include "gain.xpm"

gui::MainFrame::MainFrame(
        wxWindow* parent,
        wxWindowID id,
        const wxString& title,
        const wxPoint& pos,
        const wxSize& size,
        long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    m_mgr.SetManagedWindow(this);

    wxMenuBar* mb = new wxMenuBar;

    wxMenu* file_menu = new wxMenu;
    file_menu->Append(wxID_EXIT);
    mb->Append(file_menu, _("&File"));
    
    wxMenu* help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT, _T("&About"));
    mb->Append(help_menu, _("&Help"));

    SetMenuBar(mb);


    // toolbar
    //wxBitmap osc_bmp(wxBITMAP(osc_src));
    //wxBitmap gain_bmp(wxBITMAP(gain));

    wxAuiToolBar* tools = new wxAuiToolBar(
            this, 
            wxID_ANY, 
            wxDefaultPosition,
            wxDefaultSize,
            wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tools->SetToolBitmapSize(wxSize(64,64));
    //tools->AddTool(ID_OscSrc, wxT("Oscillator"), osc_bmp);
    //tools->AddTool(ID_Gain, wxT("Gain"), gain_bmp);
    tools->AddTool(wxID_HIGHEST+1, wxT("Oscillator"), wxBITMAP(osc_src));
    tools->AddTool(wxID_HIGHEST+2, wxT("Gain"), wxBITMAP(gain));
    tools->Realize();

    m_mgr.AddPane(tools, 
            wxAuiPaneInfo().
                Name(wxT("tools")).
                Caption(wxT("Tools")).
                ToolbarPane().Left().
                GripperTop());

    m_mgr.Update();
}

gui::MainFrame::~MainFrame()
{
    m_mgr.UnInit();
}

/////// Event Handlers
using gui::MainFrame;
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
END_EVENT_TABLE()

void gui::MainFrame::OnExit(wxCommandEvent& evt)
{
    Close(true);
}
