#pragma once


// CMyLogin 对话框

extern char Login[18];    //全局变量，记录用户状态

class CMyLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CMyLogin)

public:
	CMyLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString my_IP;
	CString my_Password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int flag;
};
