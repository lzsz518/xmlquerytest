#include <QMessageBox>
#include <QSysInfo>

#include "QXmlPQMainWindow.h"
//#include "QFileStringModel.h"

class QFileStringModel;

QXmlPQMainWindow::QXmlPQMainWindow(QWidget *parent):
            QMainWindow(parent)
{
    CreateWindowWidget();
    CreateActions();
    CreateMenuBar();
    CreateToolBar();
    CreateStatusBar();
    ConnectAction();
    this->resize(800,600);
    slotNew();
}


void QXmlPQMainWindow::SetModel(QAbstractTableModel *Model)
{
    tableviewFileList->setModel(Model);
}


void QXmlPQMainWindow::CreateWindowWidget()
{
    CreateCenterWidtet(); //the central widget is a QSplitter
    CreateDockWidget();

    //following function create splitter widget from left to right
//    CreateFileListWidget();
//    CreateXmlDetailWidget();
//    CreateIOWidget();
}

void QXmlPQMainWindow::CreateDockWidget()
{
    dockFileList = new QDockWidget(tr("File List"),this);
    dockXmlNodeTree = new QDockWidget(tr("XML Node"),this);


    tableviewFileList = new QTableView(this);
    treewidgetXmlNodes = new QTreeWidget(this);
    dockFileList->setWidget(tableviewFileList);
    dockFileList->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockXmlNodeTree->setWidget(treewidgetXmlNodes);
    dockXmlNodeTree->setAllowedAreas(Qt::LeftDockWidgetArea);

    addDockWidget(Qt::LeftDockWidgetArea,dockFileList,Qt::Vertical);
    addDockWidget(Qt::LeftDockWidgetArea,dockXmlNodeTree,Qt::Vertical);
}


void QXmlPQMainWindow::CreateCenterWidtet()
{

    XQueryWidgetTab = new QXQueryWidgetTab(this);
    XQueryWidgetTab->setTabsClosable(true);
    XQueryWidgetTab->setMovable(true);
    this->setCentralWidget(XQueryWidgetTab);
}


void QXmlPQMainWindow::CreateActions()
{
    actionNew = new QAction(QIcon(":/images/new.png"),tr("&New"),this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setStatusTip(tr("New"));

    actionOpenXml = new QAction(QIcon(":/images/open.png"),tr("&OpenXml"),this);
    actionOpenXml->setShortcut(QKeySequence::Open);
    actionOpenXml->setStatusTip(tr("Open Xml Files"));

/*
    actionOpenXQuery = new QAction(QIcon(":/images/open.png"),tr("&OpenXQuery"),this);
    actionOpenXQuery->setStatusTip(tr("Open XQuery Files"));

    actionSave = new QAction(QIcon(":/images/save.png"),tr("&Save"),this);
    actionSave->setShortcut(QKeySequence::Save);
    actionSave->setStatusTip(tr("Save XQuery Files"));

    actionSaveAs = new QAction(tr("Save as..."),this);
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    actionSaveAs->setStatusTip(tr("Save as XQuery Files"));
*/
    actionExit = new QAction(QIcon(":/images/exit.png"),tr("E&xit"),this);
    actionExit->setShortcut(QKeySequence::Quit);
    actionExit->setStatusTip(tr("Exit"));

    actionCut = new QAction(QIcon(":/images/cut.png"),tr("Cu&t"),this);
    actionCut->setShortcut(QKeySequence::Cut);

    actionCopy = new QAction(QIcon(":/images/copy.png"),tr("&Copy"),this);
    actionCopy->setShortcut(QKeySequence::Copy);

    actionPaste = new QAction(QIcon(":/images/paste.png"),tr("&Paste"),this);
    actionPaste->setShortcut(QKeySequence::Paste);

    actionDelete = new QAction(tr("&Delete"),this);
    actionSelectAll = new QAction(tr("Select &All"),this);
    actionFind = new QAction(tr("&Find"),this);

    actionToolBar = new QAction(tr("&Toolbar"),this);
    actionToolBar->setCheckable(true);
    actionToolBar->setChecked(true);
    actionStateBar = new QAction(tr("State&bar"),this);
    actionStateBar->setCheckable(true);
    actionStateBar->setChecked(true);


    actionExecXQuery = new QAction(QIcon(":/images/exec.png"),tr("&ExecQuery"),this);
    actionExecXQuery->setShortcut(tr("Ctrl+R"));

    actionClearXQuery = new QAction(QIcon(":/images/clear.png"),tr("&ClearQuery"),this);
    actionClearXQuery->setShortcut(tr("Ctrl+L"));

    actionOptions = new QAction(tr("&Options"),this);

   actionHelp = new QAction(tr("&Help"),this);
   actionAbout = new QAction(tr("&About"),this);
}

void QXmlPQMainWindow::CreateMenuBar()
{
	CreateFileMenu();
	CreateEditMenu();
	CreateViewMenu();
	CreateToolsMenu();
	CreateHelpMenu();
}

void QXmlPQMainWindow::CreateToolBar()
{
    toolbarFile = addToolBar(tr("File"));
    toolbarEdit = addToolBar(tr("Edit"));
    //toolbarView = addToolBar(tr("View`"));
    toolbarTools = addToolBar(tr("Tools"));

    toolbarFile->addAction(actionNew);
    toolbarFile->addAction(actionOpenXml);
//    toolbarFile->addAction(actionOpenXQuery);
//    toolbarFile->addAction(actionSave);

    toolbarEdit->addAction(actionCopy);
    toolbarEdit->addAction(actionCut);
    toolbarEdit->addAction(actionPaste);

    toolbarTools->addAction(actionExecXQuery);
    toolbarTools->addAction(actionClearXQuery);
}

void QXmlPQMainWindow::CreateStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void QXmlPQMainWindow::CreateFileMenu()
{
	menuFile = menuBar()->addMenu(tr("&File"));
	menuFile->addAction(actionNew);
    menuFile->addAction(actionOpenXml);
//    menuFile->addAction(actionOpenXQuery);
//	menuFile->addAction(actionSave);
//	menuFile->addAction(actionSaveAs);
	menuFile->addSeparator();
	menuFile->addAction(actionExit);
}


void QXmlPQMainWindow::CreateEditMenu()
{
	menuEdit = menuBar()->addMenu(tr("&Edit"));
	menuEdit->addAction(actionCut);
	menuEdit->addAction(actionCopy);
	menuEdit->addAction(actionPaste);
	menuEdit->addAction(actionDelete);
	menuEdit->addAction(actionSelectAll);
	menuEdit->addAction(actionFind);
}

void QXmlPQMainWindow::CreateViewMenu()
{
	menuView = menuBar()->addMenu(tr("&View"));
	menuView->addAction(actionToolBar);
	menuView->addAction(actionStateBar);
}

void QXmlPQMainWindow::CreateToolsMenu()
{
    menuTools = menuBar()->addMenu(tr("&Tools"));
    menuTools->addAction(actionExecXQuery);
    menuTools->addAction(actionClearXQuery);
    menuTools->addSeparator();
	menuTools->addAction(actionOptions);
}

void QXmlPQMainWindow::CreateHelpMenu()
{
    menuHelp = menuBar()->addMenu(tr("&Help"));
    menuHelp->addAction(actionHelp);
    menuHelp->addAction(actionAbout);
}

void QXmlPQMainWindow::slotNew()
{
    QXQueryWidget *XQueryWidget = new QXQueryWidget(this);
    XQueryWidgetTab->insertTab(XQueryWidgetTab->count(),XQueryWidget,tr("XQuery"));
//    XQueryWidgetTab->addTab(XQueryWidget,tr("XQuery"));

}


void QXmlPQMainWindow::slotOpenXQuery()
{

}

void QXmlPQMainWindow::slotSave()
{
}

void QXmlPQMainWindow::slotExecXQuery()
{
    ExecXQuery();
}

void QXmlPQMainWindow::slotClearXQuery()
{
    XQueryWidgetTab->ClearCurrentWidget();
}

void QXmlPQMainWindow::slotAbout()
{
    QAboutDialog d;
    d.exec();
}

void QXmlPQMainWindow::slotHelp()
{
    QHelpDialog d;
    d.exec();
}

void QXmlPQMainWindow::slotToolbar(bool ischecked)
{
    if(ischecked)
    {
        toolbarFile->show();
        toolbarEdit->show();
        toolbarTools->show();
    }
    else
    {
        toolbarFile->hide();
        toolbarEdit->hide();
        toolbarTools->hide();
    }
}

void QXmlPQMainWindow::slotStatebar(bool ischecked)
{
    if(ischecked)
        statusBar()->show();
    else
        statusBar()->hide();
}

void QXmlPQMainWindow::ConnectAction()
{
/*
        //connect(actionOpenXml,SIGNAL(triggered()),this,SLOT(slotOpenXml()));
        //connect(actionOpenXml,SIGNAL(triggered()),this,SLOT(OpenFile()));
        connect(actionOpenXQuery,SIGNAL(triggered()),this,SLOT(slotOpenXQuery()));
        connect(actionNew,SIGNAL(triggered()),this,SLOT(New()));
        connect(actionSave,SIGNAL(triggered()),this,SLOT(slotSave()));





        connect(actionToolBar,SIGNAL(triggered(bool)),this,SLOT(slotToolbar(bool)));
        connect(actionStateBar,SIGNAL(triggered(bool)),this,SLOT(slotStatebar(bool)));
*/

    connect(actionHelp,SIGNAL(triggered()),this,SLOT(slotHelp()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(slotAbout()));

    connect(tableviewFileList,SIGNAL(clicked(QModelIndex)),this,SLOT(FileStringSelected(QModelIndex)));
    connect(actionNew,SIGNAL(triggered()),this,SLOT(slotNew()));

    connect(actionExecXQuery,SIGNAL(triggered()),this,SLOT(slotExecXQuery()));
    connect(actionClearXQuery,SIGNAL(triggered()),this,SLOT(slotClearXQuery()));
}

void QXmlPQMainWindow::ExecXQuery()
{
    if(NULL!=XQueryWidgetTab)
    {
        QByteArray outArray;
        QBuffer buffer(&outArray);
        buffer.open(QIODevice::ReadWrite);

        QXmlQuery query;
        query.setQuery(XQueryWidgetTab->GetCurrentXQuery());
        if (!query.isValid())
            return;

        QXmlFormatter formatter(query, &buffer);
        if (!query.evaluateTo(&formatter))
            return;

        XQueryWidgetTab->SetCurrentResult(QString::fromUtf8(outArray.constData()));

        buffer.close();
    }
}



void QXmlPQMainWindow::FileStringSelected(const QModelIndex & index)
{
//    QFileStringModel *model = (QFileStringModel*)index.model();
    treewidgetXmlNodes->removeItemWidget(treewidgetXmlNodes->takeTopLevelItem(0),0);
    treewidgetXmlNodes->addTopLevelItem(((QFileStringModel*)index.model())->GetXmlNodeTreeItems(index.row()));
//    treewidgetXmlNodes->addTopLevelItem(model->GetXmlNodeTreeItems(index.row()));
}

void QXmlPQMainWindow::OpenXmlFile(QString &FileString)
{
}

void QXmlPQMainWindow::SaveXQueryFile(QString &FileString)
{
}

/*
QXmlPQMainWindow::~QXmlPQMainWindow()
{

}
*/
