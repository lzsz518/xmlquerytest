#include <QApplication>
#include <QTextcodec>
#include "QXmlPQMainWindow.h"
#include "QFileStringModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QXmlPQMainWindow w;
    QFileStringModel *fsm = new QFileStringModel;

    QTextCodec::setCodecForTr( QTextCodec::codecForName("System"));
    QObject::connect(w.actionOpenXml,SIGNAL(triggered()),fsm,SLOT(OpenFile()));
    w.SetModel(fsm);
    w.show();

    return a.exec();
}
