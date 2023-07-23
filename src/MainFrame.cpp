#include <MainFrame.h>

#include <wx/spinctrl.h>


enum IDs {
    ID_HELLO = 1,
//    ID_BUTTON = 2,
//    ID_SLIDER = 3,
//    ID_TEXT = 4,
};


// lesson 5 - EVENTS
//wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
//    EVT_BUTTON(ID_BUTTON, MainFrame::OnButtonClicked)
//    EVT_SLIDER(ID_SLIDER, MainFrame::OnSliderChanged)
//    EVT_TEXT(ID_TEXT, MainFrame::OnTextChanged)
//wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString&  title)
    : wxFrame(nullptr, wxID_ANY, title) {

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxStatusBar* statusBar = CreateStatusBar();
//    statusBar->SetDoubleBuffered(true);
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU,& MainFrame::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU,& MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU,& MainFrame::OnExit, this, wxID_EXIT);


//    // lesson 3 - CONTROLS, lesson 4 - STYLES
    wxPanel* panel = new wxPanel(this);
//
//    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);
//
//    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);
//
//    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(0, 150), {400,-1}, wxALIGN_CENTER_HORIZONTAL);
//    staticText->SetBackgroundColour(*wxBLACK);
//
//    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);
//
//    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);
//
//    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(590, 205), wxSize(-1, 125), wxGA_VERTICAL);
//    gauge->SetValue(50);
//
//    wxArrayString choices;
//    choices.Add("Item A");
//    choices.Add("Item D");
//    choices.Add("Item C");
//    choices.Add("Item B");
//
//    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
//    choice->Select(0);
//
//    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(120, -1), wxSP_WRAP);
//
//    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);
//
//    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", {555,450}, wxDefaultSize, choices, 4, wxRA_SPECIFY_ROWS);


//    // lesson 5 - EVENTS
//    wxButton* button = new wxButton(panel, ID_BUTTON, "Button", {300,275}, {200,50});
//    wxSlider* slider = new wxSlider(panel, ID_SLIDER, 0, 0, 100, {300,200}, {200, -1});
//    wxTextCtrl* text = new wxTextCtrl(panel, ID_TEXT, "", {300,375}, {200,-1});


//    // lesson 6 - DYNAMIC EVENTS
//    wxButton* button = new wxButton(panel, wxID_ANY, "Button", {300,275}, {200,50});
//    wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, {300,200}, {200, -1});
//    wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", {300,375}, {200,-1});
//
//    button->Bind(wxEVT_BUTTON,& MainFrame::OnButtonClicked, this);
//    slider->Bind(wxEVT_SLIDER,& MainFrame::OnSliderChanged, this);
//    text->Bind(wxEVT_TEXT,& MainFrame::OnTextChanged, this);
//
//    button->Unbind(wxEVT_BUTTON,& MainFrame::OnButtonClicked, this);


//    // lesson 7 - EVENT PROPAGATION
//    wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", {300,275}, {200,50});
//    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", {300,350}, {200,50});
//
//    this->Bind(wxEVT_BUTTON,& MainFrame::OnAnyButtonClicked, this);
//    button1->Bind(wxEVT_BUTTON,& MainFrame::OnButton1Clicked, this);
//    button2->Bind(wxEVT_BUTTON,& MainFrame::OnButton2Clicked, this);
//
//    this->Bind(wxEVT_CLOSE_WINDOW,& MainFrame::OnClose, this);


//    // lesson 8 - MOUSE EVENTS
//    panel->Bind(wxEVT_MOTION,& MainFrame::OnMouseEvent, this);
//
//    wxButton* button = new wxButton(panel, wxID_ANY, "Button", {300,250}, {200, 100});
//    button->Bind(wxEVT_MOTION,& MainFrame::OnMouseEvent, this);


    // lesson 9 - KEYBOARD EVENTS
    panel->Bind(wxEVT_CHAR, &MainFrame::onKeyEvent, this);
}


void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello world from wxWidgets!");
}


//void MainFrame::OnButtonClicked(wxCommandEvent& event) {
////    wxLogStatus("Button CLicked");
////    wxLogMessage("Button Clicked");
//    wxLogMessage(wxString::Format("Button %d clicked!", event.GetId()));
//}


//void MainFrame::OnSliderChanged(wxCommandEvent& event) {
//    wxString str = wxString::Format("Slider Value: %d", event.GetInt());
//    wxLogStatus(str);
//}
//
//void MainFrame::OnTextChanged(wxCommandEvent& event) {
//    wxString str = wxString::Format("Text: %s", event.GetString());
//    wxLogStatus(str);
//}


//void MainFrame::OnAnyButtonClicked(wxCommandEvent& event) {
//    wxLogMessage("Button Clicked");
//}
//
//void MainFrame::OnButton1Clicked(wxCommandEvent& event) {
//    wxLogStatus("Button 1 Clicked");
//    event.Skip();
//}
//
//void MainFrame::OnButton2Clicked(wxCommandEvent& event) {
//    wxLogStatus("Button 2 Clicked");
//}
//
//
//void MainFrame::OnClose(wxCloseEvent& event) {
////    wxLogMessage("Frame Closed");
//    wxMessageBox("Frame Closed",
//                 "...", wxOK | wxICON_INFORMATION);
//    event.Skip();
//}


//void MainFrame::OnMouseEvent(wxMouseEvent& event) {
////    wxPoint mousePos = event.GetPosition();
//    wxPoint mousePos = ScreenToClient(wxGetMousePosition());
//    wxString message = wxString::Format("Mouse Event Detected! (x=%d, y=%d)", mousePos.x, mousePos.y);
//    wxLogStatus(message);
//}


void MainFrame::onKeyEvent(wxKeyEvent &event) {
    wxChar keyChar = event.GetUnicodeKey();
    if (keyChar == WXK_NONE) {
        int keyCode = event.GetKeyCode();
        wxLogStatus("Key event %d", keyCode);
    } else {
        wxLogStatus("Key event %c", keyChar);
    }
}