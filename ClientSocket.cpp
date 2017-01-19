// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "ClientSocket.h"
#include "AsyncClientDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 成员函数


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	CAsyncClientDlg * dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 
	Receive(dlg->s_buff,200,0); 
	dlg->s_edit.SetWindowText(dlg->s_buff); 
	CAsyncSocket::OnReceive(nErrorCode);
}
