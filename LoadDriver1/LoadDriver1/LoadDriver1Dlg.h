
// LoadDriver1Dlg.h: 头文件
//

#pragma once

#include<winsvc.h>


// CLoadDriver1Dlg 对话框
class CLoadDriver1Dlg : public CDialogEx
{
// 构造
public:
	CLoadDriver1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOADDRIVER1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	//virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void UnregisterDriver();
	afx_msg void RegisterDriver();
	afx_msg void StartDriver();
	afx_msg void OnEnChangeMfceditbrowse1();
	CMFCEditBrowseCtrl browser1;
	afx_msg void StopDriver();
};

BOOL Remove(LPCSTR SzSysFileName, LPCSTR SzSysFilePath);
BOOL Load(LPCSTR SzSysFileName, LPCSTR SzSysFilePath);
BOOL Start(LPCSTR SzSysFileName, LPCSTR SzSysFilePath);
BOOL Stop(LPCSTR SzSysFileName, LPCSTR SzSysFilePath);

