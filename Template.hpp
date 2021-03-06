#ifndef __BME465_TEMPLATE_HPP__
#define __BME465_TEMPLATE_HPP__
// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"


#ifdef __BORLANDC__
    #pragma hdrstop
#endif


// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/slider.h"
#include "wx/toolbar.h"
#include "wx/utils.h"
#include "wx/image.h"
#include "wx/filedlg.h"
#include "wx/pen.h"
#include "math.h"
#include "image_processor.hpp"
#include <cstdio>
#include <vector>
#include <algorithm>
#include "sliderFrame.hpp"



// Define a new application type, each program should derive a class from wxApp
class MyApp : public wxApp
{
public:
    // override base class virtuals
    // ----------------------------

    // this one is called on application startup and is a good place for the app
    // initialization (doing it here and not in the ctor allows to have an error
    // return: if OnInit() returns false, the application terminates)
    virtual bool OnInit();
};





// Define a new frame type: this is going to be our main frame
class MyFrame : public wxFrame
{
public:
    // ctor(s)
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size,
            long style = wxDEFAULT_FRAME_STYLE);

    // event handlers (these functions should _not_ be virtual)
			
    
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    
    void OnFilter( wxCommandEvent& event );
    
    void OnPaint( wxPaintEvent& event);
    void OnLoad(wxCommandEvent& WXUNUSED(event));
    
    void OnToGray(wxCommandEvent& event);

	void makeSlider(int SliderID, int deflt, int low, int high);	//new lab4
	void sliderHandler(void);
	void sliderWindowCloses(void);

//Area Prototypes
	void OnAreaCalculation(wxCommandEvent&event);	//new lab5
	void OnLButton(wxMouseEvent& event);	//new lab5


	wxImage *masterImage;	
    wxImage *pImage;	


	MySliderFrame *sliderFrame;	//new lab4
	wxSlider *slider;
	int sliderID;
	int sliderValue;
	
//Area Variables	
	int areaindex;				//new lab5
		wxPoint* areaborder;
		int pointNumber;
	double dist;
	
	bool bAreaCalculation;		//new lab5
	bool bleftDown;
	bool bRed;
	

	
	
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE()
};


// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

enum
{
    // menu items
    MENU_FILE_OPEN = wxID_OPEN,
    MENU_FILE_QUIT = wxID_EXIT,
    MENU_FILTER    = 100,
    MENU_FILTER_LP = 101,
    MENU_FILTER_HP = 102,		//lab1
	
	MENU_FILTER_MIN = 103,  //new! lab2
	MENU_FILTER_MED = 104,
	MENU_FILTER_MAX = 105,

	MENU_FILTER_EDGE = 106,	//new! lab3
	MENU_FILTER_BIN = 107,

	MENU_FILTER_2BIN = 110,	//new lab 4!
	SLIDER_ID = 500,
	BIN_SLIDER = 600,

	MENU_AREA = 400,
	MENU_AREA_AREACALCULATION = 401,
	
	ID_AreaCalculation = 300,

	MENU_FILTER_UNDO = 108,

    ID_ToGray = 200,



    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    MENU_HELP_ABOUT = wxID_ABOUT
};

#endif
