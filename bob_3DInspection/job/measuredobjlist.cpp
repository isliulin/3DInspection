#include "measuredobjlist.hpp"

using namespace std;
using namespace Job;
using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//构造 &析构函数
MeasuredObjList::MeasuredObjList()
{
    this->m_size = 0;
    this->m_pHeadObj = nullptr;
}

MeasuredObjList::~MeasuredObjList()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//创建列表,增加,删除检测对象
void MeasuredObjList::pushHead(MeasuredObj *pMeasuredObj)
{
    try
    {
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step1
        //定义一个MeasuredObj指针对象
        //pTmpObj:为临时记录列表检测对象地址的指针,将其默认设为列表的头指针
        MeasuredObj * pTmpObj = this->m_pHeadObj;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step2
        //设置对象的成员变量(指向上一个检测对象的指针),设置为nullptr
        pMeasuredObj->setNextMeasuredObjPtr(nullptr);
        //设置对象的成员变量(指向下一个检测对象的指针)指向原来的表头
        pMeasuredObj->setNextMeasuredObjPtr(pTmpObj);

        //如果列表原来的头指针不为nullptr,则设置原来表头上一个头指针指向当前的表头
        if(nullptr != pTmpObj)
        {
           pTmpObj->setPreMeasuredObjPtr(pTmpObj);
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step3
        //重新设置列表的头指针
        this->m_pHeadObj = pMeasuredObj;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step4
        //将列表的长度 +1
        this->m_size++;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    }
    catch(const exception &ex)
    {
        THROW_EXCEPTION(ex.what());
    }
}

void MeasuredObjList::pushTail(MeasuredObj *pMeasuredObj)
{
    try
    {
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step1
        //定义两个 MeasuredObj指针对象
        //pTailObj:为记录列表尾部检测对象的指针,默认设置为nullptr
        //pTmpObj:为临时记录列表检测对象地址的指针,将其默认设为列表的头指针
        MeasuredObj * pTailObj = this->m_pHeadObj;
        MeasuredObj * pTmpObj;

        if(nullptr != this->m_pHeadObj)
        {
            pTmpObj = this->m_pHeadObj->pNextMeasuredObj();
        }
        else
        {
            pTmpObj = nullptr;
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step2
        //找出列表中最后一个检测对象
        while (nullptr != pTmpObj)
        {
            pTailObj = pTmpObj;
            pTmpObj = pTmpObj->pNextMeasuredObj();
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step3
        //3.1设置对象中成员变量(指向下一个检测对象的指针)设置为nullptr
        pMeasuredObj->setNextMeasuredObjPtr(nullptr);
        //3.2将新创建对象中成员变量(指向下一个检测对象的指针)设置为nullptr
        pMeasuredObj->setPreMeasuredObjPtr(pTailObj);
        //3.3如果列表尾部不为nullptr,则将列表尾部成员变量(指向下一个检测对象的指针)指向列表尾部
        if(nullptr != pTailObj)
        {
            pTailObj->setNextMeasuredObjPtr(pMeasuredObj);
        }
        else
        {
            this->m_pHeadObj = pMeasuredObj;
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step4
        //将列表的长度 +1
        this->m_size++;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        }
    catch(const exception &ex)
    {
        THROW_EXCEPTION(ex.what());
    }
}

void MeasuredObjList::pullHead()
{
    try
    {
        //判断列表的长度,如果列表长度大于0,则执行删除检测对象操作
        //如果列表长度为0,则抛出异常
        if(this->m_size > 0)
        {
            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step1
            //定义一个MeasureObj对象,记录列表检测对象的地址
            MeasuredObj *pTmpObj = nullptr;
            //将列表中第二个检测对象的地址赋值给临时对象
            pTmpObj = this->m_pHeadObj->pNextMeasuredObj();
            //将头指针中的成员变量(指向下一个对象的指针)设置为nullptr
            this->m_pHeadObj->setNextMeasuredObjPtr(nullptr);
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step2
            //如果列表中下一个检测对象的地址不是nullptr,即不是最后一个检测对象
            //将列表中第二个检测对象中成员变量(指向上一个检测对象的地址)置为nullptr
            if(pTmpObj != nullptr)
            {
                pTmpObj->setPreMeasuredObjPtr(nullptr);
            }
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step3
            //重新设置表头的地址
            this->m_pHeadObj = pTmpObj;
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step4
            //将列表中的长度减一
            this->m_size--;
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        }
        else
        {
            THROW_EXCEPTION("列表长度为0,无法删除检测对象!");
        }
    }
    catch(const exception &ex)
    {
        THROW_EXCEPTION(ex.what());
    }
}

void MeasuredObjList::pullTail()
{
    //判断列表的长度,如果列表长度大于0,则执行删除最后一个检测象操作
    //如果列表长度为0,则抛出异常
    if(this->m_size > 0)
    {
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step1
        //找出列表中最后一个检测对象
        MeasuredObj * pTailObj = this->m_pHeadObj;
        MeasuredObj * pTmpObj = this->m_pHeadObj->pNextMeasuredObj();

        while (pTmpObj != nullptr)
        {
            pTailObj = pTmpObj;
            pTmpObj = pTmpObj->pNextMeasuredObj();
        }
        //记录下列表中倒数第二个检测对象
        pTmpObj = pTailObj->pPreMeasuredObj();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step2
        //将列表的最后一个检测对象中成员变量(指向上一个检测对象的指针)置为nullptr
        //将列中指向尾部对象的指针置位nullptr
        pTailObj->setPreMeasuredObjPtr(nullptr);
        pTailObj = nullptr;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step3
        //如果列表尾部上一个检测对象的地址不是nullptr,即不是第一个检测对象
        //将列表中指向上一个检测对象的地址置为nullptr
        //否则将列表的表头指针设置为nullpte
        if(pTmpObj != nullptr)
        {
            //将倒数第二个检测对象中的成员变量(指向下一个检测对象的指针),将其设置为nullptr
            pTmpObj->setNextMeasuredObjPtr(nullptr);
        }
        else
        {
            this->m_pHeadObj = nullptr;
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step4
        //将列表的长度减一
        this->m_size--;
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    }
    else
    {
        THROW_EXCEPTION("列表长度为0,无法删除检测对象!");
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//显示列表中所有检测对象的元件名称,X,Y轴坐标,角度,及长和宽
void MeasuredObjList::print()
{
    MeasuredObj *pTmpObj = this->m_pHeadObj;

    while (pTmpObj != nullptr)
    {
        cout<<"元件名称:"<<pTmpObj->name()<<"\t"
            <<"X:"<< pTmpObj->rectangle().xPos()<<"\t"
            <<"Y:"<<pTmpObj->rectangle().yPos()<<"\t"
            <<"Width:"<<pTmpObj->rectangle().width()<<"\t"
            <<"Height"<<pTmpObj->rectangle().height()<<endl;
        pTmpObj = pTmpObj->pNextMeasuredObj();
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



