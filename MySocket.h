#pragma once

// CMySocket ÃüÁîÄ¿±ê

class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	virtual void OnReceive(int nErrorCode);
};


