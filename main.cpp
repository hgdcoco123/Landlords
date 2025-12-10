#include "gamepanel.h"
#include "loading.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include"cards.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "Landlords_" + QLocale(locale).name();
    //     if (translator.load(":/i18n/" + baseName)) {
    //         a.installTranslator(&translator);
    //         break;
    //     }
    // }
    // 注册Cards类型，支持跨线程信号槽传递
    qRegisterMetaType<Cards>("Cards");
    //qRegisterMetaType<Cards&>("Cards&"); // 可选：注册引用类型
    a.setWindowIcon(QIcon(":/images/logo.ico"));  // :/ 表示从 qrc 根目录读取
    Loading w;
    //GamePanel w;
    w.show();
    return a.exec();
}
