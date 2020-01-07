#ifndef QXQUERYWIDGETTAB_H
#define QXQUERYWIDGETTAB_H

#include <QTabWidget>

#include "QXQueryWidget.h"

class QXQueryWidgetTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit QXQueryWidgetTab(QWidget *parent = 0);

public:
    QString GetCurrentXQuery();
    void SetCurrentResult(const QString &str);

    void ClearCurrentWidget();

signals:

public slots:
    void slotCloseTab(int Index);
};

#endif // QXQUERYWIDGETTAB_H
