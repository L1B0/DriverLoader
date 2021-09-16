
// LoadDriver1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "LoadDriver1.h"
#include "LoadDriver1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SC_HANDLE m_ScmHandle;
SC_HANDLE m_HerService;
LPCSTR SzSysFileName, SzSysFilePath;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CLoadDriver1Dlg 对话框



CLoadDriver1Dlg::CLoadDriver1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOADDRIVER1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoadDriver1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, browser1);
}

BEGIN_MESSAGE_MAP(CLoadDriver1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CLoadDriver1Dlg::UnregisterDriver)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoadDriver1Dlg::RegisterDriver)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoadDriver1Dlg::StartDriver)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CLoadDriver1Dlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_BUTTON4, &CLoadDriver1Dlg::StopDriver)
END_MESSAGE_MAP()


void CLoadDriver1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLoadDriver1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLoadDriver1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLoadDriver1Dlg::UnregisterDriver()
{
	// TODO: 在此添加控件通知处理程序代码
	CString FilePath, FileName;
	GetDlgItem(IDC_MFCEDITBROWSE1)->GetWindowTextW(FilePath);

	// 只要文件名，后缀不要
	int nPos = FilePath.ReverseFind('\\');
	FileName = FilePath.Right(FilePath.GetLength() - nPos - 1);
	nPos = FileName.ReverseFind('.');
	FileName = FileName.Left(nPos);

	LPCSTR lpFilePath = (LPCSTR)(LPCWSTR)(FilePath), lpFileName = (LPCSTR)(LPCWSTR)(FileName);
	MessageBox((LPCWSTR)lpFilePath);


	BOOL status = Remove(lpFileName, lpFilePath);
}


void CLoadDriver1Dlg::RegisterDriver()
{
	// TODO: 在此添加控件通知处理程序代码
		// TODO: 在此添加控件通知处理程序代码
	CString FilePath,FileName;
	GetDlgItem(IDC_MFCEDITBROWSE1)->GetWindowTextW(FilePath);

	// 只要文件名，后缀不要
	int nPos = FilePath.ReverseFind('\\');
	FileName = FilePath.Right(FilePath.GetLength()-nPos-1);
	nPos = FileName.ReverseFind('.');
	FileName = FileName.Left(nPos);

	LPCSTR lpFilePath = (LPCSTR)(LPCWSTR)(FilePath), lpFileName = (LPCSTR)(LPCWSTR)(FileName);
	MessageBox((LPCWSTR)lpFilePath);


	BOOL status = Load(lpFileName, lpFilePath);
}


void CLoadDriver1Dlg::StartDriver()
{

	CString FilePath, FileName;
	GetDlgItem(IDC_MFCEDITBROWSE1)->GetWindowTextW(FilePath);

	// 只要文件名，后缀不要
	int nPos = FilePath.ReverseFind('\\');
	FileName = FilePath.Right(FilePath.GetLength() - nPos - 1);
	nPos = FileName.ReverseFind('.');
	FileName = FileName.Left(nPos);

	LPCSTR lpFilePath = (LPCSTR)(LPCWSTR)(FilePath), lpFileName = (LPCSTR)(LPCWSTR)(FileName);
	MessageBox((LPCWSTR)lpFilePath);


	BOOL status = Start(lpFileName, lpFilePath);
}

void CLoadDriver1Dlg::StopDriver()
{

	CString FilePath, FileName;
	GetDlgItem(IDC_MFCEDITBROWSE1)->GetWindowTextW(FilePath);

	// 只要文件名，后缀不要
	int nPos = FilePath.ReverseFind('\\');
	FileName = FilePath.Right(FilePath.GetLength() - nPos - 1);
	nPos = FileName.ReverseFind('.');
	FileName = FileName.Left(nPos);

	LPCSTR lpFilePath = (LPCSTR)(LPCWSTR)(FilePath), lpFileName = (LPCSTR)(LPCWSTR)(FileName);
	MessageBox((LPCWSTR)lpFilePath);


	BOOL status = Stop(lpFileName, lpFilePath);
}


void CLoadDriver1Dlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	CString str;
	browser1.GetWindowTextW(str);

}

BOOL Load(LPCSTR SzSysFileName, LPCSTR SzSysFilePath)
{
	DWORD m_loadAddDriverError;
	m_ScmHandle = NULL;
	m_HerService = NULL;

	//打开SCM管理器 (获取SCM句柄) - OpenSCManagerA
	m_ScmHandle = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (m_ScmHandle == NULL)
	{
		MessageBox(NULL, TEXT("OpenSCManagerA ERROR"), TEXT("Error"), MB_OK);
		//
		return FALSE;
	}

	m_HerService = CreateService(m_ScmHandle, (LPCWSTR)SzSysFileName, (LPCWSTR)SzSysFileName, SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL, (LPCWSTR)SzSysFilePath, NULL, NULL, NULL, NULL, NULL);

	if (m_HerService == NULL)
	{
		//CloseServiceHandle(m_HerService);
		MessageBox(NULL, TEXT("Create Service Error!"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	CloseServiceHandle(m_HerService);
	
	MessageBox(NULL, TEXT("Create Service OK!"), TEXT("OK"), MB_OK);

	return TRUE;
}

BOOL Remove(LPCSTR SzSysFileName, LPCSTR SzSysFilePath)
{
	DWORD m_loadAddDriverError;

	//打开SCM管理器 (获取SCM句柄) - OpenSCManagerA
	m_ScmHandle = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (m_ScmHandle == NULL)
	{
		MessageBox(NULL, TEXT("OpenSCManagerA ERROR"), TEXT("Error"), MB_OK);
		//
		return FALSE;
	}

	m_HerService = OpenService(m_ScmHandle, (LPCWSTR)SzSysFileName, SERVICE_ALL_ACCESS);
	
	if (m_HerService == NULL)
	{
		MessageBox(NULL, TEXT("OpenService ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}
	/*
	DWORD pcbBytesNeeded;
	struct _QUERY_SERVICE_CONFIGA* v5;

	QueryServiceConfigA(m_HerService, 0, 0, &pcbBytesNeeded);

	v5 = (struct _QUERY_SERVICE_CONFIGA*)new unsigned __int64(pcbBytesNeeded);
	if (QueryServiceConfigA(m_HerService, v5, pcbBytesNeeded, &pcbBytesNeeded))
	{
		const char *v6 = v5->lpLoadOrderGroup;
		if (v6)
		{
			HKEY hKey;
			LSTATUS result;
			DWORD cbData = 0;
			result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "System\\CurrentControlSet\\Control\\GroupOrderList", 0, 0xF003Fu, &hKey);

			if (!result)
			{
				if (!RegQueryValueExA(hKey, v6, 0i64, 0i64, 0i64, &cbData))
				{
					
					v7 = (BYTE*)operator new[](saturated_mul((unsigned __int64)cbData >> 2, 4ui64));
					if (!RegQueryValueExA(hKey, v4, 0i64, 0i64, v7, &cbData) && cbData)
					{
						
						if (*(_DWORD*)v7)
							RegSetValueExA(hKey, v4, 0, 3u, v7, cbData - 4);
						else
							LABEL_15:
						RegDeleteValueA(hKey, v4);
					}
					operator delete[](v7);
					
				}
				
				result = RegCloseKey(hKey);
			}
		}
	}
	delete(v5);
	*/
	if (DeleteService(m_HerService) == NULL)
	{
		MessageBox(NULL, TEXT("Delete Fail!"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	MessageBox(NULL, TEXT("Delete Success!"), TEXT("OK"), MB_OK);
	//
	CloseServiceHandle(m_HerService);
	
	return 0;
}

BOOL Start(LPCSTR SzSysFileName, LPCSTR SzSysFilePath)
{
	DWORD m_loadAddDriverError;
	m_ScmHandle = NULL;
	m_HerService = NULL;

	//打开SCM管理器 (获取SCM句柄) - OpenSCManagerA
	m_ScmHandle = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (m_ScmHandle == NULL)
	{
		MessageBox(NULL, TEXT("OpenSCManagerA ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	MessageBox(NULL, (LPCWSTR)SzSysFileName, TEXT("Error"), MB_OK);
	m_HerService = OpenService(m_ScmHandle, (LPCWSTR)SzSysFileName, SERVICE_ALL_ACCESS);
	if (m_HerService == NULL)
	{
		
		MessageBox(NULL, TEXT("OpenService ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	if (StartService(m_HerService, 0, 0) == 0)
	{
		
		CloseServiceHandle(m_HerService);
		MessageBox(NULL, TEXT("StartService ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	CloseServiceHandle(m_HerService);
	
	MessageBox(NULL, TEXT("StartService OK"), TEXT("OK"), MB_OK);

	return TRUE;
}

BOOL Stop(LPCSTR SzSysFileName, LPCSTR SzSysFilePath)
{
	DWORD m_loadAddDriverError;
	m_ScmHandle = NULL;
	m_HerService = NULL;

	//打开SCM管理器 (获取SCM句柄) - OpenSCManagerA
	m_ScmHandle = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (m_ScmHandle == NULL)
	{
		MessageBox(NULL, TEXT("OpenSCManagerA ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	m_HerService = OpenService(m_ScmHandle, (LPCWSTR)SzSysFileName, SERVICE_ALL_ACCESS);
	if (m_HerService == NULL)
	{
		
		MessageBox(NULL, TEXT("OpenService ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	SERVICE_STATUS ser_status;
	if (ControlService(m_HerService, SERVICE_CONTROL_STOP, &ser_status) == 0)
	{
		
		CloseServiceHandle(m_HerService);
		MessageBox(NULL, TEXT("StopService ERROR"), TEXT("Error"), MB_OK);
		return FALSE;
	}

	CloseServiceHandle(m_HerService);
	
	MessageBox(NULL, TEXT("StopService OK"), TEXT("OK"), MB_OK);

	return TRUE;
}