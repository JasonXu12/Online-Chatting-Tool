// ClientSocket.cpp : ʵ���ļ�
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


// CClientSocket ��Ա����


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CAsyncClientDlg * dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 
	Receive(dlg->s_buff,200,0); 
	dlg->s_edit.SetWindowText(dlg->s_buff); 
	CAsyncSocket::OnReceive(nErrorCode);
}
