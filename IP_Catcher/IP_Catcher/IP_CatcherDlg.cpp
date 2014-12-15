
// IP_CatcherDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IP_Catcher.h"
#include "IP_CatcherDlg.h"
#include "afxdialogex.h"
using namespace std;
//#include "IP_Info.cpp"

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


// CIP_CatcherDlg 对话框




CIP_CatcherDlg::CIP_CatcherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIP_CatcherDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIP_CatcherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}

BEGIN_MESSAGE_MAP(CIP_CatcherDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CIP_CatcherDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CIP_CatcherDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CIP_CatcherDlg 消息处理程序

BOOL CIP_CatcherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	//init list
	CRect mRect;
	m_List.GetWindowRect(&mRect);     //获取控件矩形区域
	int kuan = mRect.Width();
	m_List.InsertColumn(0,_T("版本号"),LVCFMT_LEFT,kuan/10,0);
	m_List.InsertColumn(1,_T("总长度"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(2,_T("DF"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(3,_T("PF"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(4,_T("片偏移"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(5,_T("协议"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(6,_T("源地址"),LVCFMT_CENTER,kuan/10*2,0);
	m_List.InsertColumn(7,_T("目的地址"),LVCFMT_CENTER,kuan/10*2,0);

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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIP_CatcherDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIP_CatcherDlg::OnPaint()
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
HCURSOR CIP_CatcherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIP_CatcherDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CIP_CatcherDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	int nRetCode = 0;
	WSADATA wsData;
	WSAStartup(MAKEWORD(2,2),&wsData);

	SOCKET m_Socket = socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	BOOL flag=TRUE;
	//设置IP头操作选项，用户可对IP头处理
	setsockopt(m_Socket,IPPROTO_IP,IP_HDRINCL,(char*)&flag,sizeof(flag));
	char hostName[128];
	gethostname(hostName,100);
	hostent * pHostIP;
	pHostIP=gethostbyname(hostName);
	sockaddr_in addr_in;
	addr_in.sin_addr=*(in_addr*)pHostIP->h_addr_list[0];
	addr_in.sin_family=AF_INET;
	addr_in.sin_port=htons(6000);
	bind(m_Socket,(PSOCKADDR)&addr_in,sizeof(addr_in));           //把socket绑定到本地网卡
	DWORD dwValue=1;
	//设置SOCK_RAW为SIO_RCVALL,能接收所有IP包
#define IO_RCVALL _WSAIOW(IOC_VENDOR,1)
	DWORD dwBufferLen[10];
	DWORD dwBufferInLen=1;
	DWORD dwBytesReturned=0;
	WSAIoctl(m_Socket,IO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL);
	//设置接受数据包缓冲区长度
#define BUFFER_SIZE 65535
	char buffer[BUFFER_SIZE];
	//监听网卡
	CString cs;
	bool fg = false;
	int n = 10;
	do{
		try{
			m_Edit.GetWindowText(cs);
			//MessageBox((cs));
			wchar_t* informL=cs.GetBuffer();
			char inform[100];
			WideCharToMultiByte( CP_ACP, 0, informL, -1,inform, sizeof(informL), NULL, NULL );  
			int len = strlen(inform);
			for(int i=0;i<len;++i){
				if(!(inform[i]>='0' && inform[i]<='9')){
					throw i;
				}
			}
			n = strtoul(inform,NULL,10);
			fg = true;
		}
		catch(int){
			MessageBox(_T("输入有误，请重新输入"));
			return ;
		}
	}while(fg == false);


	int i=0;            
	do
	{
		int size=recv(m_Socket,buffer,BUFFER_SIZE,0);	
		if(size>0){
			show_Ip(buffer);
		}
		i++;
	}while(i<n);
}


void CIP_CatcherDlg::show_Ip(char *buffer)
{
	IP_HEADER ip=*(IP_HEADER*)buffer;       //通过指针把缓冲区的内容强制转化为IP_HEADER数据结构
	BYTE Version;
	char file[100];
	sprintf(file,"%d",ip.getVersion());
	m_List.InsertItem(0,(CString)file);
	sprintf(file,"%d",ip.TotalLen);
	m_List.SetItemText(0,1,(CString)file);
	sprintf(file,"%d",ip.getDF());
	m_List.SetItemText(0,2,(CString)file);
	sprintf(file,"%d",ip.getMF());
	m_List.SetItemText(0,3,(CString)file);
	sprintf(file,"%d",ip.getFragOff());
	m_List.SetItemText(0,4,(CString)file);
	m_List.SetItemText(0,5,(CString)ip.getProtocol());
	m_List.SetItemText(0,6,(CString)inet_ntoa(*(in_addr*)&ip.SrcAddr));
	m_List.SetItemText(0,7,(CString)inet_ntoa(*(in_addr*)&ip.DstAddr));

}