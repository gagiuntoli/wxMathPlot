#include <math.h>
#include <mathplot.h>
#include <wx/brush.h>
#include <wx/filename.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/log.h>
#include <wx/peninfobase.h>
#include <wx/print.h>
#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/wxprec.h>

class MyFrame : public wxFrame {
 public:
  MyFrame() : wxFrame(nullptr, wxID_ANY, wxT("chart with points"), wxDefaultPosition, wxSize(500, 500)) {
    m_plot = new mpWindow(this, wxID_ANY);
    mpScaleX *xaxis = new mpScaleX(wxT("X"), mpALIGN_BOTTOM, true, mpX_NORMAL);
    mpScaleY *yaxis = new mpScaleY(wxT("Y"), mpALIGN_LEFT, true);

    xaxis->SetDrawOutsideMargins(false);
    yaxis->SetDrawOutsideMargins(false);

    mpFXYVector *vectorLayer = new mpFXYVector("Vector");

    std::vector<double> vectorx, vectory;
    for (unsigned int p = 0; p < 20; p++) {
      double xcoord = ((double)p - 50.0) * 5.0;
      vectorx.push_back(xcoord);
      vectory.push_back(0.0001 * pow(xcoord, 3));
    }

    vectorLayer->SetData(vectorx, vectory);
    vectorLayer->SetPen(wxPen(*wxBLUE, 7, wxPENSTYLE_SOLID));
    vectorLayer->SetDrawOutsideMargins(false);

    m_plot->SetMargins(60, 60, 60, 60);
    m_plot->AddLayer(xaxis);
    m_plot->AddLayer(yaxis);
    m_plot->AddLayer(vectorLayer);

    m_plot->Fit();
  }

 private:
  mpWindow *m_plot;
};

class MyApp : public wxApp {
 public:
  virtual bool OnInit() {
    wxInitAllImageHandlers();
    wxFrame *frame = new MyFrame();
    frame->Show(TRUE);
    return TRUE;
  }
};

IMPLEMENT_APP(MyApp)
