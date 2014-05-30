#ifndef GUI_MAINFRAME_HH
#   define GUI_DABBLE_MAINFRAME_HH
#include "wx/aui/aui.h"
namespace gui
{

    class MainFrame : public wxFrame
    {
        public:
            MainFrame(wxWindow* parent,
                    wxWindowID id,
                    const wxString& title,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);

            ~MainFrame();

        private:
            wxAuiManager m_mgr;

            void OnExit(wxCommandEvent& evt);

            enum
            {
                ID_OscSrc = wxID_HIGHEST+1,
                ID_Gain,
                ID_Unknown
            };
            DECLARE_EVENT_TABLE()

    };
}
#endif
