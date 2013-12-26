#include "gui/MainWindow.h"
#include <iostream>
#include "qtsingleapplication/src/QtSingleApplication"
#include <QTranslator>
#include <QTextCodec>
#include <QDebug>

#ifdef Q_WS_MAC
#include <objc/objc.h>
#include <objc/message.h>
#endif

#ifdef Q_WS_MAC
    bool dockClickHandler(id self,SEL _cmd,...);
#endif

class GApplication : public QtSingleApplication
{
public:
    MainWindow *prWin;
    GApplication(int argc, char **argv):
        QtSingleApplication(argc, argv)
    {

        addLibraryPath(applicationDirPath());

#ifdef Q_WS_MAC

    objc_object* cls = objc_getClass("NSApplication");
    SEL sharedApplication = sel_registerName("sharedApplication");
    objc_object* appInst = objc_msgSend(cls,sharedApplication);

    if(appInst != NULL)
    {
        objc_object* delegate = objc_msgSend(appInst, sel_registerName("delegate"));
        objc_object* delClass = objc_msgSend(delegate,  sel_registerName("class"));
        const char* tst = class_getName(delClass->isa);
        bool test = class_addMethod((objc_class*)delClass, sel_registerName("applicationShouldHandleReopen:hasVisibleWindows:"), (IMP)dockClickHandler,"B@:");

        if (!test)
        {
            // failed to register handler...
        }
    }

#endif
    }

    void onClickOnDock()
    {
        prWin->wakeUpWindow();
    }
};

#ifdef Q_WS_MAC
    bool dockClickHandler(id self,SEL _cmd,...)
    {
        Q_UNUSED(self)
        Q_UNUSED(_cmd)
       ((MApplication*)qApp)->onClickOnDock();
         return true;
    }
#endif

int main(int argc, char **argv)
{
    GApplication instance(argc, argv);
    if (instance.sendMessage("Wake up!"))
        return 0;
    // TODO
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

/*
    QTranslator translator;
    translator.load(MSettings::i()->languageFile());
    instance.installTranslator(&translator);
*/
    // create project window
    MainWindow w;
    instance.prWin = &w;
    w.show();
#ifdef Q_OS_WIN
    QStringList args = instance.arguments();
    QString arg;
    if(args.count() > 1)
        arg = args[1];
    if(arg == "-d")
        w.hide();
    else
        w.show();
#endif

    instance.setActivationWindow(&w);

    QObject::connect(&instance, SIGNAL(messageReceived(const QString&)),
             &w, SLOT(show()));

    return instance.exec();
}
