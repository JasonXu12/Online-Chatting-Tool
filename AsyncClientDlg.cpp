
// AsyncClientDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CAsyncClientDlg �Ի���



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


// CAsyncClientDlg ��Ϣ�������

BOOL CAsyncClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	 

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

 
//�������ݸ�������

     llSocket.Send(Login, 18);
	  char  szRecValue[100] = {0};
    llSocket.Receive((void *)szRecValue, 100);
  CString echo(szRecValue);
  if(echo=="lol")
	 {
		 CString error3("��½�ɹ���");
       AfxMessageBox(error3); 
    }
	}
	//p2p���켰Ⱥ��
	client.Create();

	s_server.Create(3000); 
    s_server.Listen();
	
	//�ļ�����
	m_File.Create(1800);
	m_File.Listen();

	out_File.Create();
	 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAsyncClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAsyncClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


char  szRecValue[100] = {0};//ȫ�ֱ�������¼IP
const char  FriId[100]="201201149720120115102012011508";   //����ID
const int   Num=3;                                         //������


void CAsyncClientDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString errcode; 
	
    if(!client.Connect(szRecValue,3000)) 

	{ CString Suc("Access Successfully!");  AfxMessageBox(Suc);}  
}


void CAsyncClientDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit.GetWindowText(buff,200); 
	CString kk; 
	kk.Format("%d",client.Send(buff,200,0)); 

 //m_edit.SetWindowText(kk); 
}


void CAsyncClientDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	s_edit.GetWindowText(s_buff,200);
 

    s_client.Send(s_buff,200,0);
}



// �˳���ť
void CAsyncClientDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
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
        CString Exit("�˳��ɹ�!");
        AfxMessageBox(Exit); 
	   
   
}
	 }

 else {

        CString error2("�˳�ʧ��!");
        AfxMessageBox(error2); 
    } 

 //�ر�
 bSocket.Close();
}


//��ѯ��ť


void CAsyncClientDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CSocket cSocket; 
   CString strIP("166.111.180.60"); 

   int nPort = 8000;

	if(!cSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return ; 
 } 
 

//����ָ���ĵ�ַ�Ͷ˿�

 if(cSocket.Connect(strIP, nPort)) 

 {
//�������ݸ�������
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
			  CString error("���Ѳ�����!");
            AfxMessageBox(error); 
	       }
	 else
		 if(echo=="Incorrect No.")
			  { 
			  CString error("û�и��û�!");
            AfxMessageBox(error); 
	       }
		 else
		 {
			 //�û����ߣ�ѯ���Ƿ����P2Pͨ��
			   	 CString error("��������!");
            AfxMessageBox(error); 
		 }
}

}




void CAsyncClientDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	AfxMessageBox("�������");

}


void CAsyncClientDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString errcode("Access Successfully!"); 
	
    if(!out_File.Connect(szRecValue,1800)) 

    AfxMessageBox(errcode);  
}


void CAsyncClientDlg::OnBnClickedButton8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
   CSocket GSocket; 
   CString strIP("166.111.180.60"); 
   int nPort = 8000;
   
   if(!GSocket.Create()) 
   {
	   CString error1("No create!");
	   AfxMessageBox(error1); 
	   return ; 
   } 

   //����ָ���ĵ�ַ�Ͷ˿�
   if(GSocket.Connect(strIP, nPort)) 
   {
	 int cnt=0;
	 //�������ݸ�������������ȷ�Ϻ����Ƿ�����
	 for (int i=0;i<Num;i++)                         //ѡ�����
	 {
		 char Ques[11];                              //��ʱ�洢����ID
		 Ques[0]='q';
		 memcpy(Ques+1,FriId+i*10,10);               //������ID��FriId�п�����Ques
		 GSocket.Send(Ques,11);                      //����������͡�q+����ѧ�š�������ȷ���Ƿ�����
		 GSocket.Receive((void *)szRecValue,100);    //���շ�����������Ϣ
		 CString echo(szRecValue);

		 if (echo != "n")      //����ΪIP��ַ�����������ߣ�������Ϣ
		 {
			 if (!client.Connect(szRecValue,3000))
			 {
				 m_edit.GetWindowText(buff,200); 
				 client.Send(buff,200,0); 
			 }
			 cnt++;
		 }
	 }
	 if (cnt==0 || cnt==1) AfxMessageBox("�޺������ߣ�");
   }
  
   GSocket.Close();

}
