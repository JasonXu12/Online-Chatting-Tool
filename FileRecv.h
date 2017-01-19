#pragma once

// CFileRecv ÃüÁîÄ¿±ê

class CFileRecv : public CAsyncSocket
{
public:
	CFileRecv();
	virtual ~CFileRecv();
	virtual void OnReceive(int nErrorCode);
};


