#pragma once

// CFileListen ÃüÁîÄ¿±ê

class CFileListen : public CAsyncSocket
{
public:
	CFileListen();
	virtual ~CFileListen();
	virtual void OnAccept(int nErrorCode);
};


