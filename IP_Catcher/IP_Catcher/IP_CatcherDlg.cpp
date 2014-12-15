
// IP_CatcherDlg.cpp : ʵ���ļ�
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


// CIP_CatcherDlg �Ի���




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


// CIP_CatcherDlg ��Ϣ�������

BOOL CIP_CatcherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	//init list
	CRect mRect;
	m_List.GetWindowRect(&mRect);     //��ȡ�ؼ���������
	int kuan = mRect.Width();
	m_List.InsertColumn(0,_T("�汾��"),LVCFMT_LEFT,kuan/10,0);
	m_List.InsertColumn(1,_T("�ܳ���"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(2,_T("DF"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(3,_T("PF"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(4,_T("Ƭƫ��"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(5,_T("Э��"),LVCFMT_CENTER,kuan/10,0);
	m_List.InsertColumn(6,_T("Դ��ַ"),LVCFMT_CENTER,kuan/10*2,0);
	m_List.InsertColumn(7,_T("Ŀ�ĵ�ַ"),LVCFMT_CENTER,kuan/10*2,0);

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIP_CatcherDlg::OnPaint()
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
HCURSOR CIP_CatcherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIP_CatcherDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CIP_CatcherDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	int nRetCode = 0;
	WSADATA wsData;
	WSAStartup(MAKEWORD(2,2),&wsData);

	SOCKET m_Socket = socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	BOOL flag=TRUE;
	//����IPͷ����ѡ��û��ɶ�IPͷ����
	setsockopt(m_Socket,IPPROTO_IP,IP_HDRINCL,(char*)&flag,sizeof(flag));
	char hostName[128];
	gethostname(hostName,100);
	hostent * pHostIP;
	pHostIP=gethostbyname(hostName);
	sockaddr_in addr_in;
	addr_in.sin_addr=*(in_addr*)pHostIP->h_addr_list[0];
	addr_in.sin_family=AF_INET;
	addr_in.sin_port=htons(6000);
	bind(m_Socket,(PSOCKADDR)&addr_in,sizeof(addr_in));           //��socket�󶨵���������
	DWORD dwValue=1;
	//����SOCK_RAWΪSIO_RCVALL,�ܽ�������IP��
#define IO_RCVALL _WSAIOW(IOC_VENDOR,1)
	DWORD dwBufferLen[10];
	DWORD dwBufferInLen=1;
	DWORD dwBytesReturned=0;
	WSAIoctl(m_Socket,IO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL);
	//���ý������ݰ�����������
#define BUFFER_SIZE 65535
	char buffer[BUFFER_SIZE];
	//��������
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
			MessageBox(_T("������������������"));
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
	IP_HEADER ip=*(IP_HEADER*)buffer;       //ͨ��ָ��ѻ�����������ǿ��ת��ΪIP_HEADER���ݽṹ
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