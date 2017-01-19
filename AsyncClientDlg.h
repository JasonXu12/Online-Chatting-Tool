
// AsyncClientDlg.h : ͷ�ļ�
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

    TCHAR       szFileTitle[128];                   //�ļ��ı�����
    DWORD       dwFileAttributes;                   //�ļ�������
    FILETIME    ftCreationTime;                     //�ļ��Ĵ���ʱ��
    FILETIME    ftLastAccessTime;                   //�ļ���������ʱ��
    FILETIME    ftLastWriteTime;                    //�ļ�������޸�ʱ��
    DWORD       nFileSizeHigh;                      //�ļ���С�ĸ�λ˫��
    DWORD       nFileSizeLow;                       //�ļ���С�ĵ�λ˫��
    DWORD       dwReserved0;                        //������Ϊ0
    DWORD       dwReserved1;                        //������Ϊ0

} SOCKET_STREAM_FILE_INFO, * PSOCKET_STREAM_FILE_INFO;

// CAsyncClientDlg �Ի���
class CAsyncClientDlg : public CDialogEx
{
// ����
public:
	CAsyncClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ASYNCCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
