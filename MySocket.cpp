// MySocket.cpp : ʵ���ļ�
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


// CMySocket ��Ա����


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CAsyncClientDlg *dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 

    Receive(dlg->buff,200,0); 

    dlg->m_edit.SetWindowText(dlg->buff);
	CAsyncSocket::OnReceive(nErrorCode);
}
