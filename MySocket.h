#pragma once

// CMySocket ����Ŀ��

class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	virtual void OnReceive(int nErrorCode);
};


