#pragma once

// CFileRecv ����Ŀ��

class CFileRecv : public CAsyncSocket
{
public:
	CFileRecv();
	virtual ~CFileRecv();
	virtual void OnReceive(int nErrorCode);
};


