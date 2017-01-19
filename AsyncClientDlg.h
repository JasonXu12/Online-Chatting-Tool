
// AsyncClientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "mysocket.h"
#include "clientsocket.h"
#include "serversocket.h"
#include "afxsock.h"
#include "FileListen.h"
#include "FileRecv.h"

typedef struct _SOCKET_STREAM_FILE_INFO {

    TCHAR       szFileTitle[128];                   //文件的标题名
    DWORD       dwFileAttributes;                   //文件的属性
    FILETIME    ftCreationTime;                     //文件的创建时间
    FILETIME    ftLastAccessTime;                   //文件的最后访问时间
    FILETIME    ftLastWriteTime;                    //文件的最后修改时间
    DWORD       nFileSizeHigh;                      //文件大小的高位双字
    DWORD       nFileSizeLow;                       //文件大小的低位双字
    DWORD       dwReserved0;                        //保留，为0
    DWORD       dwReserved1;                        //保留，为0

} SOCKET_STREAM_FILE_INFO, * PSOCKET_STREAM_FILE_INFO;

// CAsyncClientDlg 对话框
class CAsyncClientDlg : public CDialogEx
{
// 构造
public:
	CAsyncClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ASYNCCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CMySocket client;
	char buff[200];
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit s_edit;
	char s_buff[200];
	CClientSocket s_client;
	CServerSocket s_server;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
//	CString IDC_Number;
	CSocket llSocket;
//	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton6();

	CFileListen m_File;
	CFileRecv in_File;
	CAsyncSocket out_File;

	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
