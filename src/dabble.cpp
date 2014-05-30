#include "wx/wx.h"
#include "dabble.hh"
#include "mainframe.hh"

IMPLEMENT_APP(Dabble)

bool Dabble::OnInit()
{
    wxFrame *frame = new gui::MainFrame(
            0, 
            -1, 
            _T("Dabble"), 
            wxDefaultPosition, 
            wxSize(800, 600));

    //frame->CreateStatusBar();
    //frame->SetStatusText(_T("Hello, from Dabble! "));
    //frame->Show(true);
    //SetTopWindow(frame);
    frame->Show();
    return true;
}
