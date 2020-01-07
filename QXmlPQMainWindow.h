#ifndef QXMLPQMAINWINDOW_H
#define QXMLPQMAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolbar>
#include <QStatusBar>
#include <QTableWidget>
#include <QDockWidget>
#include <QtXmlPatterns/QtXmlPatterns>
#include <QtXmlPatterns/QXmlQuery>
#include <QTreeWidget>

#include "xmlsyntaxhighlighter.h"
#include "QFileStringModel.h"
#include "QHelpDialog.h"
#include "QAboutDialog.h"
#include "qxquerywidget.h"
#include "qxquerywidgettab.h"

class QXmlPQMainWindow : public QMainWindow
{
	Q_OBJECT
public:
//	QXmlPQMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    explicit QXmlPQMainWindow(QWidget *parent = 0);
//	virtual ~QXmlPQMainWindow();

    void SetModel(QAbstractTableModel *Model);
public slots:
//    void slotOpenXml();
    void slotOpenXQuery();
    void slotNew();
    void slotSave();
	void slotExecXQuery();
	void slotClearXQuery();
	void FileStringSelected(const QModelIndex & index);
	void slotAbout();
	void slotHelp();
    void slotToolbar(bool ischecked);
    void slotStatebar(bool ischecked);

public:
//FileMenu
    QAction *actionNew;
    QAction *actionOpenXml;
//    QAction *actionOpenXQuery;
//    QAction *actionSave;
//    QAction *actionSaveAs;
    QAction *actionExit;

//EditMenu
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelectAll;
    QAction *actionFind;

//ViewMenu
    QAction *actionToolBar;
    QAction *actionStateBar;

//ToolsMenu
    QAction *actionExecXQuery;
    QAction *actionClearXQuery;
    QAction *actionOptions;

//HelpMenu
    QAction *actionHelp;
    QAction *actionAbout;

private:
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuHelp;

    QToolBar *toolbarFile;
    QToolBar *toolbarEdit;
    QToolBar *toolbarView;
    QToolBar *toolbarTools;


//window widget

//    QGroupBox *groupboxFileList;
    QTableView *tableviewFileList;
    QTreeWidget *treewidgetXmlNodes;

    QDockWidget *dockFileList;
    QDockWidget *dockXmlNodeTree;
    QXQueryWidgetTab *XQueryWidgetTab;

//filepathmodel
    QFileStringModel FilePathModel;
    QString stringXQueryFileName; //Opened XQuery File Name

//Syntax high lighter

    XmlSyntaxHighlighter synataxHLInput;
    XmlSyntaxHighlighter synataxHLOutput;

private:
// UI function
    void CreateWindowWidget();
    void CreateDockWidget();

    void CreateCenterWidtet();

    void CreateActions();
    void CreateMenuBar();
    void CreateToolBar();
    void CreateStatusBar();

    void CreateFileMenu();
    void CreateEditMenu();
    void CreateViewMenu();
    void CreateToolsMenu();
    void CreateHelpMenu();
    void ConnectAction();

    void ExecXQuery();

private:
    void OpenXmlFile(QString &FileString);
    void SaveXQueryFile(QString &FileString);
};

#endif

