#pragma once

#include <wx/wx.h>


class MainFrame : public wxFrame {

public:
    explicit MainFrame(const wxString & title);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

//    void OnButtonClicked(wxCommandEvent& event);

//    void OnSliderChanged(wxCommandEvent& event);
//    void OnTextChanged(wxCommandEvent& event);

//    void OnAnyButtonClicked(wxCommandEvent& event);
//    void OnButton1Clicked(wxCommandEvent& event);
//    void OnButton2Clicked(wxCommandEvent& event);
//
//    void OnClose(wxCloseEvent& event);

//    void OnMouseEvent(wxMouseEvent& event);

    void onKeyEvent(wxKeyEvent& event);

    // lesson 5 - EVENTS
//    wxDECLARE_EVENT_TABLE();
};