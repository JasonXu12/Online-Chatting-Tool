// MySocket.cpp : 实现文件
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "MySocket.h"
#include "AsyncClientDlg.h"

// CMySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}


// CMySocket 成员函数


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	CAsyncClientDlg *dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 

    Receive(dlg->buff,200,0); 

    dlg->m_edit.SetWindowText(dlg->buff);
	CAsyncSocket::OnReceive(nErrorCode);
}
