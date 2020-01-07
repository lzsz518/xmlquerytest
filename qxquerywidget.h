#ifndef QXQUERYWIDGET_H
#define QXQUERYWIDGET_H

#include <QWidget>
#include <QSplitter>
#include <QPlainTextEdit>
#include <QGroupBox>
#include <QHBoxLayout>

class QXQueryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QXQueryWidget(QWidget *parent = 0);

public:
    QString GetXQuery();
    void SetResult(const QString &str);

    void ClearText();
signals:

public slots:

private:
    QSplitter *Splitter;
    QPlainTextEdit *editXQuery;
    QPlainTextEdit *editResult;

    QGroupBox *groupboxXQuery;
    QGroupBox *groupboxResult;
    QHBoxLayout *layoutXQuery;
    QHBoxLayout *layoutResult;

    QHBoxLayout *layoutMain;

    void CreateUI();
};

#endif // QXQUERYWIDGET_H
