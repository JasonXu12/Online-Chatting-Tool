// ServerSocket.cpp : ʵ���ļ�
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


// CServerSocket ��Ա����


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	 

CAsyncClientDlg * dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 

 //�������ĺ�����Ҫ������

Accept(dlg->s_client); //��client�׽�����ͻ����������ӣ�server�׽��ּ�������
	CAsyncSocket::OnAccept(nErrorCode);
}
