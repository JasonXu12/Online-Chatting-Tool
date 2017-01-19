// MyLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "AsyncClient.h"
#include "MyLogin.h"
#include "afxdialogex.h"
#include "AsyncClientDlg.h"


// CMyLogin 对话框

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


// CMyLogin 消息处理程序

char Login[18];    //全局变量，记录用户状态


void CMyLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxSocketInit();
	//创建 CSocket对象
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

   //初始化 CSocket对象,因为客户端不需要绑定任何端口和地址,所以用默认参数即可


 if(!lSocket.Create()) 

 {
  CString error1("No create!");
  AfxMessageBox(error1); 
  return ; 
 } 
 

//连接指定的地址和端口
  
 if(lSocket.Connect(strIP, nPort)) 

 {
//发送内容给服务器
	 
	//char *c;
	//c=(LPSTR)(LPCTSTR)strText;
	
	 memcpy(Login,strText,18);
     lSocket.Send(Login, 18);
//接收服务器发送回来的内容(该方法会阻塞,在此等待有内容接收到才继续向下执行) 
  char  szRecValue[100] = {0};
  lSocket.Receive((void *)szRecValue, 100);
  CString echo(szRecValue);
  if(echo=="lol")
	 {
		 flag=1;
		 //CString error3("登陆成功！");
      // AfxMessageBox(echo); 
		CMyLogin::OnOK();
		 //CAsyncClientDlg dlg;
     // dlg.DoModal();
     }

  else

	   { CString error3("账号或密码错误");
       AfxMessageBox(error3); 
       }
   } 

 else {

  CString error2("No connect!");
  AfxMessageBox(error2); 
    } 

 //关闭
   // lSocket.Close();
}


void CMyLogin::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyLogin::OnOK();

}
