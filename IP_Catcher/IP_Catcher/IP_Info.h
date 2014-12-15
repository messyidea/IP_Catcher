
#include "afxcmn.h"
#include "afxwin.h"
#include "iostream"

#ifndef _haha
#define _haha 0
#endif

class IP_HEADER  //����IPͷ
{
public:
    union
    {
        BYTE Version;      //�汾��ǰ4λ��
        BYTE HdrLen;       //IHL����4λ������ͷ��&�ײ�����
    };
    BYTE ServiceType;    //��������
    WORD TotalLen;       //16λ�ܳ���
    WORD ID;             //16λ��ʶ
    union
    {
        WORD Flags;      //3λ��־
        WORD FragOff;    //�ֶ�ƫ�ƣ���13λ��
    };

    BYTE TimeToLive;    //������
    BYTE Protocol;      //Э��

    DWORD SrcAddr;      //Դ��ַ
    DWORD DstAddr;      //Ŀ�ĵ�ַ
    BYTE Options;       //ѡ��

    BYTE getVersion()
    {
        return Version>>4;
    }

    BYTE getIHL()
    {
        return (HdrLen&0x0f)*4;
    }

    char * parseServiceType_getProcedence()
    {
        switch (Protocol>>5)         //��ȡ���������ֶ������ȼ�����
        {
        case 7:
            return "Network Control";
            break;
        case 6:
            return "Internet work Control";
            break;
        case 5:
            return "CRITIC/ECP";
            break;
        case 4:
            return "Flash Override";
            break;
        case 3:
            return "Flsah";
            break;
        case 2:
            return "Immediate";
            break;
        case 1:
            return "Priority";
            break;
        case 0:
            return "Routine";
            break;
        default:
            return "Unknow";
            break;
        }
    }

    char * parseServiceType_getTOS()
    {
        BYTE b=(ServiceType>>1)&0x0f;        //��ȡ���������ֶ��е�TOS����
        switch (int(b))
        {
        case 0:
            return "Normal service";
            break;
        case 1:
            return "Minimize monetary cost";
            break;
        case 2:
            return "Maximize reliability";
            break;
        case 4:
            return "Maximize throughput";
            break;
        case 8:
            return "Minimize delay";
            break;
        case 15:
            return "Maximize security";
            break;
        default:
            return "Unknow";
        }
    }

    BYTE getDF()
    {
        return (Flags>>14)&0x01;
    }

    BYTE getMF()
    {
        return (Flags>>13)&0x01;
    }


    WORD getFragOff()         //��ȡ�ֶ�ƫ���ֶ�
    {
        return (FragOff)&0x1fff;
    }

    char * getProtocol()             //��ȡЭ���ֶι�8λ
    {
        switch (int(Protocol))                         //����ΪЭ���˵����
        {
        case 1:
            return "ICMP";
        case 2:
            return "IGMP";
        case 4:
            return "IP in IP";
        case 6:
            return "TCP";
        case 8:
            return "EGP";
        case 17:
            return "UDP";
        case 41:
            return "IPv6";
        case 46:
            return "RSVP";
        case 89:
            return "OSPF";
        default:
            return "UNKNOW";
        }
    }

};

//��λ����IPͷ�е���Ϣ

