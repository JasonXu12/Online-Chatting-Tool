#pragma once


// CMyLogin �Ի���

extern char Login[18];    //ȫ�ֱ�������¼�û�״̬

class CMyLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CMyLogin)

public:
	CMyLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString my_IP;
	CString my_Password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int flag;
};
