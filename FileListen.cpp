// FileListen.cpp : 实现文件
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


// CFileListen 成员函数

void CFileListen::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	CAsyncClientDlg *dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd(); 
	Accept(dlg->in_File); 
	CAsyncSocket::OnAccept(nErrorCode);
}