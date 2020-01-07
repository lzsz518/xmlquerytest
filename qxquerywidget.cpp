#include "qxquerywidget.h"

QXQueryWidget::QXQueryWidget(QWidget *parent) :
    QWidget(parent)
{
    CreateUI();
}

void QXQueryWidget::CreateUI()
{
    layoutMain = new QHBoxLayout;

    Splitter = new QSplitter(Qt::Vertical);
    editXQuery = new QPlainTextEdit(this);
    editResult = new QPlainTextEdit(this);
    groupboxXQuery = new QGroupBox(this);
    groupboxXQuery->setTitle(tr("XPath/XQuery"));
    groupboxResult = new QGroupBox(this);
    groupboxResult->setTitle(tr("Result"));
    layoutXQuery = new QHBoxLayout;
    layoutResult = new QHBoxLayout;

    layoutXQuery->addWidget(editXQuery);
    layoutResult->addWidget(editResult);
    groupboxXQuery->setLayout(layoutXQuery);
    groupboxResult->setLayout(layoutResult);

    Splitter->addWidget(groupboxXQuery);
    Splitter->addWidget(groupboxResult);

    layoutMain->addWidget(Splitter);
    setLayout(layoutMain);
}

QString QXQueryWidget::GetXQuery()
{
    return  editXQuery->toPlainText();
}

void QXQueryWidget::SetResult(const QString &str)
{
    editResult->setPlainText(str);
}

void QXQueryWidget::ClearText()
{
    editXQuery->clear();
    editResult->clear();
}
