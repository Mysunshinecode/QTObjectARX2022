#include "dialog.h"
#include "ui_dialog.h"
#include<tchar.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    CreateLine();
}
void Dialog::CreateLine()
{
    ads_point ptStart;
    ads_point ptEnd;
    AcApDocument* pDoc = acDocManager->mdiActiveDocument();
    acDocManager->lockDocument(pDoc);

    AcDbBlockTable* pBlockTable;//声明指向块表的指针
    if (acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead) == Acad::eOk)
    {
        AcDbBlockTableRecord* pBlockTableRecord;//声明一个块表记录区的指针
        if (pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite) == Acad::eOk)
            //将空间模型区域的记录地址赋给上声明的变量 模式为写
        {

            if ((ads_getpoint(NULL,_T("\n请选择起点："), ptStart)) == RTNORM)
            {

                if (ads_getpoint(NULL,_T("\n请选择终点：") , ptEnd) == RTNORM)
                {
                    AcDbLine* pLine = new AcDbLine(asPnt3d(ptStart), asPnt3d(ptEnd));//这个类代表了CAD里面的线实体，起始点终结点
                    AcDbObjectId lineld;//声明ID
                    pBlockTableRecord->appendAcDbEntity(lineld, pLine);//将ID与实体传入
                    //关闭所有这个很关键 用到了什么就要吧所有的都关闭不然会出现问题。
                    pLine->close();
                    pBlockTableRecord->close();
                }

            }
        }
        pBlockTable->close();
    }//获取块表织针
    acDocManager->unlockDocument(pDoc);//解锁

}


