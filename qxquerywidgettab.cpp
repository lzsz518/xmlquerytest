#include "qxquerywidgettab.h"

QXQueryWidgetTab::QXQueryWidgetTab(QWidget *parent) :
    QTabWidget(parent)
{
    this->connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(slotCloseTab(int)));
}

void QXQueryWidgetTab::slotCloseTab(int Index)
{
    this->removeTab(Index);
}

QString QXQueryWidgetTab::GetCurrentXQuery()
{
    QXQueryWidget *XQueryWidget;
    XQueryWidget = (QXQueryWidget*)currentWidget();
    return XQueryWidget->GetXQuery();
}

void QXQueryWidgetTab::SetCurrentResult(const QString &str)
{
    QXQueryWidget *XQueryWidget;
    XQueryWidget = (QXQueryWidget*)currentWidget();
   XQueryWidget->SetResult(str);
}

void QXQueryWidgetTab::ClearCurrentWidget()
{
    QXQueryWidget *XQueryWidget;
    XQueryWidget = (QXQueryWidget*)currentWidget();
   XQueryWidget->ClearText();
}
