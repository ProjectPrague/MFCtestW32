//-----------------------------------------------------------------------------------------
#include <afxwin.h>      //MFC core and standard components
#include "resource.h"    //main symbols
//-----------------------------------------------------------------------------------------
//Globals

CEdit * pOUTPUT;
CButton * pHELLO;

class MAIN_FORM : public CDialog
{
    public:
    MAIN_FORM(CWnd* pParent = NULL): CDialog(MAIN_FORM::IDD, pParent)
    {    }
    // Dialog Data, name of dialog form
	enum{IDD = Interface1};
    protected:
    virtual void DoDataExchange(CDataExchange* pDX) { CDialog::DoDataExchange(pDX); }
    //Called right after constructor. Initialize things here.
    virtual BOOL OnInitDialog() 
    { 
            CDialog::OnInitDialog();
            pOUTPUT = (CEdit *) GetDlgItem(ID_BOX1);
			pHELLO = (CButton *) GetDlgItem(ID_HELLO);

			pOUTPUT->SetWindowText(L"Hello world?");

            //TEST->SetWindowText(L"Hello!");
            return true; 
    }

public:
//--------------------------------------------------------------------------------------
	afx_msg void hello() { HELLOBUTTON(); }
//--------------------------------------------------------------------------------------

	void HELLOBUTTON()
	{
		pOUTPUT->SetWindowText(L"HELLO WORLD!");
		pHELLO->EnableWindow(false);
	};
DECLARE_MESSAGE_MAP()
};
//-----------------------------------------------------------------------------------------

class TheMain : public CWinApp
{
public:
	TheMain() {  }
public:
	virtual BOOL InitInstance()
		{
			CWinApp::InitInstance();
			//SetRegistryKey(_T("Kinect Project")); if you want to use a registery key, you can use this code.
			MAIN_FORM dlg;
			m_pMainWnd = &dlg;
			INT_PTR nResponse = dlg.DoModal();
			return FALSE;
		} //close function
};


//-----------------------------------------------------------------------------------------


//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(MAIN_FORM, CDialog)
	ON_COMMAND(ID_HELLO, hello)
END_MESSAGE_MAP()
//-----------------------------------------------------------------------------------------
TheMain theApp;  //Starts the Application