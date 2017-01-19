// FileRecv.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "FileRecv.h"
#include "AsyncClientDlg.h"


// CFileRecv

CFileRecv::CFileRecv()
{
}

CFileRecv::~CFileRecv()
{
}


// CFileRecv ��Ա����


void CFileRecv::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
    // CAsyncClientDlg * dlg=(CAsyncClientDlg *)AfxGetApp()->GetMainWnd();
	SOCKET_STREAM_FILE_INFO StreamFileInfo;
	Receive(&StreamFileInfo,sizeof(SOCKET_STREAM_FILE_INFO));

	CFile destFile(StreamFileInfo.szFileTitle, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);

	UINT dwRead = 0;
	while(dwRead<StreamFileInfo.nFileSizeLow)
	{
		byte* data = new byte[1024*16];
		memset(data,0,1024*16);

		UINT dw=Receive(data, 1024*16);
		destFile.Write(data, dw);
		delete data;
		dwRead+=dw;
	}

	SetFileTime((HANDLE)destFile.m_hFile,&StreamFileInfo.ftCreationTime,
                &StreamFileInfo.ftLastAccessTime,&StreamFileInfo.ftLastWriteTime);
	destFile.Close();
	SetFileAttributes(StreamFileInfo.szFileTitle,StreamFileInfo.dwFileAttributes);
	Close();
	AfxMessageBox("�������");
	
	CAsyncSocket::OnReceive(nErrorCode);
}
