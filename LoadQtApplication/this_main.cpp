#pragma warning( push)
#pragma warning (disable: 4189 4100 )
#include <Windows.h>
#include <arxHeaders.h>
#include "Dialog.h"
#pragma warning( pop)
#include<QtWidgets/QApplication>
#include <string_view>

using namespace std::string_literals;

#include <QtWidgets>
#include <QtQml>
#include<QMessageBox>


inline void HellowWorldARX() {
//    QJSEngine varE;
//    varE.evaluate( QString("1+1") );
    {
        QMessageBox varBox ;
        varBox.setText(("Hellow World!"));
        QIcon varImage{ QString(":/png/this.png") };

//        varBox.setIconPixmap(QPixmap(QString(":/png/this.png")));

        varBox.exec() ;
    }
    auto varDataTime = QDateTime::currentDateTime().toString().toStdWString();
    varDataTime = LR"(Hellow World!)" + varDataTime ;
    acutPrintf(varDataTime.c_str());
}

namespace {
    namespace _cpp_private {
const std::string qtApplicationPath ="123";/*!!!*/
//#if _OBJECT_ARX_VERSION_X64_ == 2018
//            u8R"(D:\Program Files\AutoCAD 2018\acad.exe)"s;
//#else
//            u8R"(D:\Program Files\AutoCAD 2022\AutoCAD 2022\acad.exe)";
//#endif
		inline int & getArgc() {
			static int ans;
			ans = 1;
			return ans;
		}
		inline char** getArgv() {
            static char acadpath[] =u8R"(D:\Program Files\AutoCAD 2022\AutoCAD 2022\acad.exe)";
			static char *argv[] = { nullptr };
			std::copy(qtApplicationPath.begin(), qtApplicationPath.end(),
				static_cast<char*>(acadpath));
			argv[0] = static_cast<char *>(acadpath);
			return argv;
		}
	}
}/*namespace*/

inline void ShowQtWindow() {

        auto varQtApplication =
            new QApplication(_cpp_private::getArgc(), _cpp_private::getArgv());
        (void)varQtApplication;
        Dialog w;
        w.show();
        varQtApplication->exec();
            //	acutPrintf(LR"(Hellow Word!
            //)");
    }
extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt) {
	switch (msg) {
	case AcRx::kInitAppMsg: {
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		/*****************************************/
		{
			if (qApp == nullptr) {
				/*create the qt applicaton and never destory it*/
				auto varQtApplication =
                    new QApplication(_cpp_private::getArgc(), _cpp_private::getArgv());
				(void)varQtApplication;
			}
			{
				/*force to load images plugins*/
				QImage varImage{ QString(":/png/this.png") };
				varImage.width();
				varImage.height();
            }

		}
		/*****************************************/
		acedRegCmds->addCommand(
            L"SSTD_GLOBAL_CMD_GROUP",
            L"HellowWorld",
            L"HellowWorld",
			ACRX_CMD_MODAL,
            &HellowWorldARX);
        acedRegCmds->addCommand(
            L"SSTD_GLOBAL_CMD_GROUP",
            L"ShowQtWindow",
            L"ShowQtWindow",
            ACRX_CMD_MODAL,
            &ShowQtWindow);
	}break;
	case AcRx::kUnloadAppMsg: {}break;
	default:break;
	}
	return AcRx::kRetOK;
}


/********************************/

