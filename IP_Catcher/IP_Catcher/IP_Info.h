
#include "afxcmn.h"
#include "afxwin.h"
#include "iostream"

#ifndef _haha
#define _haha 0
#endif

class IP_HEADER  //定义IP头
{
public:
    union
    {
        BYTE Version;      //版本（前4位）
        BYTE HdrLen;       //IHL（后4位），标头长&首部长度
    };
    BYTE ServiceType;    //服务类型
    WORD TotalLen;       //16位总长度
    WORD ID;             //16位标识
    union
    {
        WORD Flags;      //3位标志
        WORD FragOff;    //分段偏移（后13位）
    };

    BYTE TimeToLive;    //生命期
    BYTE Protocol;      //协议

    DWORD SrcAddr;      //源地址
    DWORD DstAddr;      //目的地址
    BYTE Options;       //选项

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
        switch (Protocol>>5)         //获取服务类型字段中优先级子域
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
        BYTE b=(ServiceType>>1)&0x0f;        //获取服务类型字段中的TOS子域
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


    WORD getFragOff()         //获取分段偏移字段
    {
        return (FragOff)&0x1fff;
    }

    char * getProtocol()             //获取协议字段共8位
    {
        switch (int(Protocol))                         //以下为协议号说明：
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

//逐位解析IP头中的信息

