
// AsyncClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "AsyncClientDlg.h"
#include "afxdialogex.h"
#include "MyLogin.h"
#include "FileListen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAsyncClientDlg 对话框



CAsyncClientDlg::CAsyncClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAsyncClientDlg::IDD, pParent)
//	, IDC_Number(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsyncClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_EDIT2, s_edit);
	//  DDX_Text(pDX, IDC_EDIT3, IDC_Number);
}

BEGIN_MESSAGE_MAP(CAsyncClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAsyncClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAsyncClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAsyncClientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CAsyncClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CAsyncClientDlg::OnBnClickedButton4)
//	ON_BN_CLICKED(IDC_BUTTON6, &CAsyncClientDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON6, &CAsyncClientDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CAsyncClientDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CAsyncClientDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CAsyncClientDlg 消息处理程序

BOOL CAsyncClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	 

	CMyLogin dlg;
	dlg.DoModal();
	if(dlg.flag!=1) 
		CAsyncClientDlg::OnOK();

	 if(!llSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return 0; 
 } 
	  	  CString strIP("166.111.180.60"); 
      int nPort = 8000;

	if( llSocket.Connect(strIP, nPort))
	{

 
//发送内容给服务器

     llSocket.Send(Login, 18);
	  char  szRecValue[100] = {0};
    llSocket.Receive((void *)szRecValue, 100);
  CString echo(szRecValue);
  if(echo=="lol")
	 {
		 CString error3("登陆成功！");
       AfxMessageBox(error3); 
    }
	}
	//p2p聊天及群聊
	client.Create();

	s_server.Create(3000); 
    s_server.Listen();
	
	//文件传输
	m_File.Create(1800);
	m_File.Listen();

	out_File.Create();
	 
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAsyncClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAsyncClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAsyncClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


char  szRecValue[100] = {0};//全局变量，记录IP
const char  FriId[100]="201201149720120115102012011508";   //好友ID
const int   Num=3;                                         //好友数


void CAsyncClientDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString errcode; 
	
    if(!client.Connect(szRecValue,3000)) 

	{ CString Suc("Access Successfully!");  AfxMessageBox(Suc);}  
}


void CAsyncClientDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit.GetWindowText(buff,200); 
	CString kk; 
	kk.Format("%d",client.Send(buff,200,0)); 

 //m_edit.SetWindowText(kk); 
}


void CAsyncClientDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	s_edit.GetWindowText(s_buff,200);
 

    s_client.Send(s_buff,200,0);
}



// 退出按钮
void CAsyncClientDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	
    char* logout;
	logout="logout2012011510";
	char Logout[17]="logout2012000000";
	int i;

	for(i=6;i<16;i++)
	{
		Logout[i]=Login[i-6];
	}

	CSocket bSocket; 
	CString strIP("166.111.180.60");
	int nPort = 8000;

	 if(!bSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return ; 
 } 

	 if(bSocket.Connect(strIP, nPort)) 

 {

	bSocket.Send(Logout,16); 
    char  szRecValue[100] = {0};
    bSocket.Receive((void *)szRecValue, 100);
    CString echo(szRecValue);
	if(echo="loo")
	{
		CAsyncClientDlg::OnOK();
        CString Exit("退出成功!");
        AfxMessageBox(Exit); 
	   
   
}
	 }

 else {

        CString error2("退出失败!");
        AfxMessageBox(error2); 
    } 

 //关闭
 bSocket.Close();
}


//查询按钮


void CAsyncClientDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
		CSocket cSocket; 
   CString strIP("166.111.180.60"); 

   int nPort = 8000;

	if(!cSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return ; 
 } 
 

//连接指定的地址和端口

 if(cSocket.Connect(strIP, nPort)) 

 {
//发送内容给服务器
	 CString FriendNumber;
	 this->GetDlgItem(IDC_Number)->GetWindowText(FriendNumber); 

	 char Ques[11];
	 Ques[0]='q';

	memcpy(Ques+1,FriendNumber,10);
	
     cSocket.Send(Ques, 11);

	 
     cSocket.Receive((void *)szRecValue, 100);
	 CString echo(szRecValue);
	 AfxMessageBox(echo); 

	 if(echo=="n")
		  { 
			  CString error("好友不在线!");
            AfxMessageBox(error); 
	       }
	 else
		 if(echo=="Incorrect No.")
			  { 
			  CString error("没有该用户!");
            AfxMessageBox(error); 
	       }
		 else
		 {
			 //用户在线，询问是否进行P2P通信
			   	 CString error("好友在线!");
            AfxMessageBox(error); 
		 }
}

}




void CAsyncClientDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog Dlg(TRUE);
	if (Dlg.DoModal()!=IDOK)
		return;

	CFile myFile;
	if (!myFile.Open(Dlg.GetPathName(),CFile::modeRead | CFile::typeBinary))
	{
		AfxMessageBox("Error!",MB_OK|MB_ICONERROR);
		return;
	}

	SOCKET_STREAM_FILE_INFO	StreamFileInfo;
	WIN32_FIND_DATA             FindFileData;

	FindClose(FindFirstFile(Dlg.GetPathName(),&FindFileData));
    memset(&StreamFileInfo,0,sizeof(SOCKET_STREAM_FILE_INFO));
    strcpy_s(StreamFileInfo.szFileTitle,myFile.GetFileTitle());

    StreamFileInfo.dwFileAttributes     =       FindFileData.dwFileAttributes;
    StreamFileInfo.ftCreationTime       =       FindFileData.ftCreationTime;
    StreamFileInfo.ftLastAccessTime     =       FindFileData.ftLastAccessTime;
    StreamFileInfo.ftLastWriteTime      =       FindFileData.ftLastWriteTime;
    StreamFileInfo.nFileSizeHigh        =       FindFileData.nFileSizeHigh;
    StreamFileInfo.nFileSizeLow         =       FindFileData.nFileSizeLow;

	out_File.Send(&StreamFileInfo,sizeof(SOCKET_STREAM_FILE_INFO));

	UINT dwRead=0;
	while(dwRead<StreamFileInfo.nFileSizeLow)
	{
		byte* data = new byte[1024*16];
		UINT dw=myFile.Read(data, 1024*16);
		out_File.Send(data, dw);
		delete data;
		dwRead+=dw;
	}
	myFile.Close();

	out_File.Close();
	AfxMessageBox("发送完毕");

}


void CAsyncClientDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString errcode("Access Successfully!"); 
	
    if(!out_File.Connect(szRecValue,1800)) 

    AfxMessageBox(errcode);  
}


void CAsyncClientDlg::OnBnClickedButton8()
{
    // TODO: 在此添加控件通知处理程序代码
   CSocket GSocket; 
   CString strIP("166.111.180.60"); 
   int nPort = 8000;
   
   if(!GSocket.Create()) 
   {
	   CString error1("No create!");
	   AfxMessageBox(error1); 
	   return ; 
   } 

   //连接指定的地址和端口
   if(GSocket.Connect(strIP, nPort)) 
   {
	 int cnt=0;
	 //发送内容给服务器，依次确认好友是否在线
	 for (int i=0;i<Num;i++)                         //选择好友
	 {
		 char Ques[11];                              //临时存储好友ID
		 Ques[0]='q';
		 memcpy(Ques+1,FriId+i*10,10);               //将好友ID从FriId中拷贝进Ques
		 GSocket.Send(Ques,11);                      //向服务器发送“q+好友学号”，用来确认是否在线
		 GSocket.Receive((void *)szRecValue,100);    //接收服务器反馈信息
		 CString echo(szRecValue);

		 if (echo != "n")      //返回为IP地址，即好友在线，发送信息
		 {
			 if (!client.Connect(szRecValue,3000))
			 {
				 m_edit.GetWindowText(buff,200); 
				 client.Send(buff,200,0); 
			 }
			 cnt++;
		 }
	 }
	 if (cnt==0 || cnt==1) AfxMessageBox("无好友在线！");
   }
  
   GSocket.Close();

}
