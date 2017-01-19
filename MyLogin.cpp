// MyLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "MyLogin.h"
#include "afxdialogex.h"
#include "AsyncClientDlg.h"


// CMyLogin �Ի���

IMPLEMENT_DYNAMIC(CMyLogin, CDialogEx)

CMyLogin::CMyLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyLogin::IDD, pParent)
	, my_IP(_T(""))
	, my_Password(_T(""))
	, flag(0)
{

}

CMyLogin::~CMyLogin()
{
}

void CMyLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, my_IP);
	DDX_Text(pDX, IDC_EDIT2, my_Password);
}


BEGIN_MESSAGE_MAP(CMyLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyLogin::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMyLogin ��Ϣ�������

char Login[18];    //ȫ�ֱ�������¼�û�״̬


void CMyLogin::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxSocketInit();
	//���� CSocket����
   CSocket lSocket; 
   
   CString Username;
   CString Password;
   CString strText; 

   CString strIP("166.111.180.60"); 
   int nPort = 8000;

   this->GetDlgItem(IDC_EDIT1)->GetWindowText(Username); 
   this->GetDlgItem(IDC_EDIT2)->GetWindowText(Password); 
   strText=Username+"_"+Password;
   
   char* login;
   login="2012011510_net2014";

  // login=(LPSTR)(LPCTSTR)strText;
   //AfxMessageBox(strText);

   //��ʼ�� CSocket����,��Ϊ�ͻ��˲���Ҫ���κζ˿ں͵�ַ,������Ĭ�ϲ�������


 if(!lSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return ; 
 } 
 

//����ָ���ĵ�ַ�Ͷ˿�
  
 if(lSocket.Connect(strIP, nPort)) 

 {
//�������ݸ�������
	 
	//char *c;
	//c=(LPSTR)(LPCTSTR)strText;
	
	 memcpy(Login,strText,18);
     lSocket.Send(Login, 18);
//���շ��������ͻ���������(�÷���������,�ڴ˵ȴ������ݽ��յ��ż�������ִ��) 
  char  szRecValue[100] = {0};
  lSocket.Receive((void *)szRecValue, 100);
  CString echo(szRecValue);
  if(echo=="lol")
	 {
		 flag=1;
		 //CString error3("��½�ɹ���");
      // AfxMessageBox(echo); 
		CMyLogin::OnOK();
		 //CAsyncClientDlg dlg;
     // dlg.DoModal();
     }

  else

	   { CString error3("�˺Ż��������");
       AfxMessageBox(error3); 
       }
   } 

 else {

  CString error2("No connect!");
  AfxMessageBox(error2); 
    } 

 //�ر�
   // lSocket.Close();
}


void CMyLogin::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyLogin::OnOK();

}
