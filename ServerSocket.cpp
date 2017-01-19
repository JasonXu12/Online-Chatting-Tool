// ServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "ServerSocket.h"
#include "AsyncClientDlg.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket 成员函数


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	 

CAsyncClientDlg * dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 

 //上面代码的含义大家要想明白

Accept(dlg->s_client); //让client套接字与客户机建立连接，server套接字继续侦听
	CAsyncSocket::OnAccept(nErrorCode);
}
