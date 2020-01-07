#ifndef QFILESTRINGMODEL_H
#define QFILESTRINGMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QVector>
#include <QPair>
#include <QMapIterator>
#include <Qt>
#include <QFont>
#include <QStringList>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QtXml/QDomNode>
#include <QtXml/QDomNode>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class QFileStringModel :public QAbstractTableModel
{
    Q_OBJECT
public:
    QFileStringModel(QObject *parent = 0);

    void setFileString(QVector< QPair<QString, QString> > &vector);
    void setCurrencyMap();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void AppendFileString(QString Name, QString Path);
    void RemoveAll();

    QTreeWidgetItem* GetXmlNodeTreeItems(int index);

public slots:
    void OpenFile();

private:
    QVector< QPair<QString,QString> > vectorFilePaths;
    QVector<QTreeWidgetItem*> vectorXmlNodeItems;
    bool GetFileNameAndPath(const QString &FileString,QString &Name,QString &Path);
    QTreeWidgetItem* XMLFileTrav(QString &FileName);
    void DomNodeTrav(QDomNode &DomElement, QTreeWidgetItem *ParentItem);

};
#endif // QFILESTRINGMODEL_H
