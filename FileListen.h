#pragma once

// CFileListen ����Ŀ��

class CFileListen : public CAsyncSocket
{
public:
	CFileListen();
	virtual ~CFileListen();
	virtual void OnAccept(int nErrorCode);
};


