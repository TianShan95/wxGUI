#include "wxGUI.h"
#include "RTDBFrame.h"
#include "RTDBDialogNew.h"
#include "utils.h"


// RTDBApp
class RTDBApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        // Set work path as current path
        setWorkPath();

        // Init Frame
        RTDBFrame* frame = new RTDBFrame(NULL);
        frame->initComponet();
        frame->Show(true);
        
        return true;
    }
};

wxIMPLEMENT_APP(RTDBApp);
