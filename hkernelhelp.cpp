#include "hkernelapi.h"
#include <QApplication>
inline void zeroDBHandle( DBHANDLE hHandle )
{
    hHandle.pSt = NULL;
    hHandle.pPt = NULL;
}

//获取当前厂站和测点
DBHANDLE KERAPI_EXPORT getDbHandleEx(QWidget* pWidget,ushort wStation,uchar btType,ushort wNo,uchar btDBType)
{
    KEREVENT kerEvent;
    memset(&kerEvent,0,sizeof(KEREVENT));
    zeroDBHandle(kerEvent.hHandle);
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    kerEvent.wStation = wStation;
    kerEvent.btType = btType;
    kerEvent.wPoint = wNo;
    kerEvent.wOffset = btDBType;

    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::GetDBHandle));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    QApplication::sendEvent(pWidget,&event);
    return kerEvent.hHandle;
}

//同上
DBHANDLE KERAPI_EXPORT findDbHandleEx(QWidget* pWidget,ushort wStation,uchar btType,ushort wIndex)
{
    KEREVENT kerEvent;
    memset(&kerEvent,0,sizeof(KEREVENT));
    zeroDBHandle(kerEvent.hHandle);
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    kerEvent.wStation = wStation;
    kerEvent.btType = btType;
    kerEvent.wPoint = wIndex;

    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::FindDBHandle));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    QApplication::sendEvent(pWidget,&event);
    return kerEvent.hHandle;
}

//当前厂站测点是否有效
bool KERAPI_EXPORT isValidDbHandleEx(QWidget* ,DBHANDLE dbHandle)
{
    return (dbHandle.pSt != NULL);
}

//人工置数部分
void KERAPI_EXPORT analogueManualSetEx(QWidget* pWidget,DBHANDLE dbHandle,float fValue)
{
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    KEREVENT kerEvent;
    memset( &kerEvent, 0, sizeof(KEREVENT) );

    kerEvent.hHandle = dbHandle;
    kerEvent.pValue = &fValue;
    kerEvent.wValue = sizeof( float );
    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::AnalogueManualSet));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    QApplication::sendEvent(pWidget,&event);
}

void KERAPI_EXPORT digitalManualSetEx(QWidget* pWidget,DBHANDLE dbHandle,uchar btValue)
{
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    KEREVENT kerEvent;
    memset( &kerEvent, 0, sizeof(KEREVENT) );

    kerEvent.hHandle = dbHandle;
    kerEvent.pValue = &btValue;
    kerEvent.wValue = sizeof( uchar );
    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::DigitalManualSet));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    QApplication::sendEvent(pWidget,&event);
}

//获取数据
bool KERAPI_EXPORT getAttrEx(QWidget* pWidget,DBHANDLE dbHandle,ushort wAttrib,void* pValue,int length)
{
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    KEREVENT kerEvent;
    memset( &kerEvent, 0, sizeof(KEREVENT) );

    kerEvent.hHandle = dbHandle;
    kerEvent.wAttrib = wAttrib;
    kerEvent.pValue = pValue;
    kerEvent.wValue = (ushort)length;
    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::GetAttr));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    if(true == QApplication::sendEvent(pWidget,&event))
        return true;
    return false;
}

//设置数据
bool KERAPI_EXPORT setAttrEx(QWidget* pWidget,DBHANDLE dbHandle,ushort wAttrib,void* pValue,int length)
{
    if((!pWidget)||(!pWidget->isWindow()))
        return kerEvent.hHandle;
    KEREVENT kerEvent;
    memset( &kerEvent, 0, sizeof(KEREVENT) );

    kerEvent.hHandle = dbHandle;
    kerEvent.wAttrib = wAttrib;
    kerEvent.pValue = pValue;
    kerEvent.wValue = (ushort)length;
    const QEvent::Type kerType = static_cast<QEvent::Type>(QEvent::registerEventType(HKerEvent::SetAttr));
    HKerEvent event(kerType,(HLPARAM)&kerEvent);
    if(true == QApplication::sendEvent(pWidget,&event))
        return true;
    return false;
}
