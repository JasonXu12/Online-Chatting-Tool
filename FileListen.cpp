// FileListen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "FileListen.h"
#include "AsyncClientDlg.h"


// CFileListen

CFileListen::CFileListen()
{
}

CFileListen::~CFileListen()
{
}


// CFileListen ��Ա����

void CFileListen::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CAsyncClientDlg *dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 
	Accept(dlg->in_File); 
	CAsyncSocket::OnAccept(nErrorCode);
}